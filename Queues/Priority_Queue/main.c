#include <stdio.h>
#include <stdlib.h>

struct Queue {
    int size;
    int front;
    int rear;
    int *Q;
};

void create(struct Queue *q, int size) {
    q -> size = size;
    q -> Q = (int *)malloc(q -> size * sizeof(int));
    q -> front = q -> rear = -1;
}

void enqueue(struct Queue *q, int x) {
    if(q -> rear == q -> size - 1) {
        printf("Queue is Full\n");
        return;
    }
    int rearInitiallyAt = q -> rear;
    while(q -> rear >= 0 && q -> Q[q -> rear] < x) { // shift right if smaller
        q -> Q[q -> rear + 1] = q -> Q[q -> rear];
        q -> rear--;
    }
    q -> Q[q -> rear + 1] = x;
    q -> rear = rearInitiallyAt;
    q -> rear++;
}

int dequeue(struct Queue *q) {
    int x = -1;
    if(q -> front == q -> rear) {
        printf("Queue is Empty\n");
    } else {
        x = q -> Q[q -> rear];
        q -> rear--;
    }
    return x;
}

int main() {
	struct Queue q;
    int size;
    printf("Enter the size of queue: ");
    scanf("%d",&size);
    create(&q, size);
    
    enqueue(&q, 5);
    enqueue(&q, 3);
    enqueue(&q, 6);
    enqueue(&q, 1);
    printf("\n");
    
    printf("%d ",dequeue(&q));
    printf("%d ",dequeue(&q));
    free(q.Q);
	return 0;
}