/* prog0602.c */

#include <stdio.h>

int linear_search2(int key, int data[], int n)
{
    int i;
    // 末尾にkeyを追加
    data[n] = key;
    //配列の先頭から順番にキーの値の要素を探す
    for( i=0 ; data[i] != key ; i++ ){
    }
    // キーが見つかった位置が前であれば、その値を返す
    if( i != n )
        return i;
    return -1;
}

int main(void)
{
    // 番兵ありなので１つ多く配列を用意する
    int data[11] = {4,1,2,7,9,5,3,8,6,10};
    int x, found;
    scanf("%d", &x);
    found = linear_search2(x, data, 10);
    if( found >= 0 ){
        printf("Found %d at data[%d]\n", x, found);
    } else {
        printf("Not found %d\n", x);
    }
    return 0;
}
