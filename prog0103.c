/* prog0103.c */

#include <stdio.h>

int main(int argc, char const *argv[]) {
  int a,b,i,n=0;

  scanf("%d%d",&a,&b);

  /* a と b の公約数を求めて nに代⼊するプログラムを記述 */

  for (i = 1; i <= a; i++) {
  n += b;
  }
  printf("%d\n",n);
  return 0;
}
