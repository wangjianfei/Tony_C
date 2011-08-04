#include <stdio.h>
#include <string.h>
#define N 20

char * copy_str(char *ptr1 , char *ptr2)
{
  char *temp = ptr2 ;
  while((*(ptr2++) = *(ptr1++)) != '\0');
//  {
//    *ptr2 = *ptr1 ;
//    *ptr1++ ;
//    *ptr2++ ;
//  }
//  *ptr2 = '\0';
  ptr2 = temp ;
  return ptr2;
}

int main(int argc, const char *argv[])
{
    char str1[N] = "abcdef";
    char str2[N] ;
    char *ptr1 = str1 ;
    char *ptr2 = str2 ;
    strcpy(ptr2 , ptr1);  //copy_str(ptr1 ,ptr2);
    printf("%s\n", ptr2);
    return 0;
}

