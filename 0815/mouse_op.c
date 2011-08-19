#include <stdio.h>
#include "func.h"
#include "various.h"
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>

#define BORD  0x00000fff
#define X___  0x000fffff
#define T___  0x00996633
#define C_W 10
#define C_H 17

/******************************************************
 * 下面是定义了一个数组 是一个鼠标的形状
 *
 * *****************************************************/
static u32_t cursor_pixel[C_W*C_H]=
{
      BORD,T___,T___,T___,T___,T___,T___,T___,T___,T___,
      BORD,BORD,T___,T___,T___,T___,T___,T___,T___,T___,
      BORD,X___,BORD,T___,T___,T___,T___,T___,T___,T___,
      BORD,X___,X___,BORD,T___,T___,T___,T___,T___,T___,
      BORD,X___,X___,X___,BORD,T___,T___,T___,T___,T___,
      BORD,X___,X___,X___,X___,BORD,T___,T___,T___,T___,
      BORD,X___,X___,X___,X___,X___,BORD,T___,T___,T___,
      BORD,X___,X___,X___,X___,X___,X___,BORD,T___,T___,
      BORD,X___,X___,X___,X___,X___,X___,X___,BORD,T___,
      BORD,X___,X___,X___,X___,X___,X___,X___,X___,BORD,
      BORD,X___,X___,X___,X___,X___,BORD,BORD,BORD,BORD,
      BORD,X___,X___,BORD,X___,X___,BORD,T___,T___,T___,
      BORD,X___,BORD,T___,BORD,X___,X___,BORD,T___,T___,
      BORD,BORD,T___,T___,BORD,X___,X___,BORD,T___,T___,
      T___,T___,T___,T___,T___,BORD,X___,X___,BORD,T___,
      T___,T___,T___,T___,T___,BORD,X___,X___,BORD,T___,
      T___,T___,T___,T___,T___,T___,BORD,BORD,T___,T___

};

u32_t background[C_H*C_W] = {0};


/********************************************************
 * 函数功能：点亮一个鼠标
 *
 *
 * **********************************************************/

int draw_cursor(int x,int y)
{
    int i = 0;
    int j = 0;
    save_background(x,y);  //要点亮首先保存
    for(j = 0;j < C_H;j++)
    {
        for(i = 0; i < C_W; i++)
        {
            fb_one_pixel(x+i,y+j,cursor_pixel[i+C_W*j]);
        }
    }
    return 0;
 
}

/************************************************************
 *函数功能：储存鼠标所在位置以前的颜色
 *
 *************************************************************/
int save_background(int x,int y)
{
    int i =0;
    int j =0;
    for(j = 0; j < C_H ;j++)
    {
        for(i = 0;i < C_W; i++)
        {
            background[i+j*C_W] = *((u32_t *)fb_v.memo+x+i+(y+j)*fb_v.w);
        }
    }
    return 0;
}

/***********************************************************
 *函数功能：移开鼠标  让光标所在位置回复以前的状态
 *
 ************************************************************/

int restore_background(int x ,int y)
{

    int i = 0;
    int j = 0;
    for(j = 0;j < C_H;j++)
    {
        for(i = 0; i < C_W; i++)
        {
            fb_one_pixel(x+i,y+j,background[i+C_W*j]);
        }
    }
    return 0;
}
/************************************************************
 *  函数功能：读取信息从fb中，它中包含很多信息，我们只要三个字
 *            节的信息，第一个字节：是判断鼠标的那个键按下（左键
 *            中键 右键），第二个字节:横坐标移动的距离dx；第三个
 *            字节：纵坐标移动的距离dy（对于屏幕，向上为负，向下
 *            为正）
 *注意::::read 和open 不在一个函数库里
          read在#include <unistd.h>
          open在#include <fcntl.h>
 *        不要认为它们在一个库里
 ************************************************************/
int get_mouse_info(int fb,mouse_event *p)
{
    char buf[5];
    int n = 0;
    n =read(fb,buf,3);
    if(n > 0)
    {
        p->dx = buf[1];
        p->dy = buf[2];
        p->button = buf[0] & 0x07;
    }
    return n;
}

int reinit(void)
{
    memset(fb_v.memo,0,fb_v.w*fb_v.h*fb_v.bpp/8);
    printf_board();
    memset(chess_board,0,X_NUM*Y_NUM);
    player = 1;
    current_color = BLACK;

    mx = fb_v.w/2;
    my = fb_v.h/2;
    draw_cursor(mx,my);
    return 0;
}

/**********************************************************
 *函数功能:鼠标的操作
 *
 *************************************************************/

int mouse_doing(void)
{
   int fb =0;
   mouse_event m_e;
   char press_do = 0;
   fb = open("/dev/input/mice" ,O_RDWR|O_NONBLOCK);
   if(fb == -1)
   {
        perror("mice");
        exit(0);
   }
   mx = fb_v.w/2;
   my = fb_v.h/2;
   draw_cursor(mx,my);  //画出鼠标的初始位置
   int winner = 0;
   while(1)
   {
       if( get_mouse_info(fb,&m_e)>0)
       {
            restore_background(mx,my);
            mx += m_e.dx;
            my -= m_e.dy;
            if(mx < 0)
            {
                mx = 0;
            }
            if(mx > fb_v.w-C_W)
            {
                mx = fb_v.w-C_W;
            }

            if(my < 0)
            {
                my = 0;
            }
            if(my > fb_v.h-C_H)
            {
                my = fb_v.h-C_H;
            }
/*            if((mx>=20)&&(mx<=80)&&(my>=180)&&(my<=205))
            {
//                draw_cursor(mx,my);
                while(1)
                {

                  if( get_mouse_info(fb,&m_e)>0)
                 {
                       restore_background(mx,my);
                       mx += m_e.dx;
                        my -= m_e.dy;

                         if(mx < 0)
                         {
                              mx = 0;
                         }
                         if(mx > fb_v.w-C_W)
                         {
                             mx = fb_v.w-C_W;
                         }

                         if(my < 0)
                         {
                             my = 0;
                         }
                         if(my > fb_v.h-C_H)
                         {
                             my = fb_v.h-C_H;
                         }
                  }

                     switch(m_e.button)
                     {
                         case 0:
                             if(press_do == 1)
                             {
                                 press_do = 0;
                                 if((mx>=20)&&(mx<=80)&&(my>=240)&&(my<=265))
                                 {
                                    break;
                                 }

                   // printf("ab\n");
                   // fb_circle(mx,my,5,0x000000ff);
                            }
                             break;
                         case 1:press_do = 1;break;
                    }

                  draw_cursor(mx,my);
            }*/
           switch(m_e.button)
           {
                case 0:
                if(press_do == 1)
                {
                    press_do = 0;
                    winner =  chess_doing();
                   // printf("ab\n");
                   // fb_circle(mx,my,5,0x000000ff);
                }
                break;
                case 1:press_do = 1;break;
                case 2:break;
                case 4:break;
                default:break;
           }
           draw_cursor(mx,my);
           if(winner >  0)
           {
                printf("player %d won!\n",winner);
                winner = 0;
                getchar();
                reinit();
           }
       }
   }
   close(fb);
   return 0;
}

