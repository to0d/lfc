#ifndef __LFC_FILE__
#define __LFC_FILE__

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <dirent.h>  
#include <sys/stat.h> 
#include <lfc/io/lfc_simplify_path.h>

/*********************************************************************/
/* return:                                                           */
/*          0:  succ                                                 */
/*          1:  path already exist                                   */
/*          2:  target path is file which already exist              */
/*          3:  Invalid path name                                    */
/*          4:  Fail to call getcwd                                  */
/*          5:  Duplicate name with a file                           */
/*          6:  No authority to mkdir                                */
/*         99:  Internal error                                       */ 
/*         -1:  Fail to create path, unknown reason                  */
/*********************************************************************/
int lfc_mkdirs(const char* path)
{
#define MAX_PATH_LEN    5000
    char curPath[MAX_PATH_LEN] = {'\0'};
    char tgtPath[MAX_PATH_LEN] = {'\0'};
    int pos, len, tgtLen, i;
    char c;
    struct stat info;
    
    if( path == NULL || (len = strlen(path)) == 0 )
    {   return 3;        
    }

    // remove header blank
    for( pos = 0; pos < len && path[pos] == ' ' ; ++pos)
        ;
    
    // path is an empty string 
    if( pos == len )
    {   return 3;        
    }

    // get and save current path
    if( getcwd(curPath, sizeof(curPath)-1) == NULL )
    {   return 4;
    }

    // relative path
    if( path[pos] != '/' )
    {   strcat(tgtPath, curPath);
        strcat(tgtPath, "/");
    }
    strcat(tgtPath, path+pos);
    
    // Simplify Path
    if( (tgtLen=lfc_simplify_path(tgtPath)) <= 0 )
    {   return 99;        
    }  

    for( i = 1; i <= tgtLen; tgtPath[i++] = c )
    {
        if( (c=tgtPath[i]) == '/' || c == '\0')
        {              
            tgtPath[i] = '\0';
            if ( stat(tgtPath, &info ) == 0 )   // exist
            {
                if( S_ISDIR(info.st_mode) != 0) // Is Dir
                    continue;
                else 
                    return 5;   // Is File      
            }

            // Mode: drwx------
            if( mkdir( tgtPath, S_IRWXU ) != 0 ) 
                return -1;
        }        
    }
    
    return 0;
}

int lfc_is_dir(const char* path)
{
    struct stat info;
    
    if( path == NULL || strlen(path) == 0 )
        return -1;
    
    if ( stat(path, &info ) != 0 ) // no exist 
    {   return -2;
    }
    
    if( S_ISDIR(info.st_mode) == 0 )  // Is file
    {   return 1;        
    }
    
    return 0;
}

int lfc_rm_dir(char * path)  
{  
    char buffer[5000];
    DIR * dir = NULL;  
    struct dirent *ptr;  
    int rc; 

    if( path == NULL || strlen(path) == 0 )
        return -1;
    
    if( (dir = opendir(path)) == NULL )  
    {   return -2;  
    }
    
    while((ptr = readdir(dir)) != NULL)  
    {   
        if( strcmp(ptr->d_name, ".") == 0 
         || strcmp(ptr->d_name, "..") == 0 )  
            continue;   

        rc = snprintf( buffer
                     , sizeof(buffer)
                     , "%s/%s"
                     , path
                     , ptr->d_name);
        if( rc < 0 )
        {   return -3;
        }
        
        rc = lfc_is_dir(buffer);        
        if( rc == 0 )   // Is Dir
        {   if( lfc_rm_dir(buffer) != 0 )
            {   return -4;                
            }            
        }
        else if( rc == 1 ) // Is File
        {   if( remove(buffer) != 0 )
            {   return -5;
            }
        }
        else // Error
        {   return -6;            
        } 
    }
    
    closedir(dir); 

    if( rmdir(path) != 0 )
    {   return -7;
    }
    return 0;  
}  


      
#endif //__LFC_FILE__