#include <stdio.h>

#define N 20

int main(int argc, const char *argv[])
{
    char str1[N] = "abcdefg";
    char str2[N];
    char *ptr1 = str1 ;
    char *ptr2 = str2 ;
    while(*ptr1 != '\0')
    {
       *ptr2 = *ptr1 ;
       *ptr1++;
       *ptr2++;
    }
    *ptr2 = '\0';

    printf("%s\n",str2);

    return 0;
}

