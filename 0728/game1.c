#include <stdio.h>

#define N 10

int main(int argc, const char *argv[])
{
    int array[N] = {0} ;
    int i = 0 ;
    int interval = 3 ;
    int out_counter = 0 ;
    int total_num = 0 ;
    
    for(i = 0;total_num < N-1 ; i++)
    {
       if(i == N)
       {
          i = 0 ;
       }
       if(array[i] == 0)
       {
          out_counter++;
          if(out_counter == interval)
          {
            out_counter = 0 ;
            printf("%4d (out)\n",i);
            array[i] = 1 ;
            total_num++;
          }
          else
          {
             printf("%4d",i);
          }
       }
    }
    printf("  left\n");
    return 0;
}

