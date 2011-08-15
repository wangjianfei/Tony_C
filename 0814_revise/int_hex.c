#include <stdio.h>

int main(int argc, const char *argv[])
{
    unsigned int my_int = 0x1122aabb;
    unsigned int mask = (15 << 28);
    char str[18]="0123456789abcdef";
    unsigned int i = 0;
    while(my_int > 0)
    {
       i = (my_int & mask) >> 28;   //相与后还要还原回去 >>28  否则会出现段错误
       printf("%c" , str[i]);
       my_int = my_int << 4 ;
    }
    printf("\n");
    return 0;
}

