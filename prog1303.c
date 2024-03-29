/* prog1303.c */
#include <stdio.h>
#include <stdlib.h>

struct TREE {
  int data;
  struct TREE *left;
  struct TREE *right;
};
struct TREE *root;

void init(void)
{
  root = NULL;
}

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
      if( data < node->data ){
				if( node->left == NULL ){
					node->left = p;
					return;
				} else {
					node = node->left;
				}
      } else {
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

struct TREE *search_tree(int n)
{
	struct TREE *p = root;
  
  while(p != NULL) {
    if(n == p->data){
      return p;
    } else if( n < p->data ){
      p = p->left;
    } else{
      p = p->right;
    }
  }
   return NULL;	
}

void display_tree(struct TREE *p)
{
  if(p != NULL){
    display_tree(p->left);
    printf("%d\n",p->data);
    display_tree(p->right);
  }
  // if(p == NULL){
  //   return;
  // }
  // else{
  //   display_tree(p->left);
  //   printf("%d\n",p->data);
  //   display_tree(p->right);
  // }
}

int main(void)
{
  init();
  add_tree(7);
  add_tree(3);
  add_tree(9);
  add_tree(4);
  add_tree(5);
  add_tree(8);
  display_tree(root);

  return 0;
}
