/* prog0902.c */

#include <stdio.h>

void sum(int a, int b, int c)
{
  c = a + b;
}

int main(void)
{
  int x = 3, y = 5;
  int wa = -1;

  sum(x, y, wa);
  printf("和は %d\n", wa);

  return 0;
}
