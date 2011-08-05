#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, const char *argv[])
{
    FILE *fp1 = NULL;
    FILE *fp2 = NULL;
    int p = 0;
    fp1 = fopen("test.txt" , "r+");
    fp2 = fopen("copy.txt" , "w+");
    if((fp1 != NULL)&&(fp2 != NULL))
    {
       perror("error");
       exit(0);
    }
    while((p = getc(fp1))!=EOF)
    {
        putc(p ,fp2);
    }
    fclose(fp1);
    fclose(fp2);
    return 0;
}

