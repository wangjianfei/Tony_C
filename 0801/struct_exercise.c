#include <stdio.h>

struct date
{
    int  year;
    char month;
    int  x ;
    char  day;
};

int main(int argc, const char *argv[])
{
    typedef struct date  date;
    date m = {11 ,8 , 0 ,1};
    printf("%d \n", sizeof(struct date));
    printf("%d \n", m.year);
    printf("%d \n", m.month);
    printf("%d \n", m.x);
    printf("%d \n", m.day);
    return 0;
}

