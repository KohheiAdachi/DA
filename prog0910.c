/* prog0910.c */

#include <stdio.h>

int main(void)
{
  int x = -1;
  int y = -2;
  int z = -3;
  int *p;

  p = &x;
  *p = 5;
  p = &y;
  *p = 6;
  p = &z;
  *p = 7;

  printf("x=%d, y=%d, z=%d\n", x, y, z);

  return 0;
}
