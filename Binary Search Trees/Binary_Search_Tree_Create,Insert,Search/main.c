#include <stdio.h>
#include <stdlib.h>

struct Node {
    struct Node *lchild;
    int data;
    struct Node *rchild;
}*root = NULL;

void Insert(int key) {
    struct Node *t = root;
    struct Node *r, *p;
    
    if(root == NULL) {
        p = (struct Node *)malloc(sizeof(struct Node));
        p -> data = key;
        p -> lchild = p -> rchild = NULL;
        root = p;
        return;
    }
    while(t != NULL) {
        r = t;
        if(key < t -> data) {
            t = t -> lchild;
        } else if(key > t -> data) {
            t = t -> rchild;
        } else {
            return;
        }
    }
    p = (struct Node *)malloc(sizeof(struct Node));
    p -> data = key;
    p -> lchild = p -> rchild = NULL;

    if(key < r -> data) {
        r -> lchild = p;
    } else {
        r -> rchild = p;
    }
}

void Inorder(struct Node *p) {
    if(p) {
        Inorder(p -> lchild);
        printf("%d ", p -> data);
        Inorder(p -> rchild);
    }
}

struct Node * Search(int key) {
    struct Node *t = root;
    
    while(t) {
        if(key == t -> data) {
            return t;
        } else if(key < t -> data) {
            t = t -> lchild;
        } else {
            t = t -> rchild;
        }
    }
    return NULL;
}

struct Node * RSearch(struct Node *p, int key) {
    if(p == NULL) {
        return NULL;
    }
    if(key == p -> data) {
        return p;
    } else if(key < p -> data) {
        return RSearch(p -> lchild, key);
    } else {
        return RSearch(p -> rchild, key);
    }
}

int main() {
    struct Node *temp;
    
	root = RInsert(root, 10);
    RInsert(root, 5);
    RInsert(root, 20);
    RInsert(root, 8);
    RInsert(root, 30);
    
//    Insert(10);
//    Insert(5);
//    Insert(20);
//    Insert(8);
//    Insert(30);

    Inorder(root);
    printf("\n");
    
//    temp = Search(2);
//    if(temp) {
//        printf("Element %d is found\n", temp -> data);
//    } else {
//        printf("Element is not found\n");
//    }
    
    temp = RSearch(root, 2);
    if(temp) {
        printf("Element %d is found\n", temp -> data);
    } else {
        printf("Element is not found\n");
    }
	return 0;
}