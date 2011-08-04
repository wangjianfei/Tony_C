#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define M 10
#define N 10

void init_array( int (*p)[N] , int m)
{
    srand(time(NULL));
    int i = 0 ;
    int j = 0 ;
    for(i = 0 ; i < m ; i++)
    {
       for(j = 0 ; j < N ;j++)
       {
           *(*(p+i)+j) = rand()%(10*m); 
       }
    }


}

void sort_array( int (*p)[N] , int m)
{
     int count  = 0 ;
     int temp = 0 ;
     int j = 0 ;
     for(j = 0 ;j < (N*m) ; j++)
     {
         for(count = 0 ; count <(N*m-j)  ; count++)
         {
               if(*(*(p+(count/N))+(count%N)) > *(*(p+((count+1)/N))+((count+1)%N)))
               {
                   temp = *(*(p+(count/N))+(count%N)) ;
                   *(*(p+(count/N))+(count%N)) = *(*(p+((count+1)/N))+((count+1)%N));
                   *(*(p+((count+1)/N))+((count+1)%N)) = temp ;
                  
               }
         }
     }
}

int main(int argc, const char *argv[])
{
    int array[M][N];
    int i = 0 ;
    int j = 0 ;
    init_array(array , M);
    for(i = 0 ; i < M ;i++)
    {
        for(j = 0 ; j < N ; j++ )
        {
             printf("%5d", array[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    sort_array(array , M);
    getchar();
    for(i = 0 ; i < M ;i++)
    {
        for(j = 0 ; j < N ; j++ )
        {
             printf("%5d", array[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    
    return 0;
}

