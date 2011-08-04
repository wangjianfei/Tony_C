/*  是用指针打印字符串 ，forward and reverse*/
#include <stdio.h>

#define N 20

int main(int argc, const char *argv[])
{
    char str[N] = "hello world!";
    char *ptr = str ;
    int i = 0 ;
    while(*ptr != '\0')
    {
       printf("%c",*ptr);
       ptr++;          //指针++
       i++;
    }
    printf("\n");
    ptr--;           //注意此时 指针是指在'\0',所以要--
    while(i>0)          //while(ptr >= str)是老师的判断条件
    {
       printf("%c",*ptr);
       ptr--;          //反方向打印，ptr--
       i--;
    }
    printf("\n");
    return 0;
}

