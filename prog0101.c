#include "stdio.h"


int main(void) {

  int i;
  int sum=0;
  int s = 0;
  for (i = 1; i < 10000; i++){
    if (i%7==0){
      sum += i;
    }
  }
  for(i = 7;i<10000; i+=7){
    s = s + i;
  }

  printf("%d\n",s);
  printf("%d\n",sum);
  return 0;
}
