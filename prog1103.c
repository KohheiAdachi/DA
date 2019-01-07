/* prog1103.c */

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
  if(top == NULL){
    top = (struct LIST *)malloc(sizeof(struct LIST));
    top->data = n;
    top->next = NULL;
  }
  else{
    struct LIST *p;
    p = (struct LIST *)malloc(sizeof(struct LIST));
    p->data = n;
    p->next = top;
    top = p;
  }
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
  add(10);
  add(20);
  add(30);

  print();
  return 0;
}
