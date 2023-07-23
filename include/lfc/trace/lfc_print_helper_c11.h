#ifndef __LFC_PRINT_HELPER_C11__
#define __LFC_PRINT_HELPER_C11__

#include <iostream>
#include <vector>
#include <array>

template<typename T, size_t size> 
void print_content(const std::array<T, size>& arr)
{    
    std::cout << "---- array content ---------------\n";
    std::cout << "size: "<< size << std::endl;    
    for(int i = 0; i < size; ++i)
    {
        std::cout << " "<< i << ": [" << arr[i] << "]" << std::endl; 
    }
    
    std::cout << std::endl;
}

#endif //__LFC_PRINT_HELPER_C11__
