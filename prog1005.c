/* prog1005.c */

#include <stdio.h>
#include <stdlib.h>

struct DATA {
    int x, y;
};

void output(struct DATA *p)
{
    printf("x=%d, y=%d\n", p->x, p->y);
}

int main(void)
{
    struct DATA *p;

    p = (struct DATA *)malloc(sizeof(struct DATA));
    p->x = 3;
    p->y = 5;
    output(p);
    free(p);

    return 0;
}

