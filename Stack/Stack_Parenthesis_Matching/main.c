#include <stdio.h>
#include <stdlib.h>

struct Node {
    char data;
    struct Node *next;
}*top = NULL;

void push(char x) {
    struct Node *t;
    t = (struct Node*)malloc(sizeof(struct Node));
    
    if(t == NULL) {
        printf("Stack is full\n");
    } else {
        t -> data = x;
        t -> next = top;
        top = t;
    }
}

char pop() {
    struct Node *t;
    char x = -1;
    
   if(top == NULL) {
       printf("Stack is Empty\n");
   } else {
       t = top;
       top = top -> next;
       x = t -> data;
       free(t);
   }
   return x;
}

void Display() {
    struct Node *p;
    p = top;
    while(p != NULL) {
        printf("%c ", p -> data); 
        p = p -> next;
    }
    printf("\n");
}

int isBalanced1(char *exp) {
    int i;
    
    for(i = 0; exp[i] != '\0'; i++) {
        if(exp[i] == '(') {
            push(exp[i]);
        } else if(exp[i] == ')') {
            if(top == NULL) {
                return 0;
            }
            pop();
        }
    }
    if(top == NULL) {
        return 1;
    } else {
        return 0;
    }
}

int isBalanced2(char *exp) {
    int i;
    
    for(i = 0; exp[i] != '\0'; i++) {
        if(exp[i] == '{' || exp[i] == '(' || exp[i] == '[') {
            push(exp[i]);
        } else if(exp[i] == '}' || exp[i] == ')' || exp[i] == ']') {
            if(top == NULL) {
                return 0;
            }
            char popped = pop();
            if((exp[i] == '}' && popped != '{') || (exp[i] == ')' && popped != '(') || (exp[i] == ']' && popped != '[')) {
                return 0;
            }
        }
    }
    return top == NULL;
}

int isBalanced3(char *exp) {
    int i;
    for(i = 0; exp[i] != '\0'; i++) {
        if(exp[i] == '{' || exp[i] == '(' || exp[i] == '[') {
            push(exp[i]);
        } else if(exp[i] == '}' || exp[i] == ')' || exp[i] == ']') {
            if(top == NULL) {
                return 0;
            } else if(exp[i] < 50 && exp[i] - top -> data == 1) {
                pop();
            } else if(exp[i] < 100 && exp[i] - top -> data == 2) {
                pop();
            } else if(exp[i] > 100 && exp[i] - top -> data == 2) {
                pop();
            }
        }
    }
    if(top == NULL) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    char *exp1 = "((a + b) * (c - d))";
    char *exp2 = "{([a + b] * [c - d]) / e}";
    char *exp3 = "{([a + b] * [c - d]) / e}";
    
	printf("%d ", isBalanced1(exp1));
	printf("%d ", isBalanced2(exp2));
	printf("%d ", isBalanced3(exp3));
	return 0;
}