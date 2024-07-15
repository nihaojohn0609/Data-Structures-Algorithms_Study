#include <stdio.h>
#include <stdlib.h>

struct Node {
    int i;
    int j;
    int x;
    struct Node *next;
};

struct Sparse {
    int m;
    int n;
    int num;
    struct Node *A;
}*s1 = NULL, *s2 = NULL, *s3 = NULL;

void Create(struct Sparse *s) {
    int i;
    struct Node *last, *t;
    printf("Enter dimensions: ");
    scanf("%d %d", &s -> m, &s -> n);
    printf("Number of non-zero elements: ");
    scanf("%d", &s -> num);
    
    s -> A = (struct Node *)malloc(sizeof(struct Node));
    printf("Enter row, column, and corresponding element: ");
    scanf("%d %d %d", &s -> A -> i, &s -> A -> j, &s -> A -> x);
    s -> A -> next = NULL;
    last = s -> A;
    
    for(i = 1; i < s -> num; i++) {
        t = (struct Node *)malloc(sizeof(struct Node));
        printf("Enter row, column, and corresponding element: ");
        scanf("%d %d %d", &t -> i, &t -> j, &t -> x);
        
        t -> next = NULL;
        last -> next = t;
        last = t;
    }
}

void Display(struct Sparse *s) {
    int i, j;
    struct Node *p = s->A; // Use a temporary pointer to traverse the list
    for(i = 0; i < s -> m; i++) {
        for(j = 0; j < s -> n; j++) {
            if(p && i == p -> i && j == p -> j) {
                printf("%d ", p -> x);
                p = p -> next;
            } else {
                printf("0 ");
            }
        }
        printf("\n");
    }
}

struct Sparse* Add(struct Sparse *s1, struct Sparse *s2) {
    if(s1 -> m != s2 -> m || s1 -> n != s2 -> n) {
        return NULL;
    }
    struct Node *last;
    struct Sparse *sum = (struct Sparse *)malloc(sizeof(struct Sparse));
    sum -> m = s1 -> m;
    sum -> n = s1 -> n;
    sum -> num = 0;
    sum -> A = NULL;
    
    struct Node *p = s1 -> A;
    struct Node *q = s2 -> A;
    
    while(p && q) {
        struct Node *t = (struct Node *)malloc(sizeof(struct Node));
        if(p -> i < q -> i || (p -> i == q -> i && p -> j < q -> j)) {
            t -> i = p -> i;
            t -> j = p -> j;
            t -> x = p -> x;
            p = p -> next;
        } else if(p -> i > q -> i || (p -> i == q -> i && p -> j > q -> j)) {
            t -> i = q -> i;
            t -> j = q -> j;
            t -> x = q -> x;
            q = q -> next;
        } else {
            t -> i = p -> i;
            t -> j = p -> j;
            t -> x = p -> x + q -> x;
            p = p -> next;
            q = q -> next;
        }
        t -> next = NULL;
        
        if(sum -> A == NULL) {
            sum -> A = t;
            last = t;
        } else {
            last -> next = t;
            last = t;
        }
    }
    while(p) {
        struct Node *t = (struct Node *)malloc(sizeof(struct Node));
        t -> i = p -> i;
        t -> j = p -> j;
        t -> x = p -> x;
        t -> next = NULL;
        if(sum -> A == NULL) {
            sum -> A = t;
            last = t;
        } else {
            last -> next = t;
            last = t;
        }
        p = p -> next;
    }
    while(q) {
        struct Node *t = (struct Node *)malloc(sizeof(struct Node));
        t -> i = q -> i;
        t -> j = q -> j;
        t -> x = q -> x;
        t -> next = NULL;
        if(sum -> A == NULL) {
            sum -> A = t;
            last = t;
        } else {
            last -> next = t;
            last = t;
        }
        q = q -> next;
    }
    return sum;
}

int main() {
    s1 = (struct Sparse *)malloc(sizeof(struct Sparse));
    s2 = (struct Sparse *)malloc(sizeof(struct Sparse));
    Create(s1);
    Create(s2);
    Display(s1);
    printf("\n");
    Display(s2);
    printf("\n");
    
    s3 = Add(s1, s2);
    if(s3) {
        Display(s3);
    }
    
    free(s1);
    free(s2);
    free(s3);
    
	return 0;
}
