/* prog0502.c */
#include<stdio.h>
#define N 5

struct POINT2D_EX  {
  double x;
  double y;
  double dist;
};

int main(void) {
  int i;
  struct POINT2D_EX pt[N];

  for (i=0; i<N; i++) {
    printf("xとyを入力: ");
    scanf("%lf %lf",&pt[i].x, &pt[i].y);
  }

  for (i=0; i<N; i++) {
    printf("x=%.5f y=%.5f\n",pt[i].x,pt[i].y);
  }
  return 0;
}
