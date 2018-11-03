/* prog0603.c */

#include <stdio.h>

struct PRICE {
    int code;
    char *name;
    int price;
};

int linear_search(int key, struct PRICE data[], int n)
{
    int i;
    data[n].code = key;
    for( i=0; data[i].code != key; i++){     
    }
    if( i != n )
        return i;
    return -1;
}

int main(void)
{
    struct PRICE data[8] = {
        {1000, "りんご", 120},
        {1001, "メロン", 500},
        {1002, "みかん", 90},
        {1003, "キウィ", 140},
        {1004, "ぶどう", 190},
        {1005, "スイカ", 700},
        {1006, "イチゴ", 300},
        {1007, "さくらんぼ", 250}
    };
    int x, found;

    scanf("%d", &x);
    found = linear_search(x, data, 8);
    if( found >= 0 ){
        printf("%s は %d 円です\n", data[found].name, data[found].price);
    } else {
        printf("%d は見つかりませんでした\n", x);
    }
    return 0;
}
