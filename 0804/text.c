/*  有关文件的基本操作 FILE 定义文件类型的变量
 *                 fopen 打开文 格式：fopen("pash" , "mode")
 *   FILE *fp      fclose(fp)
 *   fprintf 输出内容到文件 格式:fprintf(dest fp , "%s\n" , content address)
 *   fscanf 读出文件内容到指定的地方 格式：fscanf(content fp ,"%s",dest address)
 *   但 fscanf 遇到空格就结束
 *   fgets 读出文件内容到指定的地方 格式：
 *                           fgets(char *s, int size, FILE *stream)
 *      s 为目标地址  size为输出字符的个数最多为size-1   stream 数据流的来源
 *      fgets(r_str , 5 , fp)
 *      fgets 3中结束的条件：遇到空格换行  即回车
 *                           达到size的值
 *                           文件内容结束
 *      */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, const char *argv[])
{
//   char str[100] = "good morning ,everyone";
     FILE *fp = NULL;
    char r_str[100] = {0};
    fp =  fopen("test.txt" ,"r+");
    if(fp == NULL)
    {
      perror("open");
      exit(0);
    }
    int i = 0 ;
    while((r_str[i] = getc(fp)) != EOF)
    {
        i++;
    }
    r_str[i] = '\0';
    printf("%s\n" ,r_str);
//    fscanf(stdin ,"%s" ,r_str);
//    fgets(r_str , 99 , stdin);
//    fprintf(stdout,"%s" ,r_str);
//    fgets(r_str , 99 , stdin);

//    fputs(r_str ,stdout);
    fclose(fp);
//    gets(r_str);
//    fputs(r_str ,stdout);
//    puts(r_str);
//    printf("%s\n" ,r_str);
//   printf("%s\n" ,r_str);
    return 0;
}

