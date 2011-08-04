#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define M 20

void print_array(int *p ,int n)
{
    int i =0 ;
    for(i = 0;i < n ; i++)
    {
       if(i % 10 ==0)
       {
          printf("\n");
       }
       printf("%5d",p[i]);
    }
    printf("\n");
}

void init_array(int *p , int n)
{
  
    srand(time(NULL));
    int i = 0 ;
    for(i = 0 ;i < n ;i++)
    {
       p[i]= rand()%(n/2);
    }
}

void  delete_same_data(int *p ,int n)
{
   int i = 0;
   int flag = 0;
   int j = 0;
   int temp = 0 ;
   printf("%4d", p[0]);
   for(i = 1 ;i < n ;i++)
   {
       flag = i ;
       for(j = 0 ; j < flag ; j++)
       {
         if(p[i]==p[j])
         {
           temp = 1 ;
           break ;
         }
       }
       if(temp != 1)
       {
         printf("%4d", p[i]);
       }
       if(temp == 1)
       {
          temp = 0 ;
       }
   }
   printf("\n");
}

int main(int argc, const char *argv[])
{
     int array[M];
    init_array(array , M);
    print_array(array , M);
    getchar();
    delete_same_data(array , M);
    return 0;
}

