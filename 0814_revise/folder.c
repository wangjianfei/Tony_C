#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(int argc, const char *argv[])
{
    char str[100] = "ghigk";
    char str1[100];
    FILE *fp = NULL;
    fp = fopen("text.txt","a+");
    if(fp == NULL)
    {
       perror("folder");
       exit(0);
    }
   // fputs(str,fp);
    fgets(str1,100,fp);
   // fprintf(fp,"%s" ,str);    
   // rewind(fp);
   // fscanf(fp,"%s",str1);
    puts(str1);
    int i = 0;
    i = strlen(str1);
    printf("%d\n", i);
//    puts("abcd");
//    fprintf(stdout ,"%s\n" ,str);
   // gets(str1);
   // printf("%s",str1);
    fclose(fp); 
    return 0;
}

