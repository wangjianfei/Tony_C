#ifndef _FUNC_H_
#define _FUNC_H_

typedef unsigned char u8_t;
typedef unsigned int u32_t;


#define ST_X 100
#define ST_Y 40
#define X_NUM 29
#define Y_NUM 24
#define SPACE 30

#define BLACK 0
#define WHITE 0X00ffffff

typedef struct   //注意这种定义结构体的形式 是一种固定格式  记住即可
{
     int w;
    int h;
    int bpp;
    void *memo;//泛型指针，可以指向任何类型的指针
}fbscr_t;


typedef struct
{
    int dx;
    int dy;
    int button;
}mouse_event;

int init_data(void);
int fb_one_pixel(int x,int y,u32_t color);
int fb_line(int,int,int,int,u32_t);
void swap(int *a,int *b);

int fb_circle(int x0,int y0,int r,u32_t color);
void printf_board(void);
int draw_cursor(int x ,int y);
int save_background(int x,int y);
int restore_background(int x,int y);
int mouse_doing(void);
int get_mouse_info(int fb,mouse_event *p);
int chess_doing(void);
int chess_put(int x,int y);
#endif

