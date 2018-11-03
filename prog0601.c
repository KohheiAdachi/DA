/* prog0601.c */

#include <stdio.h>

int linear_search(int key, int data[], int n)
{
    int i;
    for( i=0 ; i<n ; i++ ){
        if( data[i] == key ){
            return i;
        }
    }
    return -1;
}

int main(void)
{
    int data[10] = {4,1,2,7,9,5,3,8,6,10};
    int x, found;
    scanf("%d", &x);
    found = linear_search(x, data, 10);
    if( found >= 0 ){
        printf("Found %d at data[%d]\n", x, found);
    } else {
        printf("Not found %d\n", x);
    }
    return 0;
}
