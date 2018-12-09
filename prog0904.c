/* prog0904.c */

#include <stdio.h>

int sum(int a, int b)
{
  return a + b;
}

int main(void)
{
  int x = 3, y = 5;
  int wa = -1;

  wa = sum(x, y);
  printf("和は %d\n", wa);

  return 0;
}
