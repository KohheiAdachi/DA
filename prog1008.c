/* prog1008.c */

#include <stdio.h>

#define SIZE 1000000000

int main(int argc, char *argv[])
{
    static int static_int[SIZE];
    int i;

    for (i=0; i<SIZE; ++i) {
        static_int[i] = i;
    }
    printf("static: %p-%p (%d)\n",
        static_int, &static_int[SIZE-1], SIZE);

    return 0;
}

