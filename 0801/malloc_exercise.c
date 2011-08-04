/*    
 * */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct student
{
   int number;
   char name[10];

};

typedef struct student stu ;

int main(int argc, const char *argv[])
{
    stu *ptr = NULL;    // 当定义指针时，不赋初值时，最好赋NULL，如果不赋值，可
                        // 能会造成严重的后果，导致程序崩溃
    ptr  = malloc(sizeof(stu));     //知道大小也要写成sizeof，以便更好的兼容,
                              // malloc返回一个指针
    if( ptr == NULL)
    {
        perror("malloc");
        exit(0);
     
    }
    ptr -> number = 1 ;
    strcpy(ptr -> name , "wang");
    printf("%-5d\n", ptr -> number);
    printf("%5d\n", ptr -> number);
    printf("%s\n" , ptr -> name);

    return 0;
}

