#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
}*first = NULL, *second = NULL, *third = NULL;


void createFirst(int A[], int n) {
    int i;
    struct Node *t, *last;
    first = (struct Node*)malloc(sizeof(struct Node));
    first -> data = A[0];
    first -> next = NULL;
    last = first;
    
    for(i = 1; i < n; i++) {
        t = (struct Node*)malloc(sizeof(struct Node));
        t -> data = A[i];
        t -> next = NULL;
        last -> next = t;
        last = t;
    }
}

void createSecond(int A[], int n) {
    int i;
    struct Node *t, *last;
    second = (struct Node*)malloc(sizeof(struct Node));
    second -> data = A[0];
    second -> next = NULL;
    last = second;
    
    for(i = 1; i < n; i++) {
        t = (struct Node*)malloc(sizeof(struct Node));
        t -> data = A[i];
        t -> next = NULL;
        last -> next = t;
        last = t;
    }
}

int length() {
    struct Node *p = first;
    int len = 0;
    while (p) {
        len++;
        p = p->next;
    }
    return len;
}

void Intersection(struct Node *p, struct Node *q) {
    struct Node *t, *temp, *last = NULL;
    while(p) {
        t = q;
        while(t) {
            if(p -> data == t -> data) {
                temp = (struct Node*)malloc(sizeof(struct Node));
                temp -> data = p -> data;
                temp -> next = NULL;
                if(third == NULL) {
                    third = last = temp;
                } else {
                    last -> next = temp;
                    last = temp;
                }
                break;
            }
            t = t -> next;
        }
        p = p -> next;
    }
}

void Display(struct Node *p) {
    while(p) {
        printf("%d ", p-> data);
        p = p->next;
    }
    printf("\n");
}

int main() {
	int A[] = {10, 20, 30, 40, 50};
    int B[] = {1, 10, 15, 20, 30};
    createFirst(A,5);
    createSecond(B,5);
    
    Intersection(first,second);
    Display(third);
    
	return 0;
}
