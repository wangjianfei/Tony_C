#include <stdio.h>
#include "various.h"

/*************************************************************************
 *函数功能:画一个棋盘
 *功能描述：开始点坐标（100，40）
 *          X_NUM = 29
 *          Y_NUM = 24
 *          间隔为space = 30
 *
 *
 * ***********************************************************************/
void printf_board(void)
{
   int i = 0;
   int j = 0;
   for(j = 0;j<768;j++)
   {
        for(i = 0;i<1024;i++)
        {
            fb_one_pixel(i , j ,0x00996633);
        }
   }
   for(i = 0;i < X_NUM ;i++)
   {
        fb_line(ST_X+SPACE*i,ST_Y,ST_X+SPACE*i,ST_Y+SPACE*(Y_NUM-1),0x00ffffff);
   }
   for(i = 0;i < Y_NUM ;i++)
   {
       fb_line(ST_X,ST_Y+SPACE*i,ST_X+SPACE*(X_NUM-1),ST_Y+SPACE*i,0X00ffffff);
   }
   for(j=180;j< 205;j++)
   {
        for(i = 20;i < 80;i++)
        {
            fb_one_pixel(i , j ,0x00ffffff);
        }
   }
   for(j=240;j<265;j++)
   {
        for(i = 20;i<80;i++)
        {
            fb_one_pixel(i , j ,0x00ffffff);
        }
   }
   for(i = 190 ;i < 205;i++)
   {
      fb_one_pixel(50 , i ,0);
      fb_one_pixel(49 , i ,0);
      fb_one_pixel(51 , i ,0);
   }
   for(i = 40,j=180;i<50;i++,j++)
   {
        fb_one_pixel(i-1 ,j ,0);
        fb_one_pixel(i ,j ,0);
        fb_one_pixel(i+1 ,j ,0);
   }

   for(i = 60,j=180;i>50;i--,j++)
   {
        fb_one_pixel(i-1 ,j ,0);
        fb_one_pixel(i ,j ,0);
        fb_one_pixel(i+1 ,j ,0);
   }

   for(i = 240;i<265;i++)
   {
        fb_one_pixel(39 ,i ,0);
        fb_one_pixel(40 ,i ,0);
        fb_one_pixel(41 ,i ,0);
        fb_one_pixel(59 ,i ,0);
        fb_one_pixel(61 ,i ,0);
        fb_one_pixel(60 ,i ,0);
   }
   for(i = 40,j=242;i < 60;i++,j++)
   {
        fb_one_pixel(i ,j ,0);
        fb_one_pixel(i+1,j ,0);
        fb_one_pixel(i-1,j ,0);
   }
}
