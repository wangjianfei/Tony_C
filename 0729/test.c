#include <stdio.h>

int argc = 0 ;
char str[128] = "hello 100  200";
char *argv[10];
int main(void)
{
    int state = 0 ;
    int i = 0 ;
    while(str[i])
    {
   
       if((state==0)&&(str[i] !=' '))
       {
         state = 1;
         argv[argc++] = str + i ;
       }
       if((state==1)&&(str[i] == ' '))
       {
          state = 0 ;
          str[i] = '\0';
       }
       i++;
    }
    printf("%d\n",argc);
    for(i = 0 ; i < argc ; i++)
    {
        printf("%s\n", argv[i]);  
    }
    return 0;
}

