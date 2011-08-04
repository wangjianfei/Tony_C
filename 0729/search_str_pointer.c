#include <stdio.h>
#define N 20

void search_str(char *dest , char *src)
{
    int i = 0 ;
    int j = 0 ;
    char *temp = dest ;
    while(*src != '\0')
    {
       if(*src == *dest )
       {
           src++;
           dest++;
           j++;
           continue ;
       }
       else if(*dest =='\0')
       {
         printf("%4d",i);
         dest = temp ;
         i = i +j;
         j = 0 ;
         continue ;
       }
       else
       {
         src = src - j - 1;
         dest = temp;
         j = 0 ;
       }
       i++;
       src++;
    }
}

int main(int argc, const char *argv[])
{
    char strB[N] = "adeabcdeaaabcde";
    char strL[10] = "abcde";
    search_str(strL , strB);
    printf("\n");
    return 0;
}

