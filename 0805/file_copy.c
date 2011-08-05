#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, const char *argv[])
{
    char str[1024] = {0};
    FILE *fp1 = NULL;
    FILE *fp2 = NULL;
    fp1 = fopen("test.txt" , "r+");
    if(fp1 == NULL)
    {
       perror("test");
       exit(0);
    }
    fp2 = fopen("copy.txt" ,"w+");

    if(fp2 == NULL)
    {
       perror("test");
       exit(0);
    }

    fread(str ,1 , 1023 ,fp1);
    fwrite(str , 1, strlen(str),fp2);
    fclose(fp2);
    fclose(fp1);
    return 0;
}

