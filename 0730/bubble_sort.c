#include <stdio.h>
#define N 15
int main(int argc, const char *argv[])
{
    int array[N]={5,11,3,2,14,1,4,12,7,6,13,9,10,8,0};
    int i = 0 ;
    int j = 0 ;
    int var= 0 ;
    while(j < N -1)
    {
        for(i = 0 ; i < N - 1 - j ; i++)
        {
          if(array[i]>array[i+1])
          {
              var =  array[i];
              array[i] = array[i+1];
              array[i+1] = var ;

          }
        }
        j++;
    }
    for(i= 0 ; i< N ; i++)
    {
        printf("%4d", array[i]);
    }
    printf("\n");
    return 0;
}

