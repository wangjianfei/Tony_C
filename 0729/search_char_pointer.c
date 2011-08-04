#include <stdio.h>

#define N 20

void  search_char(char *des)
{
    int i = 0 ;
    while(*des != '\0')
    {   
        if('a'== *des)
        {
           printf("%4d",i);
        }
        i++;
        des++;
    }
}

int main(int argc, const char *argv[])
{
    char str[N] = "abadaeafabacasa" ;
    search_char(str);
    printf("\n");
    printf("%d\n", argc);
    int j = 0 ;
    for( j = 0 ; j <argc ; j++)
    {
       printf("%s\n",argv[j]);
    }
    return 0;
}

