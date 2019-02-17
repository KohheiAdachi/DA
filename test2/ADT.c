#include <stdio.h>

typedef struct{
    int x,y;
} some_t;

some_t g(some_t p,some_t *q){
    p.x = p.x + p.y;
    q->x = q->x + q->y;
    return p;
}

int main(int argc, char const *argv[])
{
    some_t a,b,c;

    a.x = 5; a.y = 3;
    b.x = 20; b.y = 10;

    c = g(b,&a);
    // 8 20 30
    printf("%d %d %d\n",a.x,b.x,c.x);

    c = g(a,&b);
    // 8 30 11
    printf("%d %d %d\n",a.x,b.x,c.x);
    return 0;
}
