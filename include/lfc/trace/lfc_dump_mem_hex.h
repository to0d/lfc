#ifndef __LFC_DUMP_MEM_HEX__
#define __LFC_DUMP_MEM_HEX__

#include <ctype.h>

char __dump_hex_to_char(char v)
{
    if( v <= 9 )
    {   return '0' + v;
    }
    return 'A' + v - 10;
}

void lfc_dump_memory_hex(void *address, int datasize)
{	
#define ROW_A_LINE 16
#define MYMIN(a,b) (a)<(b)?(a):(b)

    if( address == NULL || datasize == 0)
    {   return;
    }

    unsigned char *pAddr = (unsigned char*)address;
    int index = 0;
    char Buffer[ROW_A_LINE*3 + 40]; 
    int BufPos;
    
    while (datasize)
    {
        int nCurSize = MYMIN(datasize, ROW_A_LINE);
        int i = 0;
        
        // Output Hex
        BufPos = sprintf(Buffer,"   %05X     ", index);
		while (i < ROW_A_LINE)
		{
            if( i < nCurSize )
            {   char c = pAddr[i++];
                Buffer[BufPos++ ] = __dump_hex_to_char((c&0xF0) >> 4 );
                Buffer[BufPos++ ] = __dump_hex_to_char((c&0x0F) );
            }
            else // append '.' if need
            {   Buffer[BufPos++] = '.';
                Buffer[BufPos++] = '.';
                ++i;
            }
            
			if( i % 4 == 0 )
            {   Buffer[BufPos++] = ' ';// fill a blank
            }
		}
        
        // Output Character 
		i = 0;	
        BufPos += sprintf(Buffer+BufPos, "  - ");
		while ( i < ROW_A_LINE )
		{   
            if( i < nCurSize )
            {   char c = pAddr[i];  
                Buffer[BufPos++]  = isgraph(c) ? c : '.';   
            }
            else 
            {   Buffer[BufPos++] = '.';
            }
            ++i;
		}
        
        Buffer[BufPos++] = '\n';
        Buffer[BufPos++] = '\0';
        
        printf("%s",Buffer);      
        datasize -= nCurSize;	 // print next line
        pAddr += nCurSize;
        index += ROW_A_LINE;
    }
}

#endif //__LFC_DUMP_MEM_HEX__