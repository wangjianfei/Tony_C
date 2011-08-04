#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student
{
    int number;
    char name[10];
    struct student  *next;
};

typedef struct student  stu;

stu *add_node(stu *p)
{
   stu *head = p ;
   stu *ptr = NULL;
   ptr = malloc(sizeof(stu));
   if(ptr == NULL)
   {
      perror("crear_node");
      exit(0);
   }
   printf("input a number :");
   scanf("%d" ,&ptr->number);
   printf("input a name :");
   scanf("%s" , ptr->name);
   ptr->next = NULL;
   if(p == NULL)
   {
      return ptr;
   }
   if(p->number > ptr->number)
   {
       ptr->next = p;
       head = ptr ;
       return head;
   }
   while(p->next != NULL)
   {
       if(p->next->number > ptr->number)
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
    while(p != NULL)
    {
       printf("%-5d   %s\n",p->number ,p->name);
       p = p->next;
    }
}

int main(int argc, const char *argv[])
{
    stu *head = NULL;
    int i = 0;
    for(i = 0 ;i <10 ;i++)
    {
       head = add_node(head);
    }
    printf_link(head);
    return 0;
}


