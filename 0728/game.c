/*  循环删除数据，  
 *  就是数到某个数，删除次数，重新开计数
 *  */
#include <stdio.h>
#define N 11

int main(int argc, const char *argv[])
{
    int array[N];
    int a[3] = {0};
    int i = 0;
    for(i = 0 ;i < N ; i++)
    {
      array[i] = i+1 ;
      printf("%4d",array[i]);
    }
     printf("\n");

    int  j =0 ;
         i =0 ;
      while(1)
      {
        if(i>N-1)
        {
          i=0;
        }
        while(array[i]<0)
        {
          i++;
          if(i>N-1)
          {
            i=0;
          }
        }

        a[j]=array[i];
        printf("%4d",a[j]);
        if(j==2)
        {
          j=-1;
          array[i]=-array[i];
          
          printf(" out\n");
        }

        int m = 0;
        int n = 0;
        int flag=0;
        for(m = 0; m < N ; m++)    // if((j>0)&&(a[j]==a[j-1]))
        {                          // {
           if(array[m]>0)          //    printf("    left\n") ;
           {                       //    break ;
             n++;
             flag=array[m];                      // }
           }
        }
        if(1==n)
        {
           printf("  %4d  left\n",flag);
           break ;
        }
        j++;
        i++;
      }
    printf("\n");
    return 0;
}

