/*   
 *    在多次输入scanf中，不要乱用getchar，可能会给你带来意想不到的错误
 *    这与getchar的性质有关，因为getchar一开始是从一个缓冲区找数据，scanf
 *    函数见到空格回车停止，把空格回车留在缓冲区，会给使用getchar带来很大
 *    的麻烦
 *
 *    定义变量 链表 那是只针对内存，对硬盘无用
 *
 *
 *   使用getchar输入一个字符，再输出时，如果只输出这个字符，则在输出后在加一个
 *   getchar   
 *   example：：：：： 
         p =  getchar();
         printf("%d\n" , p);
         getchar();
 * */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 10

struct student
{
   int num ;
   char name[10];
   struct student *next;
};

typedef struct student stu;

/*stu *creat_link( int n)   //创建一个链表
{
     stu *head = NULL;
     stu *p = NULL;
     head = p = malloc(sizeof(stu));
     if(p  == NULL)
     {
        perror("a_node");
        exit(0);
     }
     p->num = 1;
     printf("num is 1\n");
     printf("input a name:");
     scanf("%s",p->name);
     p->next = NULL;
     int i = 0;
     for(i =  1; i < n; i++)
     {
           p->next = malloc(sizeof(stu));
           if(p->next == NULL)
           {
              perror("creat");
              exit(0);
           }
           p->next->num = i+1;
           printf("num is %d\n", p->next->num);
           printf("input a name:");
           scanf("%s" , p->next->name);
           p->next->next = NULL;
           p = p->next;
     }
     return head;
}*/

stu *delete_a_node(stu *p)
{
   stu *head = p;
   stu *ptr = NULL;
   int i = 0;
   printf("delete a node\n");
   printf("input a num:");
   scanf("%d",&i);
   if(p == NULL)
   {
       printf("this is an empty link\n");
       return NULL;
   }
   if(i == p->num)
   {
      ptr = p;
      head = p = p->next;
      free(ptr);
      return head;
   }
   while(p->next != NULL)
   {
      if(p->next->num == i)
      {
          break;
      }
      p = p->next;
   }
   if(p->next == NULL)
   {
      printf("no match\n");
   }
   else
   {
      ptr = p->next;
      p->next = p->next->next;
      free(ptr);
   }
   return head;
}

/**********************************************************
   函数名称：add_a_node
   函数参数：链表的头指针
   函数功能：添加一个节点 
*************************************************************/
stu *add_a_node(stu *p)
{
   stu *head = p;
   stu *ptr = NULL;
   ptr =  malloc(sizeof(stu));
   if(ptr == NULL)
   { 
      perror("add node");
      exit(0);
   }
   printf("add a node\n");
   printf("input a num:");
   scanf("%d" ,&ptr->num);
   printf("input a name:");
   scanf("%s",ptr->name);
   ptr->next = NULL;
   if(p == NULL)
   {
      head = ptr;
      return head;
   }
   if(ptr->num < p->num)
   {
      ptr->next = p;
      head = ptr ;
      return head;
   }
   while(p->next != NULL)
   {
      if(p->next->num > ptr->num)
      {
         break;
      }
      p = p->next;
   }
   ptr->next = p->next;
   p->next = ptr;
   return head;
}

void printf_link(stu *p)
{
    if (p == NULL) 
    {
        printf("this is an empty link\n");
    }
    while(p != NULL)
    {
        printf("%-5d     %s\n" ,p->num ,p->name);
        p = p->next;
    }
}

void menu()
{
   puts("1 add a node    ");
   puts("2 delete a node    ");
   puts("3 print    ");
   puts("4 save  ");
   puts("5 exit   ");
}

void save_link(stu *head)
{
    FILE *fp = NULL;
    fp = fopen("text.txt","w+");
    if(fp == NULL)
    {
        perror("open");
        exit(0);
    }
    while(head != NULL)
    {
       fprintf(fp, "%d   %s\n",head->num ,head->name);
       head = head->next;
    }
    fclose(fp);
}

stu *read_data()
{
  stu *head = NULL;
  stu *p = NULL;
  int num;
  char name[10];
  FILE *fp = NULL;
  fp = fopen("text.txt", "r+");
  if(fp == NULL)
  {
     perror("open");
     exit(0);
  }
  if( fscanf(fp , "%d%s", &num ,name) == EOF)
  {
     return NULL;
  }
  head = p = malloc(sizeof(stu));
  if(p == NULL)
  {
     perror("read_data");
     exit(0);
  }
  p->num = num;
  strncpy(p->name , name ,9);
  p->next = NULL;
  while(fscanf(fp , "%d%s", &num ,name) != EOF)
  {
      p->next = malloc(sizeof(stu));
      if(p->next == NULL)
      {
         perror("data"); 
         exit(0);
      }
      p->next->num = num;
      strncpy(p->next->name , name ,9);
      p->next->next = NULL;
      p = p->next;
  }
  fclose(fp);
  return head;
}

int main(int argc, const char *argv[])
{
    stu *head = NULL;
    menu();
    int choice = 0;
    head = read_data();
    while(1)
    {
        printf("please make a choice:");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1 : head = add_a_node(head); break;
            case 2 : head = delete_a_node(head) ;break;
            case 3 : printf_link(head) ; break;
            case 4 : save_link(head);break;
            case 5 : break ;
            default : printf("num is un character");
        }
        if(choice == 5)
        {
           break;
        }
    
         
      // switch()
    }
 /*   head = delete_a_node(head);
//   printf_link(head)
    head = add_a_node(head);
    printf_link(head);
    getchar();
    head = add_a_node(head);
    printf_link(head);
    getchar();
    head = add_a_node(head);
    printf_link(head);
    getchar();
    head = add_a_node(head);
    printf_link(head);
    head = delete_a_node(head);
    printf_link(head);*/
    return 0;
}


