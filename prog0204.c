/* prog0204.c */

#include <stdio.h>
#include <math.h>

#define N 5

struct POINT2D {
    double x;
    double y;
};

void print_point(struct POINT2D p)
{
    printf("点(%.2f, %.2f)\n", p.x, p.y);
}

/* ここに distance 関数を作成 */
/* ２点 p1, p2 間の距離を計算して、戻り値として返す  */

double distance(struct POINT2D p1,struct POINT2D p2){
  double d;
  d = sqrt((p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y));
  return d;

}



int main(void)
{
    int i;
    struct POINT2D pt[N];
    struct POINT2D zero = {0,0};

    for( i=0; i<N; i++ ){
        printf("x%d=", i);
        scanf("%lf", &pt[i].x);
        printf("y%d=", i);
        scanf("%lf", &pt[i].y);
    }

    printf("入力された全ての点と各点の座標と原点からの距離を表示\n");
    for( i=0; i<N; i++ ){
        print_point(pt[i]);
        printf("距離=%.3f\n", distance(zero, pt[i]));
    }

    printf("原点からの距離が最も遠い点とその距離を表示\n");

    /* 原点からの距離が最も遠い点を求めて、その点の座標と原点からの距離を表示する */
    struct POINT2D maxpt = {0.0,0.0};
    double maxdis=0.0;
    for(i = 0;i < N; i++ ){
      if(maxdis<distance(zero,pt[i])){
        maxpt = pt[i];
        maxdis = distance(zero,pt[i]);
      }
    }
    print_point(maxpt);
    printf("距離=%.3f\n",maxdis);

    return 0;
}
