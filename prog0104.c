/* prog0104.c */

#include <stdio.h>

int main(void)
{
    int a, b, n, r;

    scanf("%d%d", &a, &b);

    if (a <= b){
      r = a; a = b; a = r;
    }

    /* a と b の公約数を求めて n に代入するプログラムを記述 */
    while(b != 0){
      r = a % b;
      a = b;
      b = r;
    }
    n = a;


    printf("%d\n", n);

    return 0;
}
