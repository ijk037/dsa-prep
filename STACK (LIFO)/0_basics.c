#include<stdio.h>
#include<stdlib.h>
#include <stdbool.h>
#define MAX 100

struct Stack{
    int arr[MAX];
    int top;
};

void initialization(struct Stack *s){
    s->top=-1;
}

bool isEmpty(struct Stack *s){
    return s->top==-1;
}

bool isFull(struct Stack *s){
    return s->top >= MAX-1;
}

void push(struct Stack *s, int value){
    if(isFull(s))
        return;

    s->arr[++s->top]=value;
}

int pop(struct Stack *s){
    if(isEmpty(s))
        return -1;

    int popped = s->arr[s->top];
    s->top--;
    return popped;
}

int peek(struct Stack *s){
    if(isEmpty(s))
        return -1;
    return s->arr[s->top];
}

int main(){
    struct Stack *s;
    initialization(s);

    push(s, 3);
    printf("Top element: %d\n", peek(s));
    push(s, 4);
    printf("Top element: %d\n", peek(s));
    push(s, 5);
    printf("Top element: %d\n", peek(s));
    push(s, 1);
    printf("Top element: %d\n", peek(s));

    while(!isEmpty(s)){
        printf("Top element: %d\n", peek(s));
        printf("Popped element: %d\n", pop(s));
    }
    return 0;
}