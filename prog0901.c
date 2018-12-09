/* prog0901.c */

#include <stdio.h>

int sum(int a, int b)
{
  int c = a + b;
  return c;
}

int main(void)
{
  int x = 3, y = 5;
  int wa = -1;

  wa = sum(x, y);
  printf("和は %d\n", wa);

  return 0;
}
