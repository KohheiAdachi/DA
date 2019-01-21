/* prog1301.c */
#include <stdio.h>
#include <stdlib.h>

struct TREE {
  int data;
  struct TREE *left;
  struct TREE *right;
};
struct TREE *root = NULL;

void add_tree(int data)
{
  struct TREE *p;
  p = (struct TREE *)malloc(sizeof(struct TREE));
  p->data = data;
  p->left = NULL;
  p->right = NULL;
  if( root == NULL ){
    root = p;
  } else {
    struct TREE *node = root;
    while( node != NULL ){
      if( data < node->data ){　//左側に格納すべき場所がある
        if( node->left == NULL ){
          node->left = p;
          return;
        } else {　//左下に先がある場合
          node = node->left;
        }
      } else { /* data > node-> data */　//右側に格納すべき場所がある
        if( node->right == NULL ){
          node->right = p;
          return;
        } else {
          node = node->right;
        }
      }
    }
  }
}

int main(void)
{
  add_tree(7);
  add_tree(3);
  add_tree(9);
  add_tree(4);
  add_tree(5);
  add_tree(8);

  return 0;
}
