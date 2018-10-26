/* prog0504.c */
#include<stdio.h>
#include<stdlib.h>

struct POINT2D_EX  {
  double x;
  double y;
  double dist;
};

int main(void) {
  FILE *fp;
  struct POINT2D_EX pt;

  if ((fp=fopen("data1.txt","r"))==NULL)  {
    printf("\n");
    exit(1);
  }
  fscanf(fp,"%lf %lf",&pt.x, &pt.y);

  printf("x=%.5f y=%.5f\n",pt.x,pt.y);
  
  return 0;
}
