#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include<ctype.h>
#include <string.h>
#define MAX 100

int Stack[MAX];
int top=-1;

void push(int value){
    if(top==MAX-1)
        return;
    Stack[++top] = value;
}

int pop(){
    if(top==-1)
        return -1;
    return Stack[top--];
}

void display(){
    if(top==-1){
        printf("Stack empty");
        return;
    }
    printf("Stack: ");
    for(int i=top; i>=0; i--)
        printf("%d ", Stack[i]);
    printf("\n");
}

void insertatbottom(int value){
    if(top==-1){
        push(value);
        return;
    }
    int temp=pop();
    insertatbottom(value);
    push(temp);
}

void reversal(){
    if (top==-1)
        return;
    int temp=pop();
    reversal(Stack);
    insertatbottom(temp);
}

int main(){
    push(1);
    push(2);
    push(3);

    printf("Original ");
    display();

    reversal();

    printf("After reversal, ");
    display();
}