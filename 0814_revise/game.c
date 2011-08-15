/*  此程序源于一个故事  是约瑟夫杀人的故事   从某个人开始数数   数到某个数本人被    杀，依次循环  最后只剩下一个人  
 * */
#include <stdio.h>
#define N 10
#define OUT_CUONTER 3
int main(int argc, const char *argv[])
{
    int array[N] =  {0};
    int out_counter = 0;  // 出局的数
    int interval = 0;   //间距  也就是隔几个人
    int flag = 0;
    int i = 0;
    for(i = 0; flag < N-1 ; i++)
    {
         if(i == N)
         {
            i = 0;
         }
         if(array[i] == -1)
         {
             continue ;
         }
         if(out_counter == OUT_CUONTER)
         {
             out_counter = 0;
             array[i] = -1;
             flag++;
             printf("%-5d out\n" ,i);
         }
         else
         {
             out_counter++;
             printf("%-5d", i);
         }
         
//ZZ         printf("  left  \n");
/*         if(flag ==9)
         {
            printf("  left  \n");
            break;
         }*/
    }
    for(i = 0; i < N ;i++)
    {
         if(array[i] == 0)
         {
             printf("  left%d  \n", i);
         }
    }
    return 0;
}

