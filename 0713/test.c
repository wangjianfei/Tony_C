#include <stdio.h>
#include <string.h>

struct data
{
    char str[10];
};

typedef struct data data;

int main(int argc, const char *argv[])
{
    data data_1,data_2;
    strcpy("abcdef",data_1.str);
    data_2.str = data_1.str;
    printf("%s\n",data_2.str);
    int a = 3;
    int b = 4;
    printf("%d\n",a);
    printf("%d\n",b);

    return 0;
}

