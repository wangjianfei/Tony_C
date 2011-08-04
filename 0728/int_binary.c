#include <stdio.h>

int main(int argc, const char *argv[])
{
    unsigned char my_int = 15 ;
    unsigned char mask = (1 << 7) ;

    for (;my_int > 0 ; my_int <<= 1)
    {
        printf("%c",((my_int & mask) > 0 )? '1':'0');
    }
    printf("\n");
    return 0;
}

