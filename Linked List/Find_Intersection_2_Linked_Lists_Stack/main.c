#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
}*first = NULL, *second = NULL, *third = NULL;

struct Stack {
    int size;
    int top;
    struct Node *s;
}*stk1, *stk2;

void Create(struct Stack *st) {
    printf("Enter size: ");
    scanf("%d", &st -> size);
    st -> top = -1;
    st -> s = (struct Node *)malloc(st -> size * sizeof(struct Node));
}

struct Node* createFirst(int A[], int n) {
    int i;
    struct Node *t = NULL, *last;
    first = (struct Node *)malloc(sizeof(struct Node));
    first -> data = A[0];
    first -> next = NULL;
    last = first;
    for(i = 1; i < n; i++) {
        t = (struct Node *)malloc(sizeof(struct Node));
        t -> data = A[i];
        t -> next = NULL;
        last -> next = t;
        last = t;
    }
    return first;
}

struct Node* createSecond(int A[], int n) {
    int i;
    struct Node *t = NULL, *last;
    second = (struct Node *)malloc(sizeof(struct Node));
    second -> data = A[0];
    second -> next = NULL;
    last = second;
    for(i = 1; i < n; i++) {
        t = (struct Node *)malloc(sizeof(struct Node));
        t -> data = A[i];
        t -> next = NULL;
        last -> next = t;
        last = t;
    }
    return second;
}

void Display(struct Stack st) {
    int i;
    for(i = st.top; i >= 0; i--) {
        printf("%d ", st.s[i].data);
        printf("\n");
    }
}

void push(struct Stack *st, struct Node *p) {
    if(st -> top == st -> size - 1) {
        printf("Stack Overflow\n");
    } else {
        st -> top++;
        st -> s[st -> top].data = p -> data;
    }
}

int pop(struct Stack *st) {
    int x = -1;
    if(st -> top == -1) {
        printf("Stack Underflow\n");
    } else {
        x = st -> s[st -> top--].data;
    }
    return x;
}

int stackTop(struct Stack st) {
    if(st.top != -1) {
        return st.s[st.top].data;
    }
    return -1;
}

int Intersection(struct Node *t1, struct Node *t2) {
    int x = -1;
    struct Node *p = first;
    while(p) {
        push(stk1, p);
        p = p -> next;
    }
    p = second;
    while(p) {
        push(stk2, p);
        p = p -> next;
    }
    while(stackTop(*stk1) == stackTop(*stk2)) {
        x = pop(stk1);
        pop(stk2);
    }
    return x;
}

int main() {
    struct Node *t1, *t2;
    int A[] = {3, 5, 7, 9, 11, 13, 15};
    t1 = createFirst(A, 7);
    
    stk1 = (struct Stack *)malloc(sizeof(struct Stack));
    stk1 -> size = 7;
    stk1 -> top = -1;
    stk1 -> s = (struct Node *)malloc(stk1 -> size * sizeof(struct Node));
    
    int B[] = {4, 5, 7, 11, 11, 13, 15};
    t2 = createSecond(B, 7);
    
    stk2 = (struct Stack *)malloc(sizeof(struct Stack));
    stk2 -> size = 7;
    stk2 -> top = -1;
    stk2 -> s = (struct Node *)malloc(stk2 -> size * sizeof(struct Node));
	
    printf("%d ", Intersection(t1, t2));
	return 0;
}
