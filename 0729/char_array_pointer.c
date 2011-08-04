#include <stdio.h>
#define N 10

int main(int argc, const char *argv[])
{
    char array[N];
    char str[N] = "abcdefg";
    char *ptr = array ;
    int i = 0;
/*    for(i = 0 ; i < N ; i++,ptr++ )
    {
      *ptr = 'a' + i ;
      printf("%4c",*ptr);
    }
    printf("\n");*/
    for (i = 0; str[i] != '\0'; i++)
    {
        printf("%c",str[i]);
    }
    printf("\n");
/*    for(i = 0 ; i < N ; i++)
    {
       printf("%4c",array[i]);
    }
    printf("\n");*/
    return 0;
}

