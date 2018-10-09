/* prog0205.c */

#include <stdio.h>

struct COMP {
    double re, im;
};


/* 構造体COMP型で表された複素数の値を表示する関数 */
void print_comp(struct COMP c)
{
    printf("%.1f",c.re);
    if(c.im>=0){
    printf("+");
  }
    printf("%.1fi\n",c.im);
}


/* 複素数の足し算を計算する関数 */
struct COMP add_comp(struct COMP c1, struct COMP c2)
{
    struct COMP c = { 0.0, 0.0 };
    c.re = c1.re + c2.re;
    c.im = c1.im + c2.im;
    return  c;
}


/* 複素数の掛け算を計算する関数 */
struct COMP mult_comp(struct COMP c1, struct COMP c2)
{
    struct COMP c = { 0.0, 0.0 };

    c.re = c1.re*c2.re - c1.im*c2.im;
    c.im = c1.re*c2.im + c1.im*c2.re;

    return  c;
}


int main(void)
{
    struct COMP c1 = {0.0, 3.0};
    struct COMP c2 = {4.0, 0.0};
    struct COMP c3 = {0.0, 0.0};
    struct COMP c4 = {4.0, 3.0};
    struct COMP c5 = {4.0,-3.0};
    struct COMP c6 = {4.0, 1.0};
    struct COMP c7 = {4.0,-1.0};

    print_comp(c1);
    print_comp(c2);
    print_comp(c3);
    print_comp(c4);
    print_comp(c5);
    print_comp(c6);
    print_comp(c7);

    print_comp( add_comp( c1, c7 ) );
    print_comp( mult_comp( c5, c6 ) );

    return 0;
}
