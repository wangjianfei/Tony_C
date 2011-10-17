#include <stdio.h>
#include <string.h>

int my_strncmp(char *a,char *b)
{
//    int 
    while(*a != '\0')
    {
        if(*a == *b)
        {
            a++;
            b++;
        }
        else
        {
            break;
        }
    }
    if((*a == '\0')&& (*b == '\0'))
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

int main(int argc, const char *argv[])
{
    char str1[15];
    char str2[15];
    printf("input a string:");
    scanf("%s",str1);
    printf("input a string:");
    scanf("%s",str2);
    int i = my_strncmp(str1,str2);
    printf("%d\n",i);
    return 0;
}

