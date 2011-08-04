#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define M 10
#define N 8



int main(int argc, const char *argv[])
{
    int i = 0 ;
    int j = 0 ;
    int array[M][N];
    srand(time(NULL));
    for(i = 0 ; i < M ; i++)
    {
        for(j = 0 ; j < N ; j++)
        {
           array[i][j] =rand()%(2*M);
        }
    }
    for (i = 0; i < M; i++)
    {
        for (j = 0; j < N; j++)
        {
            printf("%4d",array[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    return 0;
}

