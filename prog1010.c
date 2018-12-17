/* prog1010.c */

#include <stdio.h>
#include <stdlib.h>

#define SIZE 10000000

int main(int argc, char *argv[])
{
    int *heap_int;
    int i;

    heap_int = (int *)malloc(sizeof(int) * SIZE);
    for (i=0; i<SIZE; ++i) {
        heap_int[i] = i;
    }
    printf("heap: %p-%p (%d)\n", 
        heap_int, heap_int+(SIZE-1), SIZE);

    return 0;
}

