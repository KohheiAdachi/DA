/* prog0403.c */

#include <stdio.h>

void print_array(int data[], int n)
{
    int i;
    for( i=0 ; i<n ; i++ )
        printf( "%d ", data[i] );
    printf( "\n" );
}

void quick_sort(int data[], int left, int right)
{
    int i, j,pivot,tmp;

    if( left >= right )
        return;
    i = left;
    j = right;
    pivot = data[ (i+j)/2 ];
    printf("pivot = %d\n",pivot);

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
        // printf("i=%d\n",i);
        // printf("j=%d\n",j);
    }
    print_array(data,8);
    printf("i=%d\n",i);
    printf("j=%d\n",j);
    quick_sort(data, left, i-1);
    printf("q_sort:%d,%d\n",j+1,right);
    quick_sort(data, j+1, right);
}

int main(void)
{
    int i;
    // int data[15] = {6,3,1,5,7,3,4,9,2,8,0,2,8,5,1};
    int data[8] = { 4, 2, 7, 8, 1, 3, 6, 5 };
    quick_sort(data, 0, 7);

    for( i=0; i<7; i++ )
	    printf("%d ", data[i]);

    return 0;
}
