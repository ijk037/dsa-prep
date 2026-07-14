#include<stdio.h>
#include<stdlib.h>
#include <stdbool.h>
#define MAX 100

struct Queue{
    int arr[MAX];
    int front;
    int rear;
};

void initialize(struct Queue *q){
    q->front = -1;
    q->rear = -1;
}

int isEmpty(struct Queue *q){
    return (q->front == -1);
}

int size(struct Queue *q){
    if(isEmpty(q))
        return 0;
    return q->rear - q->front +1;
}

void enqueue(struct Queue *q, int value){
    if (q->rear == MAX-1)
        return;
    if(q->front==-1)
        q->front = 0;
    q->arr[++q->rear] = value;
}

int dequeue(struct Queue *q){
    if(isEmpty(q))
        return 0;
    int value = q->arr[q->front++];
    if(q->front > q->rear)
        q->front = q->rear = -1;
    return value;
}

int getFront(struct Queue *q){
    if(isEmpty(q))
        return -1;
    return q->arr[q->front];
}

int getRear(struct Queue *q){
    if(isEmpty(q))
        return -1;
    return q->arr[q->rear];
}

void display(struct Queue *q){
    if(isEmpty(q))
        return;
    for(int i=q->front; i<=q->rear; i++)
        printf("%d ", q->arr[i]);
}

int main(){
    struct Queue q;
    initialize(&q);
    
    if (isEmpty(&q))
        printf("Queue is empty.\n");
    else
        printf("Queue is not empty.\n");
    
    printf("Enqueued ");
    enqueue(&q, 1);
    enqueue(&q, 2);
    enqueue(&q, 3);
    enqueue(&q, 4);
    enqueue(&q, 5);

    display(&q);
    printf("Queue size: %d\n", size(&q));

    printf("Front of the queue: %d\n", getFront(&q));
    printf("Rear of the queue: %d\n", getRear(&q));

    printf("Dequeued: %d\n", dequeue(&q));
    printf("New Queue: ");
    display(&q);

    printf("Queue size: %d\n", size(&q));

    if(isEmpty(&q))
        printf("Queue is empty.\n");
    else
        printf("Queue is not empty.\n");

    return 0;
}