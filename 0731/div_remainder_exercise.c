#include <stdio.h>

int div_remainder(int *p , int n)
{
   int i = 0 ;
   int j = 0 ;
   int count = 0 ;
   int flag = 0 ;
   int record = 0 ;
   for(i = 0 ; i < n ; i++)
   {  
      record = p[i];
      while(p[i] > 0)
      {
         if(p[i]%10 == 9)
         {
            count++;
         }
         p[i] /= 10; 
      }

      if(count > flag)
      {
         printf("%4d", record);
         flag = count ;
      }

   }
   printf("\n");
  return count ;
}

int main(int argc, const char *argv[])
{
    int array[100];
    int count = 0 ;
    int i = 0 ;
    for(i = 0 ; i < 100 ; i++ )
    {
       array[i]=i+1;
    }
    count =  div_remainder(array , 100);
    printf("%4d\n", count);
    return 0;
}

