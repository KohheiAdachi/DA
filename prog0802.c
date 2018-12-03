/* prog0802.c */

#include <stdio.h>

#define QUEUE_SIZE 100

int q_entry;
int q_exit;

int queue[QUEUE_SIZE];

void init(void)
{
  q_entry = 0;
  q_exit = 0;
}

void enqueue(int data)
{
  queue[q_entry] = data;
  if(q_entry <= QUEUE_SIZE-1){
    q_entry++;
  } else{
    q_entry = 0;
  }
  
}

int dequeue(void)
{
  int data = queue[q_exit];
  q_exit++;
  if(q_exit >= QUEUE_SIZE-1){
    q_exit= 0;
  }
  return data;
  
}

int size(void)
{
  if (q_entry >= q_exit){
    return q_entry - q_exit;
  } else{
    return QUEUE_SIZE - q_exit + q_entry;
  }
}

int main(void)
{
  init();
  enqueue(3);
  enqueue(5);
  enqueue(7);
  enqueue(9);
  while( size() > 0 ){
    int x = dequeue();
    printf("%d\n", x);
  }
  return 0;
}
