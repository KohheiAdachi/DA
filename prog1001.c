/* prog1001.c */

#include <stdio.h>

int main(void)
{
    int x = -1;
    int *p;

    p = &x;
    *p = 5;

    printf("x=%d\n", x);

    return 0;
}

