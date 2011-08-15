#include <stdio.h>

int main(int argc, const char *argv[])
{
/* 第一种方法 按位与 my_int左移法*/
/*    unsigned int my_int  = 15;
    unsigned  int mask = (1 << 31);
   // int mid = 0;
    while(my_int > 0)
    {
        if((my_int & mask) > 0)
        {
           printf("1");
        }
        else
        {
            printf("0");
        }
        my_int = my_int << 1;
    }
    printf("\n");*/
/* 第二种方法  按为与  mask右移法*/

/*  unsigned int my_int = 15 ;
    unsigned int mask = (1 << 31);
    while(mask > 0)
    {
       if((my_int & mask) > 0)
       {
          printf("1");
       }
       else
       {
           printf("0");
       }
       mask = mask >> 1;
    }
    printf("\n");*/

/* 第三种方法*/
   
    unsigned int my_int = 15 ;
    unsigned int mask = (1 << 31);
    while(mask > 0)
    {
        printf("%c" ,((mask & my_int) > 0 ? '1':'0' ));
        mask = mask >> 1;
    }
    printf("\n");
    return 0;
}

