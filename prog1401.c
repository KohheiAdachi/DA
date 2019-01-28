/* prog1401.c */
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

int search_max(struct TREE *tree)
{
  // if(tree == NULL){
  //   return 0;
  // }
  // if (tree->right != NULL){
  //   return search_max(tree->right);
  // }
  // else{
  //   return tree->data;
  // }
  struct TREE *p = tree;
  while(p != NULL){
    if(p->right == NULL){
      return p->data;
    } else{
      p = p->right;
    }
  }
  return 0;
}

void delete_node(int n, struct TREE **tree)
{
  struct TREE **p = tree;
  while(*p != NULL) {
    if( (*p)->data == n ){
      struct TREE *delete =*p;
      if(((*p)->left == NULL) && ((*p)->right == NULL)) {
        *p = NULL;
        free(delete);
      } else if ((*p)->left == NULL) {
        *p = (*p)->right;
        free(delete);
      } else if ((*p)->right == NULL) {
        *p = (*p)->left;
        free(delete);
      } else {
        int max = search_max((*p)->left);
        delete_node(max, p);
        (*p)->data = max;
      }
      return;
    } else if( n < (*p)->data ) {
      p = &((*p)->left);
    } else { /* n > p->data */
      p = &((*p)->right);
    }
  }
}


void print_tree(struct TREE *p)
{
  if( p != NULL ){
    print_tree(p->left);
    printf("%d ", p->data);
    print_tree(p->right);
  }
}

void display_tree(struct TREE *node)
{
  static int depth = 0;

  printf("%*s", depth+3, "-");
  printf("{\"%d\"}\n", node->data);

  if (node->left != NULL) {
    depth++;
    display_tree(node->left);
    depth--;
  }

  if (node->right != NULL) {
    depth++;
    display_tree(node->right);
    depth--;
  }
}

int main(void)
{
  int n;
  init();
  add_tree(7);
  add_tree(3);
  add_tree(9);
  add_tree(4);
  add_tree(5);
  add_tree(8);

  display_tree(root);

  printf("Input n: ");
  scanf("%d", &n);
  delete_node(n, &root);
  display_tree(root);

  print_tree(root);
  printf("\n");
  show_tree(root);
  return 0;
}
