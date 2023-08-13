#include "stdio.h"
#include <lfc/lfc.h>

typedef struct {
    long int RecLen;
    long int SrcLen;
    char     Line[1];
} _MY_RECORD_T;


LFC_STATIC_STACK_DECLARE(RecordStackBuf, 1024*64)       /* 64K*/

int main( void )
{
    _MY_RECORD_T* pRecord = NULL;
    LFC_STATIC_STACK_MALLOC(RecordStackBuf, 1024); 
    pRecord =(_MY_RECORD_T*)LFC_STATIC_STACK_NAME(RecordStackBuf);
    assert(pRecord != NULL);

    printf("output: done.\n");
    
    return 0;
}



