#include <stdio.h>
#include <stdlib.h>

struct Queue {
    int size;
    int front;
    int rear;
    int *DQ;
};

void create(struct Queue *q, int size) {
    q -> size = size;
    q -> front = q -> rear = -1;
    q -> DQ = (int *)malloc(q -> size * sizeof(int));
}

void enqueue_front(struct Queue *q, int x) {
    if(q -> front == -1) {
        printf("DQ is Full! Can't insert from front!\n");
    } else {
        q -> DQ[q -> front] = x;
        q -> front--;
    }
}

int dequeue_front(struct Queue *q) {
    int x = -1;
    if(q -> front == q -> rear) {
        printf("DQ is Empty");
    } else {
        q -> front++;
        x = q -> DQ[q -> front];
    }
    return x;
}

void enqueue_rear(struct Queue *q, int x) {
    if(q -> rear == q -> size - 1) {
        printf("DQ is Full\n");
    } else {
        if(q -> front == q -> rear) {
            q -> front = q -> rear = -1;
        }
        q -> rear++;
        q -> DQ[q -> rear] = x;
    }
}

int dequeue_rear(struct Queue *q) {
    int x = -1;
    if(q -> rear == q -> front) {
        printf("DQ is Empty");
    } else {
        x = q -> DQ[q -> rear];
        q -> rear--;
    }
    return x;
}

void Display(struct Queue *q) {
    int i;
    for(i = q -> front + 1; i <= q -> rear; i++) {
        printf("%d ", q -> DQ[i]); 
    }
    printf("\n");
}

int main() {
	struct Queue q;
    create(&q, 3);
    
    enqueue_rear(&q, 5);
    enqueue_rear(&q, 6);
    enqueue_rear(&q, 10);
 
    Display(&q);
 
    dequeue_front(&q);
    dequeue_front(&q);
    Display(&q);
 
    enqueue_front(&q, 3);
    enqueue_front(&q, 4);
 
    Display(&q);
 
    enqueue_rear(&q, 5);
    enqueue_front(&q, 4);
 
    printf("%d was dequeued\n", dequeue_rear(&q));
 
    printf("Rear is at %d\n", q.rear);
 
    printf("Front is at %d\n", q.front);
 
    Display(&q);
	return 0;
}