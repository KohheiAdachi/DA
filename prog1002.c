/* prog1002.c */

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

    a.x = 3;
    a.y = 5;
    output(&a);

    return 0;
}

