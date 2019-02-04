#include <stdio.h>

struct BITMAP {
  int bitmap[4][4];
};

void display(struct BITMAP *p)
{
  int i, j;
  for( i=0 ; i<4 ; i++ ){
    for( j=0 ; j<4 ; j++ ){
      printf("%d", p->bitmap[i][j]);
    }
    printf("\n");
  }
  printf("\n");
}

void rotate(struct BITMAP *p)
{
  int i, j;
  struct BITMAP b;
  for( i=0 ; i<4 ; i++ ){
    for( j=0 ; j<4 ; j++ ){
      b.bitmap[j][3-i] = p->bitmap[i][j];
    }
  }
  *p = b;
}

int main(void)
{
  struct BITMAP bitmap = {
    {{0,1,0,0},{0,1,1,0},{0,1,0,0},{0,0,0,0}}
  };

  display(&bitmap);
  rotate(&bitmap);
  display(&bitmap);
}
    
