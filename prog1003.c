/* prog1003.c */

#include <stdio.h>

struct DATA {
    int x, y;
};

void output(struct DATA *p)
{
    printf("x=%d, y=%d\n", p->x, p->y);
}

int main(void)
{
    struct DATA a;
    struct DATA *p;

    p = &a;
    p->x = 3;
    p->y = 5;
    output(p);

    return 0;
}

