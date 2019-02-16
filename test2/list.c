#include <stdio.h>
#include <stdlib.h>

typedef struct nd
{
    int val;
    struct nd *next;
} node;

node *cons(int a,node *b){
    node *p = (node *)malloc(sizeof(node));
    p->val = a;
    p->next = b;
    return p;
}


//先頭を頭に逆順に印字する関数
void printR(node *node){
    if (node != NULL) {
      printR(node->next);
      printf("%d",node->val);  
    }    
}

//第1引数で与えたリストを末尾に第2引数で与えた値をval値とするノードを追加してできたリストを返す関数
node *append(node *p,int val){
    if(p == NULL){
        return cons(val,NULL);
    }
    else{
        p->next = append(p->next,val);
        return p;
    }
}

int getmax(node *p){
    int max;
    if (p == NULL) {
        return 0;
    }
    else{
        max = getmax(p->next);
        if(p->val > max)
            return p->val;
        else
            return max;
    }
}

node *delete(node *p,int x){
    node *q;
    if(p==NULL){
        return NULL;
    }
    else if(p->val == x){
        q = p->next;
        free(p);
        return delete(q,x);
    }
    else{
        p->next = delete(p->next,x);
        return p;
    }
}

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
