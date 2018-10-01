#include <stdio.h>

int sum(int n){
  int i,sum=0;

  for(i = 1;i<=n;i++){
    sum += i;
  }
  return sum;
}

int main(int argc, char const *argv[]) {
  printf("%d\n",sum(10));
  return 0;
}
