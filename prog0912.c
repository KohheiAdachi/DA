/* prog0912.c */

#include <stdio.h>

struct DATA {
  int a1;
  int a2;
  int a3;
};

void output(struct DATA *d)
{
  // printf("(%d,%d,%d)\n", (*d).a1, (*d).a2, (*d).a3);
	printf("(%d,%d,%d)\n", d->a1, d->a2, d->a3); 
}

int main(void)
{
  struct DATA x;
  x.a1 = 5;
  x.a2 = 6;
  x.a3 = 7;

  output(&x);
  return 0;
}
