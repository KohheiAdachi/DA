/* prog0501.c */
#include<stdio.h>

struct POINT2D_EX  {
  double x;
  double y;
  double dist;
};

int main(void) {
  struct POINT2D_EX pt;

  printf("xとyを入力: ");
  scanf("%lf %lf",&pt.x, &pt.y);

  printf("x=%.5f y=%.5f\n",pt.x,pt.y);
  
  return 0;
}
