/*   rewind 是该边文件的指示器位置 当刚刚进行了一次文件操作 又要进行时
 *   文件指示器不在文件的开始  可以用rewind(fp)将文件指示器只在文件开头
 *
 *
 *   fread
 *
 *
 * */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(int argc, const char *argv[])
{
    FILE *fp = NULL;
    char str[100] = "this is a c programme"; 
    char r_str[100] = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
    fp = fopen("test.txt" , "w+");
    if(fp == NULL)
    {
       perror("file");
       exit(0);
    }
    int i  = 0;
//    while(str[i] != '\0')
//    {
//       putc(str[i],fp);
//       i++;
//    }
      
   //   rewind(fp);
      fwrite(str ,1 , strlen(str) ,fp);  
      fseek(fp ,0 ,SEEK_SET);
      i = fread(r_str , 1 , 99 , fp);
      r_str[i] = '\0';
//    rewind(fp);
/*    i = 0;
    while((r_str[i] = getc(fp)) != EOF)
    {
       i++;
    }
    r_str[i] = '\0';*/
    printf("%s\n" ,r_str);
    fclose(fp);
    return 0;
}


