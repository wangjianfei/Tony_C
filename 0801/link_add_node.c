#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct student
{
    int number;
    char  name[10];
    struct student *next;
};

typedef struct student stu;

stu *creat_link(int n)
{
   int i = 0;
   stu *head = NULL;
   stu *p = NULL;

   p = malloc(sizeof(stu));
   if( p == NULL)
   {
      perror("creat_link");
      exit(0);
   }

   head = p;

   p->number = 1 ;
   strcpy(p->name , "student");
   p->next = NULL;
   
   for(i = 1 ; i < n ;i++)
   {
      p->next = malloc(sizeof(stu));
      if(p->next  == NULL)
      {
          perror("creat_link");
          exit(0);
      }

      p->next->number = i+1;
      strcpy(p->next->name ,"student");
      p->next->next = NULL;

      p = p->next;
   }
   return head ;
}

stu *add_node(stu *p)
{
    stu *head = p ;
    stu *p_add_node = NULL;
    p_add_node = malloc(sizeof(stu));
    if(p_add_node == NULL)
    {
       perror("add a node");
       exit(0);
    }
    p_add_node->number = 0;
    strcpy(p_add_node->name , "wang");
    p_add_node->next = NULL;

    if(p->number > p_add_node->number)
    {
       p_add_node->next = head;
       head = p_add_node;
    }
    else
    {
        while(p->next != NULL)
        {
           if(p->next->number > p_add_node->number)
           {
              break;
           }
           p = p->next;
        }
        p_add_node->next = p->next ;
        p->next = p_add_node;
    }
    return head;
}

void printf_link(stu *p)
{
    while( p != NULL)
    {
       printf("%-5d     %s\n" ,p->number , p->name);
       p = p->next;
    }
    printf("\n");
}

int main(int argc, const char *argv[])
{
    stu *head = NULL;
    head = creat_link(10);
    printf_link(head);
    head = add_node(head);
    printf_link(head);
    return 0;
}

