/* exercise for and while  at the same time , compare them*/
#include <stdio.h>

int main(int argc, const char *argv[])
{
  // unsigned  int a = -10 ;
  // unsigned  int b = 6 ;
  int i= 0 ;
   unsigned  int array[100];
   unsigned  int b = 6 ;
   array[100] = 10 ;
   for (i = 0; i < 100; i++)
   {
       array[i] = i * 3 + 1 ;
       printf("%5d",array[i]);
   }
   printf("\n");   
   i= 0;
   while(i < 100)
   {
      array[i] = i * 3 + 1 ;
      printf("%5d",array[i]);
      i++;
   }

    printf("\n");
    printf("%d\n",b);
    return 0;
}

