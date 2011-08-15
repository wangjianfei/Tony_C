#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 20

void printf_array(int *p ,int n)
{
   int i = 0;
   for (i = 0; i < n; i++)
   {
       if(i%10 == 0)
       {
          printf("\n");
       }
       printf("%-5d",p[i]);
   }
   printf("\n");
}

void srand_array(int *p ,int n)
{
    srand(time(NULL));
    int i = 0;
    for (i = 0; i < n; i++)
    {
        p[i] = rand()%(2*n);
    }
}

void quick_sort(int *p ,int x ,int y)
{
   int i = x;
   int j = y;
   int temp = 0;
   int mid = p[(i+j)/2];
   do
   {
       while((p[i]<mid)&&(i<y)) i++;
       while((p[j]>mid)&&(j>x)) j--;
       if(i<=j)
       {
          temp = p[i];
          p[i] = p[j];
          p[j] = temp;
          i++;
          j--;
       }
  // quick_sort(p , i ,j);
   }
   while(i<=j);
   if(i<y)
   {
      quick_sort(p,i,y);
   }
   if(x<j)
   {
      quick_sort(p,x,j);
   }
}

int main(int argc, const char *argv[])
{
    int array[N] = {0};
    srand_array(array ,N); 
    printf_array(array ,N);
    getchar();
    quick_sort(array ,0,N-1);
    printf_array(array,N);
    return 0;
}

