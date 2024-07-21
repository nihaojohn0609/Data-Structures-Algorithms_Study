#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    char data;
    struct Node *next;
}*top = NULL;

void push(char x) {
    struct Node *t;
    t = (struct Node *)malloc(sizeof(struct Node));
    
    if(t == NULL) {
        printf("Stack Overflow");
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
        printf("Stack Underflow");
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

char stackTop() {
    if(top == NULL) {
        return -1;
    }
    return top -> data;
}

int isBalanced(char *exp) {
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

int isOperand(char x) {
    if(x == '+' || x == '-' || x == '*' || x == '/' || x == '(' || x == ')' || x == '^') {
        return 0;
    } else {
        return 1;
    }
}

int outPrecedence(char x) {
    if(x == '+' || x == '-') {
        return 1;
    } else if(x == '*' || x == '/') {
        return 3;
    } else if(x == '^') {
        return 6;
    } else if (x == '(') {
        return 7;
    } else if(x == ')') {
        return 0;
    }
    return 0;
}

int inPrecedence(char x) {
    if(x == '+' || x == '-') {
        return 2;
    } else if(x == '*' || x == '/') {
        return 4;
    } else if(x == '^') {
        return 5;
    } else if(x == '(') {
        return 0;
    }
    return 0;
}

char* InToPost(char *infix) {
    int i = 0, j = 0;
    char *postfix;
    int len = strlen(infix);
    postfix = (char *)malloc((len + 2) * sizeof(char)); // because of added #
    
    while(infix[i] != '\0') {
        if(isOperand(infix[i])) {
            postfix[j++] = infix[i++];
        } else {
            if(outPrecedence(infix[i]) > inPrecedence(stackTop())) {
                push(infix[i++]);
            } else if(outPrecedence(infix[i]) < inPrecedence(stackTop())) {
                postfix[j++] = pop();
            } else {
                pop();
                i++;
            }
        }
    }
    while(top != NULL && stackTop() != '#') {
        postfix[j++] = pop();
    }
    postfix[j] = '\0';
    return postfix;
}

int main() {
    char *infix = "((a+b)*c)-d^e^f";
    push('#');
    
    char *postfix = InToPost(infix);
    
    printf("%s ", postfix);
	return 0;
}
