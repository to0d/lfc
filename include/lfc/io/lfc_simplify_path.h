#ifndef __LFC_SIMPLIFY_PATH__
#define __LFC_SIMPLIFY_PATH__

#include <stdio.h>

int lfc_simplify_path(char* path) 
{
    char* stack[1024];
    char c, *p1, *p2;
    int n;
    
    if( path == NULL || path[0] != '/' )
        return -1;
    
     p1 = path;
INIT:p2 = path;
     n  = 0;
STR:while(( c = *p1++ ) != '\0' )
    {   switch(c)
        { case '/':
NEXT:             stack[n++] = p2;
                  *(p2++) = '/';
SKIP:             for( ; *p1 == '/'; ++p1 );
                      break;
          case '.':
                  // a.b/ or a./
                  if( p2 > path && *(p2-1) != '/' )
                  {
UNTIL:                while((*(p2++) = c))
                      {   switch((c=*p1++))
                          {   case '/' :  goto NEXT;
                              case '\0':  goto END;
                          }
                      }
                  }
                  switch(*p1)
                  {   case '/' :  ++p1; goto SKIP;    // ignore "./"
                      case '\0':  goto STR;
                      case '.' :                      // pop if "../"
                          if( (*(p1+1)=='/') || (*(p1+1) == '\0') )  
                          {   p1++;
                              if( --n <= 0 ) // assume the path start with "/"
                                  goto INIT;
                              p2 = stack[--n];
                              goto NEXT;
                          }
                  }
          default: goto UNTIL; 
        }
    }
END:if( p2 == path )
        *(p2++) = '/';
    else if( *(p2-1) == '/' && p2 > (path+1) )
        --p2;
    *(p2) = '\0';
    
    return p2-path;
}

      
#endif //__LFC_SIMPLIFY_PATH__