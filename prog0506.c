/* prog0506.c */
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define N 100000

struct POINT2D_EX  {
  double x;
  double y;
  double dist;
};

void read_point(struct POINT2D_EX po[]) {
	  /* 演習課題1で作成 */
     FILE *fp;
  int i;
  if((fp=fopen("data2.txt","r"))==NULL){
    printf("\n");
    exit(1);
  }
	for (i = 0; i < N; i++) {
    fscanf(fp,"%lf %lf",&po[i].x,&po[i].y);
  }
}

void calc_dist(struct POINT2D_EX pt, struct POINT2D_EX po[]) {
   /* この部分を作成*/
   int i;
   double d;
   for(i=0;i < N;i++){
      d = sqrt((pt.x-po[i].x)*(pt.x-po[i].x)+(pt.y-po[i].y)*(pt.y-po[i].y));
      po[i].dist = d;
   }
	
}

void sort_point(struct POINT2D_EX po[], int left, int right)  {
	/* この部分を作成*/
	int i,j;
  double pivot;
  struct POINT2D_EX tmp;

  if(left >= right){
    return;
  }
  i = left;
  j = right;

  pivot = po[(i+j)/2].dist;

  while(1){
    while(pivot > po[i].dist){
      i++;
    }
    while(pivot < po[j].dist){
      j--;
    }
    if(i >= j)
      break;
    tmp = po[i];
    po[i] = po[j];
    po[j] = tmp;
    i++;
    j--;
  }
	sort_point(po,left,i-1);
  sort_point(po,j+1,right);
}


int main(void) {
  struct POINT2D_EX pt[N];
  struct POINT2D_EX ref_p;

  read_point(pt);

  printf("基準点のx座標とy座標を入力: ");
	/* この部分を作成 */
	scanf("%lf %lf",&ref_p.x,&ref_p.y);

  calc_dist(ref_p,pt);
  sort_point(pt,0,N-1);

  printf("最初の座標 x=%.5f y=%.5f\n",pt[0].x,pt[0].y);
  printf("最後の座標 x=%.5f y=%.5f\n",pt[N-1].x,pt[N-1].y);
  printf("N/2番目の座標 x=%.5f y=%.5f\n",pt[N/2-1].x,pt[N/2-1].y);

  return 0;
}
