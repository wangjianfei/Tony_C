#include <stdio.h>
#include "func.h"
#include "various.h"

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
    fb_line(0,0,fb_v.w-1,fb_v.h-1,0x0000ff00);
    fb_line(fb_v.w-1 ,0,0,fb_v.h-1,0x0000ff00); 
    return 0;
}

