#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct Node {
    int data;
    struct Node *next;
}*top = NULL;

struct Stack {
    int size;
    int top;
    struct Node **array;
};

void create(int A[], int n) {
    int i;
    struct Node *t, *bottom;
    top = (struct Node *)malloc(sizeof(struct Node));
    top -> data = A[0];
    top -> next = NULL;
    bottom = top;
    
    for(i = 1; i < n; i++) {
        t = (struct Node *)malloc(sizeof(struct Node));
        t -> data = A[i];
        t -> next = NULL;
        bottom -> next = t;
        bottom = t;
    }
}

void initialize(struct Stack *st, int size) {
    st -> size = size;
    st -> top = -1;
    st -> array = (struct Node **)malloc(size * sizeof(struct Node *));
}

void push(struct Stack *st, struct Node *node) {
    if(st -> top == st -> size - 1) {
        printf("Stack Overflow\n");
    } else {
        st -> array[++st -> top] = node;
    }
}

struct Node* pop(struct Stack *st) {
    if(st -> top == -1) {
        printf("Stack Underflow\n");
        return NULL;
    } else {
        return st -> array[st -> top--];
    }
}

int mid(struct Node *top) {
    struct Node *p = top;
    int len = 0;
    
    while(p) {
        len++;
        p = p -> next;
    }
    
    if(len == 0) {
        printf("Stack is empty\n");
        return -1;
    }
    
    struct Stack st;
    initialize(&st, len);
    
    p = top;
    while(p) {
        push(&st, p);
        p = p -> next;
    }
    
    int midIndex = floor(len / 2.0);
    struct Node *middle = NULL;
    for(int i = 0; i <= midIndex; i++) {
        middle = pop(&st);
    }
    
    free(st.array);
    
    return middle -> data;
}

int main() {
	int A[] = {3, 5, 7, 10, 15, 18, 29};
    create(A, 7);
    
    printf("Middle element of Linked List: %d\n", mid(top));
	return 0;
}