/*
 *  冒泡排序
 * */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 20

void print_array(int *p ,int n)
{
   int i = 0;
   for (i = 0; i < n; i++)
   {
       if(i%10 == 0)
       {
         printf("\n");
       }
       printf("%-5d" , p[i]);
   }
   printf("\n");
}

void srand_array(int *p ,int n)
{
   srand(time(NULL));
   int i  = 0;
   for(i = 0 ;i < n ;i++)
   {
      p[i] = rand()%(2*n); 
   }
}

void sort_array(int *p ,int n)
{
   int i = 0;
   int j = 0;
   int temp =0;
   for(i = 0; i < n; i++)
   {
       for(j = 1; j < n-i ;j++)
       {
          if(p[j] < p[j-1])
          {
             temp = p[j];
             p[j] = p[j-1];
             p[j-1] = temp;
          }
       }
   }
}
int main(int argc, const char *argv[])
{
    int array[N] = {0};
    srand_array(array ,N);
    print_array(array ,N);
    getchar();
    sort_array(array ,N);
    print_array(array ,N);
    return 0;
}

