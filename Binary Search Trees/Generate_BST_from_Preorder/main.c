#include <stdio.h>
#include <stdlib.h>

struct Node {
    struct Node* lchild;
    int data;
    struct Node* rchild;
}*root = NULL;

struct Stack {
    int top;
    struct Node **s;
    int size;    
};

void createStack(struct Stack *stk, int size) {
    stk -> size = size;
    stk -> s = (struct Node **)malloc(stk -> size * sizeof(struct Node));
    stk -> top = -1;
}

void push(struct Stack *stk, struct Node *x) {
    if(stk -> top == stk -> size - 1) {
        printf("Stack Overflow\n");
    } else {
        stk -> top++;
        stk -> s[stk -> top] = x;
    }
}

struct Node *pop(struct Stack *stk) {
    struct Node *x;
    if(stk -> top == -1) {
        printf("Stack Underflow\n");
    } else {
        x = stk -> s[stk -> top--];
    }
    return x;
}

struct Node *stackTop(struct Stack stk) {
    if(stk.top == -1) {
        return NULL;
    } else {
        return stk.s[stk.top];
    }
}

void Inorder(struct Node *p) {
    if(p) {
        Inorder(p -> lchild);
        printf("%d ", p -> data);
        Inorder(p -> rchild);
    }
}

void createPre(int pre[], int n) {
    struct Stack stk;
    createStack(&stk, 50);
    struct Node *t, *p;
    int i = 0;
    root = (struct Node *)malloc(sizeof(struct Node));
    root -> data = pre[i++];
    root -> lchild = root -> rchild = NULL;
    p = root;
    
    while(i < n) {
        if(pre[i] < p -> data) {
            t = (struct Node *)malloc(sizeof(struct Node));
            t -> data = pre[i++];
            t -> lchild = t -> rchild = NULL;
            p -> lchild = t;
            push(&stk, p);
            p = t;
        } else {
            if(pre[i] > p -> data && (!stackTop(stk) || pre[i] < stackTop(stk) -> data)) {
                t = (struct Node *)malloc(sizeof(struct Node));
                t -> data = pre[i++];
                t -> lchild = t -> rchild = NULL;
                p -> rchild = t;
                p = t;
            } else {
                p = pop(&stk);
            }
        }
    }
    free(stk.s);
}

int main() {
    
	int pre[]={30,20,10,25,40,35,45,42,43};
    createPre(pre,9);
    Inorder(root);
	return 0;
}