#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <lfc/lfc.h>

void _Test(const char* input, char* expectOutput, int expectOutLen)
{
    char new_input[1024] = {0};
    char old_input[1024] = {0};
    int len;
    
    // Save input
    if( input != NULL )
    {
         strcat(new_input, input);  
         strcat(old_input, input);
    }
    
    len = lfc_simplify_path(new_input);
    if( len != expectOutLen )
    {
        printf("input : {%s}\n", old_input);
        printf("output length not match: expect %d, actual %d\n"
              ,expectOutLen, len);
        assert(0);
    }
    
    if( expectOutput != NULL && strcmp(new_input, expectOutput) != 0 )
    {
        printf("output not match: \n"); 
        printf("input : {%s}\n", old_input); 
        printf("output: {%s}\n", new_input);
        printf("expect: {%s}\n", expectOutput);
        assert(0);
    }
}

int main(int argc, char *argv[])
{
    _Test(NULL, NULL, -1);
    _Test("", NULL, -1);
    _Test("/abc/../", "/", 1);  
    _Test("/a/./b/../../c/", "/c", 2);  
    _Test("/////x", "/x", 2);  
    _Test("/x//////y", "/x/y", 4);
    _Test("/x/../y", "/y", 2);
    _Test("/x/../../", "/", 1); 
    _Test("/..", "/", 1); 
    _Test("/a/./b///../c/../././../d/..//../e/./f/.\
/g/././//.//h///././/..///", "/e/f/g", 6); 
    _Test("/x/../y\\ \\ ", "/y\\ \\ ", 6);
    
    printf("output: done.\n");
    return 0;
}

