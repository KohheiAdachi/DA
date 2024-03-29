/* prog1102.c */

#include <stdio.h>
#include <stdlib.h>

struct LIST {
  int data;
  struct LIST *next;
};
struct LIST *top;

void init(void)
{
  top = NULL;
}

void add(int n)
{
  struct LIST *p;
  p = (struct LIST *)malloc(sizeof(struct LIST));
  p->data = n;
  p->next = top;
  top = p;
}

void print(void)
{
  struct LIST *p = top;
  while( p != NULL ){
    printf("%d ", p->data);
    p = p->next;
  }
  printf("\n");
}

int main(void)
{
  init();
  add(2);    add(3);    add(5);    add(7);
  add(11);   add(13);   add(17);   add(19);

  print();

  return 0;
}
