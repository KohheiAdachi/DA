/* prog1104.c */

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

struct LIST *search(int n)
{
  struct LIST *p = top;
  while(p != NULL){
    if(p->data == n){
      return p;
    }
    p = p->next;
  }
  return NULL;
}

int main(void)
{
  int key;
  struct LIST *find;

  init();
  add(2);    add(3);    add(5);    add(7);
  add(11);   add(13);   add(17);   add(19);

	print();
  printf("search=");
  scanf("%d", &key);

  find = search(key);
  if( find != NULL ){
    printf("found %d\n", find->data);
  } else {
    printf("not found\n");
  }

  return 0;
}
