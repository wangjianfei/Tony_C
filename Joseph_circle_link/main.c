#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct people    //定义结构体类型
{
   int number;
   struct people *next;
};

typedef struct people peo;  //定义变量类型 用peo代替 struct people

peo *creat_link(int n)    //创建链表
{
    int i =0 ;
    peo *head = NULL;
    peo *p = NULL;
    head = p = malloc(sizeof(peo));
    if(p == NULL)
    {
       perror("creat");
       exit(0);
    }
    p->number = 1;
    p->next = NULL;
    for(i = 1 ;i < n ; i++)
    {
        p->next = malloc(sizeof(peo));
        if(p == NULL)
        {
            perror("creat");
            exit(0);
        }
        p->next->number = i+1;
        p->next->next = NULL;
        p = p->next;
    }
    p->next = head;    //让链表的头尾相接生成环状链表
    return p;         //返回尾指针，利用尾指针可以找回头指针
}

void game(peo *p)    //game的主要程序区
{
  peo *head = p->next;
  int interval = 3;
  int out_counter = 0;
  while(head->next != head)
  {    
      out_counter++;
      if(interval == out_counter) 
      {
          printf("%-5d\n", head->number);          
          p->next = head->next;
          free(head);         //释放head存储区
          head = p->next;     //释放了head，要继续给它赋值，继续使用
          out_counter = 0;    //注意out_counter清零
      }
      else
      {
         printf("%-5d" , head->number);
         head = head->next;
         p = p->next;
      }
  }
  printf("%5dleft\n" ,head->number);
}

int main(int argc, const char *argv[])
{
    int num = 0;
    printf("Please input a number :");
    scanf("%d" ,&num);
    peo *head = NULL;
    peo *rear = NULL;
    rear = creat_link(num);
    game(rear);
    return 0;
}

