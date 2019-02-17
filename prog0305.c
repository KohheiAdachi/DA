/* prog0305.c */
#include <stdio.h>


void print_array(int data[], int n)
{
    int i;
    for( i=0 ; i<n ; i++ )
        printf( "%d ", data[i] );
    printf( "\n" );
}


void insersion_sort(int data[], int n)
{
    int i, j, t;
    print_array( data, n );
    for( i=1 ; i<n ; i++ ){
        t = data[i];
        // 一つ前と比べて大小関係を比べる
        if( data[i-1] > t ){
            j = i;
            while( j>0 && data[j-1] > t ){
            data[j] = data[j-1];
            j--;
            print_array( data, n );
            }
        data[j] = t;
        print_array( data, n );
        }
        
    }
}


int main(void)
{
    int array_size = 8;
    int array[] = { 4, 2, 7, 8, 1, 3, 6, 5 };

    insersion_sort( array, array_size );

    return 0;
}
