#include <stdio.h>
#include "various.h"

/*******************************************************
 *函数功能：检查一个点各个方向是否有五个连续的
 *
 **********************************************************/
int check(int x,int y )
{
    int i = 0;
    int j = 0;
    int who = chess_board[x+y*X_NUM];
    int counter = 1;
    if(who == 0)  //检查该点是否有棋子 ， 没有直接跳出
    {
        return who;
    }
    for(i = 1;i<5;i++)
    {
        if(chess_board[x+i+y*X_NUM] == who)
        {
            counter++;
        }
        else                   //如果有一个不是则直接跳出
        {
            break;
        }
    }
    if(counter == 5)  //判断是否有五个
    {
        return who;
    }
    counter = 1;   //计数后注意清零
    for(i =1,j=-1;i<5;i++,j--)
    {
        
        if(chess_board[x+i+(y+j)*X_NUM] == who)
        {
            counter++;
        }
        else
        {
            break;
        }
    }
    if(counter == 5)
    {
        return who;
    }
    counter = 1;

    for(i =1,j=1;i<5;i++,j++)
    {
        
        if(chess_board[x+i+(y+j)*X_NUM] == who)
        {
            counter++;
        }
        else
        {
            break;
        }
    }
    if(counter == 5)
    {
        return who;
    }

    counter = 1;

    for(j=1;j<5;j++)
    {
        
        if(chess_board[x+(y+j)*X_NUM] == who)
        {
            counter++;
        }
        else
        {
            break;
        }
    }
    if(counter == 5)
    {
        return who;
    }
    return 0;


}

/************************************************************
 * 函数功能：记录该点是否有棋子，同时检查每个点是否满足五个
 *
 *
 ***********************************************************/
int chess_put(int x,int y)
{
     chess_board[x+y*X_NUM] = player;
     int i = 0;
     int j = 0;
     int winner = 0;
     for(j = 0;j < Y_NUM;j++)
     {
        for (i = 0; i < X_NUM; i++)
        {
            if((winner= check(i,j)) > 0)
            {
                return winner;
            }
        }
     }
     return 0;
}



/**********************************************************
 *函数功能：放棋子在棋盘内的交叉点
 *
 *
 ********************************************************/
int chess_doing(void)
{
  /*  int rx = (mx-ST_X)%SPACE;
    int ry = (my-ST_Y)%SPACE;
    int cx = mx - rx;
    int cy = my - ry;*/
    if((mx < ST_X)||(mx > (ST_X + (X_NUM-1)*SPACE))||(my < ST_Y)||(my > (ST_Y + (Y_NUM-1)*SPACE)) )
    {
        return 0;
    }
  /*  if(rx > SPACE/2)
    {
        cx += SPACE;
    }
    if(ry > SPACE/2)
    {
        cy += SPACE;
    }
    fb_circle(cx,cy,8,0x00ff0000);*/
    int rx = (mx+15-ST_X)%SPACE;
    int ry = (my+15-ST_Y)%SPACE;
    int cx = mx+15 - rx;
    int cy = my+15 - ry;
    int flag = 0;
    fb_circle(cx,cy,8,current_color);
     flag =  chess_put((cx-ST_X)/SPACE,(cy-ST_Y)/SPACE);
     if(flag > 0)  // 判断是否有满足五个点
     {
        return flag;
     }
    if(current_color == BLACK)   //放了一个棋子后， 交换棋子的颜色
    {
        current_color = WHITE;
        player = 2;
    }
    else
    {
        current_color = BLACK;
        player = 1;
    }
    return 0;
}
