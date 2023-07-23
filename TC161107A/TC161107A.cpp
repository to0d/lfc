#include <limits.h>
#include <gtest/gtest.h>
#include <lfc/trace.h>
#include <lfc/string_helper.h>


TEST(Trace, lfc_dump_memory_hex)
{
    lfc_dump_memory_hex(NULL, 0); 
}

TEST(String, lfc_memrchr) 
{
    // EXPECT_STREQ(".z",(char*) lfc_memrchr("xx.yy.z", '.', 100));
    EXPECT_STREQ(".z",(char*) lfc_memrchr("xx.yy.z", '.', 7));
    EXPECT_STREQ(NULL,(char*) lfc_memrchr(NULL, '.', 7));
    EXPECT_STREQ(".z",(char*) lfc_memrchr("xx.yy.z", '.', 6));
    EXPECT_STREQ(".yy.z",(char*) lfc_memrchr("xx.yy.z", '.', 5));
    EXPECT_STREQ(".yy.z",(char*) lfc_memrchr("xx.yy.z", '.', 4));
    EXPECT_STREQ(".yy.z",(char*) lfc_memrchr("xx.yy.z", '.', 3));
    EXPECT_STREQ(NULL,(char*) lfc_memrchr("xx.yy.z", '.', 2));
    EXPECT_STREQ(NULL,(char*) lfc_memrchr("xx.yy.z", '.', 1));
    EXPECT_STREQ(NULL,(char*) lfc_memrchr("xx.yy.z", '.', 0));
    // EXPECT_STREQ(NULL,(char*) lfc_memrchr("xx.yy.z", '.', -1));
    
    printf( "output: done.\n" );
}

