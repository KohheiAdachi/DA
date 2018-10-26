/* prog0503.c */
#include<stdio.h>
#define N 5

struct POINT2D_EX  {
  double x;
  double y;
  double dist;
};

void input_point(struct POINT2D_EX po[])  {
  int i;

  for (i=0; i<N; i++) {
    printf("xy: ");
    scanf("%lf %lf",&po[i].x, &po[i].y);
  }
}

int main(void) {
  int i;
  struct POINT2D_EX pt[N];

  input_point(pt);
 
  for (i=0; i<N; i++) {
    printf("x=%.5f y=%.5f\n",pt[i].x,pt[i].y);
  }
  return 0;
}
