/* bansic exercise about pointer   sizeof is a key word . 它可以得到数字类型的
 * 大小， 即占空间的大小
 * */
#include <stdio.h>

int main(int argc, const char *argv[])
{
    int a = 6 ;
    int b = 0 ;
    int *ptr = &a ;
    int array[10];
    int *ptr1 = array ;
    int i = 0 ;

    for (;ptr1 < array + 10  ;i++ , ptr1++)
    {
        *ptr1 = i + 1 ;
        printf("%4d", array[i]);
    }
//    ptr1 = array ;
//    for(i = 0 ; i < 10 ; i++)
//    {
//      printf("%4d", array[i]);
//    }
    printf("\n");

    printf("a = %x\n" , a);
    printf("&a = %x\n" , &a);
    printf("ptr = %x\n" , ptr);
    printf("*ptr = %x\n" , *ptr);
    printf("&ptr = %x\n" , &ptr);
    printf("my_int = %d\n", sizeof(int) );    
    printf("my_char = %d\n", sizeof(char) );    
    printf("my_long_int = %d\n", sizeof(long int) );    
    printf("my_pointer = %d\n", sizeof(*ptr) );    
    return 0;
}

