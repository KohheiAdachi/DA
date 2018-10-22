/* prog0402.c */

#include <stdio.h>

int fibonacci(int n)
{
    if(n == 1){
      return 1;
    }
    else if(n == 0){
      return 0;
    }
    else{
    return  fibonacci(n-1) + fibonacci(n-2);
  }
}

int main(void)
{
    int i,f,n=30;
    for(i = 0;i<n;i++){
      f = fibonacci(i);
      printf("%d\n",f);
    }
    return 0;
}
