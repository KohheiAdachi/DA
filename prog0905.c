/* prog0905.c */

#include <stdio.h>

void sum_avg(int a, int b, int *c, int *d)
{
  *c = a + b;
  *d = *c / 2;
}

int main(void)
{
  int x = 3, y = 5;
  int wa = -1, heikin = -1;

  sum_avg(x, y, &wa, &heikin);
  printf("和は %d\n", wa);
  printf("平均は %d\n", heikin);

  return 0;
}
