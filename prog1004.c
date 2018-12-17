/* prog1004.c */

#include <stdio.h>

int a = 0;

int func(int b)
{
    static int c=0;
    int d=0;
    a += b;
    c += b;
    d += b;
    return d;
}

int main(void)
{
    int e;
    e = func(1);
    e = func(1);
    return 0;
}

