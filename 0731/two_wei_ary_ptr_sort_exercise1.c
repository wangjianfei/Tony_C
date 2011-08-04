#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define M 6
#define N 5

void init_array(int *p ,int m)
{
     srand(time(NULL));
     int i = 0 ;
     for(i =0 ;i < m ;i++)
     {
        p[i] = rand()%(m);
     }

}

void printf_array(int *p ,int m)
{
   int i = 0 ;
   for(i = 0 ; i < m ; i++)
   {
      if(i % N == 0)
      {
        printf("\n");
      }
      printf("%5d", *(p+i));
   }
   printf("\n");
}

void sort_array(int *p ,int m ,int n)
{
   int i = m;
   int j = n;
   int mid = p[(m + n)/2];
   int temp = 0;
   do
   {
       while((p[i] < mid)&&(i < n)) i++;
       while((p[j] > mid)&&( j > m)) j--;
       if(i <= j)
       {
          temp = p[i];
          p[i] = p[j];
          p[j] = temp;
          i++;
          j--;
       }
   }
   while(i <= j);
   if(j >= m)
   {
      sort_array(p , m ,j);
   }
   if(i <= n)
   {
      sort_array(p , i ,n);
   }

}

int main(int argc, const char *argv[])
{
    int array[M][N];
    int *ptr = &array[0][0];
    init_array(ptr , M*N);
    printf_array(ptr , M*N);
    getchar();
    sort_array(ptr , 0 ,M*N-1);
    printf_array(ptr , M*N);
    return 0;
}

