/* prog0401.c */

#include <stdio.h>

int sum(int n)
{
    if( n==0 ){
        return 0;
    } else {
        return n + sum(n-1);
    }
}

int main(void)
{
    int i, s, n=30;
    for(i=0; i<n; i++)
    {
        s = sum( i );
        printf("%d\n", s);
    }
    return 0;
}
