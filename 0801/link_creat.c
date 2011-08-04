#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

struct student 
{
   int number;
   char name[10];
   int age;
   char adress[30];
   struct student *next ;
};

typedef struct student  stu;

stu *link_creat(int n)
{
    stu *head = NULL;
    stu *p = NULL ;
    int i = 0;
    srand(time(NULL));

    p = malloc(sizeof(stu));
    if(p == NULL)
    {
       perror("link");
       exit(0);
    }
    head = p ;
    p -> number = 1;
    strcpy( p -> name , "student");
    p ->age = rand()%30 ;
    strcpy( p -> adress , "tai yuan gong ye xue yuan");
    p -> next = NULL;

    for(i = 1 ; i < n ;i++)
    {
       p -> next = malloc(sizeof(stu));
       if(p -> next == NULL)
       {
          perror("link");
          exit(0);
       }
       p -> next -> number = i+1;
       strcpy( p -> next -> name , "student");
       p -> next -> age = rand()%30 ;
       strcpy( p ->next-> adress , "tai yuan gong ye xue yuan");
       p -> next ->next = NULL;
       p = p -> next ;
    }
    return head;
}

void printf_link(stu *p)
{
    int i = 0;
    while(p != NULL)
    {
       printf("%-5d %s  %-5d  %s\n" ,p->number,p->name,p->age,p->adress);
       p = p -> next ;
       i++;
    }
    printf("%5d\n", i);
}

int main(int argc, const char *argv[])
{
    char * const p = NULL;
    stu *head = NULL;
    head = link_creat(10);
    printf_link(head);
    return 0;
}

