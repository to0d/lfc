#ifndef __LFC_PRINT_HELPER_C99__
#define __LFC_PRINT_HELPER_C99__

#include <stdio.h>

void print_int_list(int* list, int n )
{  
    int i;
    
    printf("list: size=%d, value=", n);
    for(i = 0; i < n; ++i)
    {   printf("%3d,", list[i]);
    }
    
    printf("\n");
}


void print_int_array1(int* array, int n1 )
{  
    int i;
    
    printf("array: size: %d\n", n1);
    for(i = 0; i < n1; ++i)
    {   printf("  R%02d:   %3d\n", i, array[i]);
    }
}

void print_int_array2(int* array, int n1, int n2 )
{  
    int i, j, v;
    
    printf("array: size: %d * %d\n", n1, n2);
    printf("         ");
    for(j = 0; j < n2; ++j)
    {   printf("C%02d   ",j);
    }
    printf("\n");
    
    for(i = 0; i < n1; ++i)
    {
        printf("  R%02d: ", i);
        for(j = 0; j < n2; ++j)
        {   printf("  %3d,", array[i*n2 + j]);
        }
        printf("\n");
    }
}


#endif //__LFC_PRINT_HELPER_C99__
