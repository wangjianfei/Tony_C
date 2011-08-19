/* open(path , mode)  path:是指文件的路径
 * mode是文件的模式，分三种：可读 、可写 、可读可写  在函数说明中有具体的宏定义
 * 属于#include <fcntl.h>
 * ioctl(int fb, int request, &fb_var) fb是指文件的类型描述 request 是给出你要      求的 所输出的内容（fb中有很多内容 只输出你想要的）  fb_war 是你输出内容的
 *  格式 ，并把内容传给fb_var
 *  mmap(void *addr, size_t length, int prot, int flags,int fd, off_t offset)
 *  是一个分配显存的函数 ，申请分配一块显存  addr是显存开始的地址，一般为NULL，
 *  由系统来给 length 是显存的大小 以字节为单位  port定义显存的形式 是可读可写
 *  flag是显存的性质  一般都写为：MAP_SHARED  fd是和那个文件映射  offset是是从哪 *   里开始 
 *memset(fb_v.memo,0,fb_v.w*fb_v.h*fb_v.bpp/8)是清屏的函数，填满fb_v.mome为开
 *  始地址的fb_v.w*fb_v.h*fb_v.bpp/8多个字节  用‘0’填满
 *
 * */
#include <stdio.h>
#include "func.h"
#include <stdlib.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <linux/fb.h>
#include <string.h>
#include <sys/mman.h>


fbscr_t fb_v;
int mx;
int my;

int player;
u32_t current_color;
char chess_board[X_NUM*Y_NUM];


int init_data(void)
{
  int fb = 0;
  
  struct fb_var_screeninfo fb_var;  //结构体在：
  fb = open("/dev/fb0" , O_RDWR);
  if(fb == -1)
  {
      perror("open_fb0");
      exit(0);
  }
  if(ioctl(fb ,FBIOGET_VSCREENINFO ,&fb_var) == -1)
  {
     perror("ioctl");
     exit(0);
  }
//  printf("%d\t%d\t%d\n" , fb_var.xres ,fb_var.yres ,fb_var.bits_per_pixel);
  fb_v.w = fb_var.xres;
  fb_v.h = fb_var.yres;
  fb_v.bpp = fb_var.bits_per_pixel;

  fb_v.memo = mmap(NULL,fb_v.w*fb_v.h*fb_v.bpp/8,PROT_READ|PROT_WRITE,MAP_SHARED ,fb,0);
  if(fb_v.memo == MAP_FAILED)
  {
      perror("map");
      exit(0);
  }
  memset(fb_v.memo,0,fb_v.w*fb_v.h*fb_v.bpp/8);//清屏的作用
  memset(chess_board,0,X_NUM*Y_NUM);
  player = 1;
  current_color = BLACK;
/*  int i = 0; 
  u32_t *p = fb_v.memo;
    
  for(i = 10*fb_v.w;i < fb_v.w*fb_v.h*fb_v.bpp/8;i = i+64)
  {
     p[i] = 0x0000ff00;
  }
 //  while(1);*/
  return 0;
}











