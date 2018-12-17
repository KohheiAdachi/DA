/* prog1009.c */

#include <stdio.h>

#define SIZE 1000000

int main(int argc, char *argv[])
{
    int auto_int[SIZE];
    int i;

    for (i=0; i<SIZE; ++i) {
        auto_int[i] = i;
    }
    printf("auto: %p-%p (%d)\n",
        auto_int, &auto_int[SIZE-1], SIZE);

    return 0;
}

