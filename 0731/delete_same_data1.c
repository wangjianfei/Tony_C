#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define  M 20

void printf_array(int *p , int n)
{
   int i = 0 ;
   for (i = 0; i < n; i++)
   {
       if(i%10 == 0)
       {
          printf("\n");
       }
       printf("%4d",p[i]);
   }
   printf("\n");
}

void init_array(int *p ,int n)
{
   int i = 0 ;
   srand(time(NULL));
   for (i = 0; i < n; i++)
   {
       p[i] = rand()%(n/2);
   }
}

void delete_same_data(int *p ,int n)
{
   int i = 0 ;
   int j = 0 ;

   for (i = 0; i < n-1; i++)
   {
       if(p[i] != -1)
       {
          for(j = i+1 ;j < n ; j++)
          {
              if (p[i] ==p[j])
              {
                  p[j] = -1 ;
              }
          }
       }
   }
}

void printf_result(int *p ,int n)
{
   int i = 0 ;
   for(i = 0 ; i < n ;i++)
   {
      if(p[i] != -1)
      {
         printf("%4d" ,p[i]);
      }
   }
   printf("\n");
}

int main(int argc, const char *argv[])
{
    int array[M];
    init_array(array , M);
    printf_array(array , M);
    delete_same_data(array , M);
    printf_array(array , M);
    printf("\n");
    printf_result(array , M);   
    return 0;
}


