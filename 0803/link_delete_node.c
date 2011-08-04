#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student
{
    int number;
    char name[10];
    struct student *next;
};

typedef struct student stu;

stu *creat_link(int n)
{
    int i = 0;
    stu *head = NULL;
    stu *p = NULL;

    head = p = malloc(sizeof(stu));

    if(p == NULL)
    {
       perror("creat_link");
       exit(0);
    }

    p -> number  = 1;
    strcpy(p -> name , "student");
    p -> next = NULL;

    for( i  = 1; i < n ; i++)
    {
        p -> next = malloc(sizeof(stu));

        if(p -> next == NULL)
        {
          perror("creat_link");
          exit(0);
        }

        p -> next -> number = i+1;
        strcpy(p -> next ->name , "student");
        p -> next -> next = NULL;
        p = p -> next;
    }
    return head ;
}

stu *delete_node(stu *p)
{
    stu *head = p;
    stu *ptr = NULL;
    int i = 0 ;
    printf("input i :");
    scanf("%d" ,&i);
    if(NULL == p)
    {
       // printf("empty link\n");
        return NULL;
    }
    if(p -> number == i)
    {
         ptr = head;
         head = p = p -> next;
         free(ptr);
    }
    else
    {
        while(p -> next != NULL)
        {
           if(p ->next -> number == i)
           {
              ptr = p -> next ;
              p -> next  = p-> next -> next;
              free(ptr);
              return head ;
           }
    /*       if((p -> next -> next == NULL)&&(p -> next -> next -> number ==i))
           {
              ptr = p -> next -> next;
              p -> next = NULL ;
              free(ptr);
              return head;
           }*/
           p = p -> next;
        }
     }
     
    if(p->next == NULL)
    {
      printf( "no number match\n"); 
    }
   return head;
}

void printf_link(stu *p)
{
    if(p == NULL)
    {
       printf("empty link\n");
    }
    while(p != NULL)
    {
       printf("%-5d    %s\n" , p ->number , p -> name);
       p = p -> next;
    }
}
int main(int argc, const char *argv[])
{
    stu *head = NULL;
   // head = creat_link(10);
    printf_link(head);
    head =  delete_node(head);
    printf_link(head);
    return 0;
}

