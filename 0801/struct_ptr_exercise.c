#include <stdio.h>

struct date
{
   int a ;
   int b ;
   char  c ;
   char d ;
   struct date *ptr ;
};

typedef struct date date;

int main(int argc, const char *argv[])
{
    date m = {5,10,20,30};
    date n = {1, 2, 3, 4};
    date *p = &m ;

   /* printf("%d\n" , sizeof(date));
    printf("%d\n" ,m.a);
    printf("%d\n" ,(*p).a);
    printf("%d\n" ,p -> a);
    printf("%d\n" ,m.b);
    printf("%d\n" ,(*p).b);
    printf("%d\n" ,p -> b);
    printf("%d\n" ,m.c);
    printf("%d\n" ,(*p).c);
    printf("%d\n" ,p -> c);
    printf("%d\n" ,m.d);
    printf("%d\n" ,(*p).d);
    printf("%d\n" ,p -> d);*/
    p -> ptr = &n;
    printf("%d\n" ,p -> ptr ->a );
    printf("%d\n" ,p -> ptr ->b );
    printf("%d\n" ,p -> ptr ->c );
    printf("%d\n" ,p -> ptr ->d );
    printf("%d\n" ,p -> a);
    printf("%d\n" ,p -> b);
    printf("%d\n" ,p -> c);
    printf("%d\n" ,p -> d);
    return 0;
}

