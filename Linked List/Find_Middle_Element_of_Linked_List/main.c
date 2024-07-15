#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
}*first = NULL;

void create(int A[], int n) {
    int i;
    struct Node *t, *last;
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
}

void Display(struct Node *p) {
    while(p != NULL) {
        printf("%d ", p -> data);
        p = p -> next;
    }
}

int count(struct Node *p) {
    int l = 0;
    while(p) {
        l++;
        p = p -> next;
    }
    return l;
}

//int findMiddle(struct Node *p) {
//    int i;
//    for(i = 0; i < count(p) / 2; i++) {
//        p = p -> next;
//    }
//    return p -> data;
//}

int findMiddle(struct Node *p) {
    struct Node *q;
    
    p = q = first;
    while(q) {
        q = q -> next;
        if(q) {
            q = q -> next;
        }
        if(q) {
            p = p -> next;
        }
    }
    return p -> data;
}

int main() {
	int A[] = {3, 5, 7, 10, 15};
    create(A, 5);
    
    printf("%d", findMiddle(first));
	return 0;
}
