#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct Node {
    int coeff;
    int exp;
    struct Node *next;
}*poly = NULL;

struct Node *first = NULL;
struct Node *second = NULL;
struct Node *third = NULL;

void CreateFirst(int x) {
    struct Node *t, *last;
    int i;
    first = (struct Node *)malloc(sizeof(struct Node));
    scanf("%d %d", &first -> coeff, &first -> exp);
    first -> next = NULL;
    last = first;
    for(i = 1; i < x; i++) {
        t = (struct Node *)malloc(sizeof(struct Node));
        scanf("%d %d", &t -> coeff, &t -> exp);
        t -> next = NULL;
        last -> next = t;
        last = t;
    }
}

void CreateSecond(int x) {
    struct Node *t, *last;
    int i;
    second = (struct Node *)malloc(sizeof(struct Node));
    scanf("%d %d", &second -> coeff, &second -> exp);
    second -> next = NULL;
    last = second;
    for(i = 1; i < x; i++) {
        t = (struct Node *)malloc(sizeof(struct Node));
        scanf("%d %d", &t -> coeff, &t -> exp);
        t -> next = NULL;
        last -> next = t;
        last = t;
    }
}

void Display(struct Node *p) {
    while(p) {
        printf("%dx^%d", p -> coeff, p -> exp);
        p = p -> next;
        if(p) {
            printf(" + ");
        }
    }
    printf("\n");
}

long Eval(struct Node *p, int x) {
    long val = 0;
    
    while(p) {
        val += p -> coeff * pow(x, p -> exp);
        p = p -> next;
    }
    return val;
}

void Add(struct Node *p, struct Node *q) {
    struct Node *last, *t;
    third = (struct Node *)malloc(sizeof(struct Node));
    third->next = NULL;
    last = third;
    
    while(p && q) {
        t = (struct Node *)malloc(sizeof(struct Node));
        if(p -> exp > q -> exp) {
            t -> coeff = p -> coeff;
            t -> exp = p -> exp;
            t -> next = NULL;
            last -> next = t;
            last = t;
            p = p -> next;
        } else if(p -> exp < q -> exp) {
            t -> coeff = q -> coeff;
            t -> exp = q -> exp;
            t -> next = NULL;
            last -> next = t;
            last = t;
            q = q -> next;
        } else {
            t -> coeff = p -> coeff + q -> coeff;
            t -> exp = p -> exp;
            t -> next = NULL;
            last -> next = t;
            last = t;
            p = p -> next;
            q = q -> next;
        }
    }
    while(p) {
        t = (struct Node *)malloc(sizeof(struct Node));
        t -> coeff = p -> coeff;
        t -> exp = p -> exp;
        t -> next = NULL;
        last -> next = t;
        last = t;
        p = p -> next;
    }
    while(q) {
        t = (struct Node *)malloc(sizeof(struct Node));
        t -> coeff = q -> coeff;
        t -> exp = q -> exp;
        t -> next = NULL;
        last -> next = t;
        last = t;
        q = q -> next;
    }
    
    struct Node *temp = third;
    third = third -> next;
    free(temp);
}

int main() {
    int n1, n2;
    
    printf("Enter number of terms in first polynomial: ");
    scanf("%d", &n1);
    CreateFirst(n1);
    
    printf("Enter number of terms in second polynomial: ");
    scanf("%d", &n2);
    CreateSecond(n2);
    
    Add(first, second);
    Display(third);
    
    printf("%ld\n",Eval(third,1));
    
	return 0;
}