#include "stdio.h"
#include <lfc/lfc.h>

int main( void )
{
    char test[10] = {"ABCDEFGH"};
    char other[90] = {"Others"};
    other[88] = 'a'; 
    
    lfc_dump_memory_hex((void*)test, 100);  
    
    printf( "output: done.\n" );
    return 0;
}



