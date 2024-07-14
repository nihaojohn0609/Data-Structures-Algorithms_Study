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

int Length(struct Node *h) {
    int len = 0;
    do {
        len++;
        h = h -> next;
    } while(h != Head);
    return len;
}

void Insert(struct Node *p, int index, int x) {
    struct Node *t;
    int i;
    
    if(index < 0 || index > Length(p)) {
        return;
    }
    t = (struct Node *)malloc(sizeof(struct Node));
    t -> data = x;
    
    if(index == 0) {
        if(Head == NULL) {
            Head = t;
            Head -> next = Head;
            Head -> prev = Head;
        } else {
            t -> next = Head;
            t -> prev = Head -> prev;
            Head -> prev = Head -> prev -> next = t;
            
            Head = t;
        }
    } else {
        for(i = 0; i < index - 1; i++) {
            p = p -> next;
        }
        t -> next = p -> next;
        t -> prev = p;
        if(p -> next) {
            p -> next -> prev = t;
        }
        p -> next = t;
    }
}

int Delete(struct Node *p, int index) {
    struct Node *q;
    int i, x;
    
    if(index <= 0 || index > Length(p)) {
        return -1;
    }
    if(index == 1) {
        x = Head -> data;
        if(Head -> next == Head && Head -> prev == Head) {
            free(Head);
            Head = NULL;
        } else {
            q = Head -> prev;
            q -> next = Head -> next;
            Head -> next -> prev = q;
            q = Head;
            Head = q -> next;
            free(q);
        }
    } else {
        for(i = 0; i < index - 2; i++) {
            p = p -> next;
        }
        q = p -> next;
        p -> next = q -> next;
        q -> next -> prev = p;
        x = q -> data;
        free(q);
    }
    return x;
}

int main() {
	int A[] = {10, 20, 30, 40, 50};
    Create(A, 5);
    Delete(Head, 0);
    
    Display(Head);
	return 0;
}