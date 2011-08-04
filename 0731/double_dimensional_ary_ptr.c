#include <stdio.h>
#define M 10
#define N 8
int main(int argc, const char *argv[])
{
    int array[M][N] ;
    printf("array :          %p\n",array );
    printf("&array[0] :      %p\n",&array[0] );
    printf("array[0] :       %p\n",array[0] );
    printf("&array[0][0] :   %p\n",&array[0][0] );
    return 0;
}

