#include <stdio.h>
#define N 100

char * copy_str( char *dest , char *src)
{
     char *temp = dest ;
     while(*src != '\0')
     {
        *dest = *src;
        dest++;
        src++;
     }
     *dest = '\0';
    return temp;
}

int main(int argc, const char *argv[])
{
    char src[N] = "abcdefg";
    char dest[N] = {0};
  //  char *ptr1 = src;
    char *ptr2 = dest;
    ptr2  =  copy_str(dest ,src);
    printf("%s\n" ,dest);
    return 0;
}

