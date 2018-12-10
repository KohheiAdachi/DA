/* prog0906.c */

#include <stdio.h>

void swap(int *x, int *y)
{
  int tmp;
  tmp = *y;
  *y = *x;
  *x = tmp; 
}

int main(void)
{
  int x = 3;
  int y = 5;

  printf("x=%d, y=%d\n", x, y);
  printf("swap\n");
  swap(&x, &y);
  printf("x=%d, y=%d\n", x, y);

  return 0;
}
