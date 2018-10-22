/* prog0403.c */

#include <stdio.h>

void quick_sort(int data[], int left, int right)
{
    int i, j,pivot,tmp;

    if( left >= right )
        return;
    i = left;
    j = right;
    pivot = data[ (i+j)/2 ];


    while( 1 ){
        while( data[i] < pivot )
            i++;
        while( pivot < data[j] )
            j--;
        if( i >= j )
            break;
        tmp = data[i];
        data[i] = data[j];
        data[j] = tmp;
        i++;
        j--;
    }
    quick_sort(data, left, i-1);
    quick_sort(data, j+1, right);
}

int main(void)
{
    int i, data[15] = {6,3,1,5,7,3,4,9,2,8,0,2,8,5,1};

    quick_sort(data, 0, 14);

    for( i=0; i<15; i++ )
	    printf("%d ", data[i]);

    return 0;
}
