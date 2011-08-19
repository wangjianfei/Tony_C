/* 在五子棋项目中：
 * ctr Alt f1  是从bash -----> 文本界面
 * Atl f7      文本界面------->bash
 * /dev/fb0  dev 是设备文件 fb0 是里面含有屏幕设置的文件
 *
 * */
#include <stdio.h>
#include "func.h"
#include "various.h"
#include <unistd.h>  //sleep() 是秒
                     //usleep()是微秒
int main(int argc, const char *argv[])
{
    init_data();
  //  int i =0;
  //  int j =0;
/*    for(j = 0;j < 100;j++)
    {
       for(i = 0;i < 100;i++)
       {
       fb_one_pixel(500+i,300+j,0x0000ff00);
       }
    }*/
   // fb_line(0,0,fb_v.w-1,fb_v.h-1,0x0000ff00);
   // fb_line(fb_v.w-1 ,0,0,fb_v.h-1,0x0000ff00); 
//    fb_circle(500,300,150,0x0000ff00);
/*    int i = 0;
    for(i = 24;i < fb_v.h-23;i=i+30)
    {
        fb_line(0,i,1023,i,0x0000ff00);
    }
    for(i = 32;i < fb_v.w-31;i=i+30)
    {
      fb_line(i,0,i,767,0x0000ff00);
    }*/
/*    printf_board();
    fb_circle(300+32,150+24,5,0x00ff0000);
    fb_circle(270+32,120+24,5,0);
    fb_circle(240+32,120+24,5,0);
    fb_circle(210+32,120+24,5,0);
    fb_circle(180+32,120+24,5,0);
    fb_circle(300+32,120+24,5,0);
    save_background(512,338);
    draw_cursor(512,338);
//    sleep(2);
//    getchar();
    int i = 0;
    int j = 0;
    for(i = 0 ;i < 10000;i++)
    {
        for (j = 0; j < 10000; j++)
        {
            ;
        }
    }
    restore_background(512,338);
    draw_cursor(700,338);*/
//    while(1);
    
    printf_board();
    mouse_doing();
    return 0;
}

