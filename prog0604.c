/* prog0604.c */

#include <stdio.h>

int binary_search(int key, int data[], int n)
{
    int left = 0, right = n-1, mid;

    while( left <= right ){
        mid = (left+right)/2;
        if( data[mid] == key ) return mid;
        if( data[mid] > key ){
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return -1;
}

int main(void)
{
    int data[10] = {2,3,5,7,11,13,17,19,23,29};
    int x, found;

    scanf("%d", &x);
    found = binary_search(x, data, 10);
    if( found >= 0 ){
        printf("Found %d at data[%d]\n", x, found);
    } else {
        printf("Not found %d\n", x);
    }

    return 0;
}

