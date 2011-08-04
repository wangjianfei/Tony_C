#include <stdio.h>

int factorial(int n)
{
   int total = 0 ;

   if(n == 1)
   {
      total=1;
      return total ;
   }
   total = n*factorial(n-1);
}

int main(int argc, const char *argv[])
{
    int total = 0;
    total =  factorial(5);
    printf("%d\n", total);
    return 0;
}

