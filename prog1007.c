/* prog1007.c */

#include <stdio.h>

#define SIZE 100000000
int global_int[SIZE];

int main(int argc, char *argv[])
{
    int i;

    for (i=0; i<SIZE; ++i) {
        global_int[i] = i;
    }
    printf("global: %p-%p (%d)\n", 
        global_int, &global_int[SIZE-1], SIZE);

    return 0;
}

