/* prog0909.c */

#include <stdio.h>

int main(void)
{
  int x = -1;
  int *p;

  p = &x;
  *p = 5;

  printf("xのアドレス=%p\n", &x);
  printf("pのアドレス=%p\n", &p);
  printf("pの値=%p\n", p);
  printf("xの値=%d\n", x);
  return 0;
}
