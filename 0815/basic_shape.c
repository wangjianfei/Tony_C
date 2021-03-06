#include <stdio.h>
#include "various.h"
#include <stdlib.h>
//#include "func.h"


/************************************************
 *函数功能：点亮任意位置的一个点
 * *********************************************/
int fb_one_pixel(int x,int y,u32_t color)
{
   *((u32_t *)fb_v.memo + y*fb_v.w+x) = color; //点亮一个点 让fb_v.memo强制类型
                                            //转换 ，转换成u32_t
   return 0;
}


/************************************************
 * 函数功能:实现两个数的交换
 * **********************************************/
void swap(int *a,int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}


/* ************************************************
 *函数功能：画一条任意角度的线
 *算法名称：Bresenham算法 
 *函数描述：
 *
 * ************************************************/
int fb_line(int x1,int y1,int x2,int y2,u32_t color)
{
    
    int dx = x2 - x1;
    int dy = y2 - y1;
    int inc = (dx*dy) > 0 ? 1 : -1 ;
    int p =0;
    if(abs(dx) > abs(dy))
    {
        if(dx < 0)
        {
           swap(&x1,&x2);
           swap(&y1,&y2);
           dx = -dx;
           dy = -dy;
        }
        dy = abs(dy);
        p =2*dy-dx;
        while(x1 <= x2)
        {
            fb_one_pixel(x1,y1,color);
            x1++;
            if(p<0)
            {
                p += 2*dy;
            }
            else
            {
                y1 = y1 + inc;
                p += 2*(dy-dx);
            }
        }
    }
    else
    {
    
        if(dy < 0)
        {
           swap(&x1,&x2);
           swap(&y1,&y2);
           dx = -dx;
           dy = -dy;
        }
        dx = abs(dx);
        p =2*dx-dy;
        while(y1 <= y2)
        {
            fb_one_pixel(x1,y1,color);
            y1++;
            if(p<0)
            {
                p += 2*dx;
            }
            else
            {
                x1 = x1 + inc;
                p += 2*(dx-dy);
            }
        }
    }
    return 0;
}

/**************************************************
 * 函数功能：画一个圆
 * 算法名称：Bresenham算法
 ****************************************************/
int fb_circle(int x0,int y0,int r,u32_t color)
{
   int x = 0;
   int y = r;
   int p = 3 - 2*r ;
   while(x <= y)
   {

   /*下面划的是一空心圆*/
      fb_one_pixel(x0+x,y0+y,color);
      fb_one_pixel(x0+y,y0+x,color);

      fb_one_pixel(x0+x,y0-y,color);
      fb_one_pixel(x0+y,y0-x,color);

      fb_one_pixel(x0-x,y0+y,color);
      fb_one_pixel(x0-y,y0+x,color);

      fb_one_pixel(x0-x,y0-y,color);
      fb_one_pixel(x0-y,y0-x,color);

   /*下面划的是个实心圆*/

      fb_line(x0+x,y0+y,x0-x,y0+y,color);
      fb_line(x0+y,y0+x,x0-y,y0+x,color);
      fb_line(x0+x,y0-y,x0-x,y0-y,color);
      fb_line(x0+y,y0-x,x0-y,y0-x,color);
      
      if(p < 0)
      {
        p += 4*x+6;
      }
      else
      {
        p += 4*(x-y)+10;
        y--;
      }
      x++;

   }
   return 0;
}

