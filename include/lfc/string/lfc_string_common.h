#ifndef __LFC_STRING_COMMON__
#define __LFC_STRING_COMMON__

#include <string.h>

/*********************************************************************/
/* scans the first n bytes of the memory area pointed to by s for the*/
/* character c. Does not like memchr, lfc_memrchr will try to find   */
/* the last location                                                 */
/*********************************************************************/
void *lfc_memrchr(const void *s, char c, size_t count)
{
#define MAX_CHECK_LENGTH 65535

    char*  pStart   = (char*) s;
    char*  pLoc     = NULL;
    char*  pFindLoc = NULL;
    size_t nFindLen = 0;
    
    if( s == NULL )
    {   return NULL;        
    }
    
    if( count > MAX_CHECK_LENGTH )
    {   count = MAX_CHECK_LENGTH;        
    }
    
    pLoc = (char*) memchr( pStart, c, count);
    if( pLoc != NULL )
    {
        pFindLoc = pLoc;
        nFindLen = pLoc - pStart + 1;       
        while( pFindLoc != NULL && nFindLen < count ) 
        {
            pFindLoc = (char*) memchr(pStart + nFindLen, c, count - nFindLen);
            if( pFindLoc != NULL )
            {   pLoc     = pFindLoc;
                nFindLen = pFindLoc - pStart + 1;
            }
        }       
    }
    return pLoc;
}
          
#endif //__LFC_STRING_COMMON__