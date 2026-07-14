#include<stdio.h>
#include<stdlib.h>
#include <stdbool.h>
#define MAX 100

int Queue[MAX];
int front=-1, rear=-1;

void enqueue(int value){
    if(rear==MAX-1)
        return;
    if(front==-1)
        front=0;
    Queue[++rear]=value;
}

int dequeue(){
    if(front==-1 || front>rear)
        return -1;
    int value = Queue[front++];
    if(front>rear){
        front=rear=-1;
    }
    return value;
}

int getFront(){
    if(front==-1)
        return -1;
    return Queue[front];
}

int getRear(){
    if(rear==-1)
        return -1;
    return Queue[rear];
}

int isEmpty(){
    if(front==-1)
        return 1;
    return 0;
}

int size(){
    if(front==-1)
        return 0;
    return rear-front+1;
}

void display(){
    if(isEmpty()){
        return;
    }
    printf("Queue: ");
    for(int i=front; i<=rear; i++)
        printf("%d ", Queue[i]);
    
    printf("\n");
}

int main(){
    if(isEmpty())
        printf("Queue is empty.\n");
    else
        printf("Queue is not empty.\n");
    
    printf("Enqueued ");
    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(4);
    enqueue(5);

    display();
    printf("Queue size: %d\n", size());

    printf("Front of the queue: %d\n", getFront());
    printf("Rear of the queue: %d\n", getRear());

    printf("Dequeued: %d\n", dequeue());
    printf("New ");
    display();

    printf("Queue size: %d\n", size());

    if(isEmpty())
        printf("Queue is empty.\n");
    else
        printf("Queue is not empty.\n");

    return 0;
}