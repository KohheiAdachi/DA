/* prog0801.c */

#include <stdio.h>

#define STACK_SIZE 100

int sp;
int stack[STACK_SIZE];

void init(void)
{
  sp = 0;
}

void push(int data)
{
  stack[sp] = data;
  sp++;
}

int pop(void)
{
  sp--;
  return stack[sp];	
}

int size(void)
{
  return sp;
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
