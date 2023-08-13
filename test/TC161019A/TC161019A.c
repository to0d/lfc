#include "stdio.h"
#include <lfc/lfc.h>

void _test(const char* s, char c, size_t len)
{
    const char* rst = lfc_memrchr(s, c, len);
    printf( "s=%s, c=%c, len=%d, rst=%s\n", s, c, len, rst);
}

int main( void )
{
    _test("xx.yy.z", '.', 6);
    _test("xx.yy.z", '.', 5);
    printf( "output: done.\n" );
    return 0;
}



