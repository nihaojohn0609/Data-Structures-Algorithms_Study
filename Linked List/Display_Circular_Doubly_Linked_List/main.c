#include <stdio.h>
#include <stdlib.h>

struct Node {
    struct Node *prev;
    int data;
    struct Node *next;
}*Head = NULL;

void Create(int A[], int n) {
    int i;
    struct Node *t, *last;
    Head = (struct Node *)malloc(sizeof(struct Node));
    Head -> data = A[0];
    Head -> next = Head;
    Head -> prev = Head;
    last = Head;
    
    for(i = 1; i < n; i++) {
        t = (struct Node *)malloc(sizeof(struct Node));
        t -> data = A[i];
        t -> next = last -> next;
        t -> prev = last;
        last -> next = t;
        Head -> prev = t;
        last = t;
    }
}

void Display(struct Node *h) {
    do {
        printf("%d ", h -> data);
        h = h -> next;
    } while(h != Head);
    printf("\n");
}

int main() {
	int A[] = {10, 20, 30, 40, 50};
    Create(A, 5);
    
    Display(Head);
	return 0;
}
