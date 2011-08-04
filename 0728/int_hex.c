/* 把integer convert HEX */

#include <stdio.h>

int main(int argc, const char *argv[])
{
    unsigned int my_int = 0x112233aa;
    unsigned int mask = 0x0f;
    unsigned char str[17] = "0123456789abcdef";
    unsigned int move = 28 ;

    printf("0x");
    for(;my_int > 0 ; my_int <<= 4)
    {
       printf("%c",str[(my_int >> move) & mask]);
    }
    printf("\n");
    return 0;
}

