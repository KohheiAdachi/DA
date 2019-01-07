/* prog1202.c */

#include <stdio.h>
#include <stdlib.h>

struct LIST {
  int data;
  struct LIST *next;
};

int count;
struct LIST *top;

void init(void)
{
  top = NULL;
  count = 0;
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

struct LIST *search(int n)
{
  struct LIST *p = top;
  while( p != NULL ){
    if( p->data == n ){
      return p;
    }
    p = p->next;
  }
  return NULL;
}

void delete(struct LIST *delete)
{
  
  if (top == delete){
    top = delete->next;
  }
  else{
    struct LIST *temp = top;;
    while(temp->next!=delete){
      temp=temp->next;
    }
    temp->next = delete->next;
  }
  free(delete);

}

void push(int n)
{
  struct LIST *p;
  p = (struct LIST *)malloc(sizeof(struct LIST));
  p->data = n;
  p->next = top;
  top = p;
  count++;
}

int pop(void)
{
  struct LIST *find;
  find = search(top->data);
  int n = top->data;
  delete(find);
  count--;
  return n;
}

int size(void)
{
  return count;
}

int main(void)
{
  init();
  push(3);
  push(5);
  push(7);
  push(9);
  while( size() > 0 ){
    int x = pop();
    printf("%d\n", x);
  }
  return 0;
}
