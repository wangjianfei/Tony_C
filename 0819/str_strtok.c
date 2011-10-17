#include <stdio.h>
#include <string.h>

int main(int argc, const char *argv[])
{
    char str[]="tai yuanggggggggong ye xue yuan";
    char *p = strtok(str ," ");
    printf("%s\n",p);
    p = strtok(NULL ,"g");
    printf("%s\n",p);
    p = strtok(NULL ," ");
    printf("%s\n",p);
    return 0;
}

