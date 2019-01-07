/* prog1201.c */

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

int main(void)
{
  int key;
  struct LIST *find;

  init();
  add(2);    add(3);    add(5);    add(7);
  add(11);   add(13);   add(17);   add(19);

  print();

  printf("delete=");
  scanf("%d", &key);
  find = search(key);
  if( find != NULL ){
    delete(find);
  } else {
    printf("not found\n");
  }

  print();
  return 0;
}
