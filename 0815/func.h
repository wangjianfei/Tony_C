#ifndef _FUNC_H_
#define _FUNC_H_

typedef unsigned char u8_t;
typedef unsigned int u32_t;

typedef struct   //注意这种定义结构体的形式 是一种固定格式  记住即可
{
     int w;
    int h;
    int bpp;
    void *memo;//泛型指针，可以指向任何类型的指针
}fbscr_t;

int init_data(void);
int fb_one_pixel(int x,int y,u32_t color);
int fb_line(int,int,int,int,u32_t);
void swap(int *a,int *b);
#endif
