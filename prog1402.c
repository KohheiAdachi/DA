/* prog1402.c */
#include <stdio.h>
#include <stdlib.h>

struct TREE {
  int data;
  struct TREE *left;
  struct TREE *right;
};
struct TREE *root;

#define QUEUE_SIZE 100

int q_entry;
int q_exit;

struct TREE* queue[QUEUE_SIZE];

void enqueue(struct TREE* data)
{
  queue[q_entry] = data;
  q_entry++;
  if( q_entry >= QUEUE_SIZE ){
    q_entry = 0;
  }
}

struct TREE *dequeue(void)
{
  struct TREE* data = queue[q_exit];
  q_exit++;
  if( q_exit >= QUEUE_SIZE ){
    q_exit = 0;
  }
  return data;
}

int size(void)
{
  if( q_entry >=  q_exit ){
    return q_entry - q_exit;
  } else {
    return QUEUE_SIZE - q_exit + q_entry;
  }
}

int is_empty()
{
	if (q_entry == q_exit) {
		return 1;
	} else {
		return 0;
	}
}

void init(void)
{
  root = NULL;
  q_entry = 0;
  q_exit = 0;
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

void pre_order(struct TREE *p)
{
  if(p != NULL){
    printf("%d ",p->data);
    pre_order(p->left);
    pre_order(p->right);
  }
}

void in_order(struct TREE *p)
{
  if(p != NULL){
    in_order(p->left);
    printf("%d ",p->data);
    in_order(p->right);
  }




}

void post_order(struct TREE *p)
{
  if(p != NULL){
    post_order(p->left);
    post_order(p->right);
    printf("%d ",p->data);
  }





}

void breadth_first(struct TREE *p)
{
  
    enqueue(p);
    while(is_empty()==0){
      struct TREE *node = dequeue();
      if (node != NULL){
        printf("%d ",node->data);
        enqueue(node->left);
        enqueue(node->right);
      }
    }

}

int main(void)
{
  init();
  add_tree(6);
  add_tree(3);
  add_tree(1);
  add_tree(5);
  add_tree(8);
  add_tree(9);

	printf("\n行きがけ順(Pre-order): ");
	pre_order(root);
	printf("\n通りがけ順(In-order): ");
	in_order(root);
	printf("\n帰りがけ順(Post-order): ");
	post_order(root);
	printf("\n幅優先(Breadth-first): ");
	breadth_first(root);

	printf("\n");

  return 0;
}
