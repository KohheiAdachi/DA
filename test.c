#include <stdio.h>

int main(int argc, char const *argv[])
{
    
    for(int i = 1; i<=100; i++)
    {
        if (i % 5 ==0){
            printf("Fizz");
        }
        if (i % 3 == 0){
            printf("Buzz");
        }
        if(!(i % 3==0) && !(i %5 == 0)){
            printf("%d",i);
        }

        printf("\n");
    }
    
}
