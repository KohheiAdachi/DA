/* prog1006.c */

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int *p1;
    
    p1 = (int *)malloc(sizeof(int));

    *p1 = 5;
    printf("%p\n",p1);
    printf("%d\n",*p1);

    free(p1);

    return 0;
}

