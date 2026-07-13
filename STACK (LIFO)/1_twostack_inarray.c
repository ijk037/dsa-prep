#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 100

int arr[MAX];
int top1=-1;
int top2=sizeof(arr)/sizeof(arr[0]);

void push1(int value){
    if(top1<top2-1){
        arr[++top1] = value;
    }
    else
        return;
}

void push2(int value){
    if(top1<top2-1){
        arr[--top2] = value;
    }
    else
        return;
}

int pop1(){
    if(top1==-1)
        return -1;

    return arr[top1--];
}

int pop2(){
    if(top2==MAX)
        return -1;
    return arr[top2++];
}

void display1(){
    if (top1==-1)
        return;
    
    printf("Stack 1: ");
    for(int i=0; i<=top1; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void display2(){
    if (top2==MAX)
        return;
    
    printf("Stack 2: ");
    for(int i=MAX-1; i>=top2; i--)
        printf("%d ", arr[i]);
    printf("\n");
}

int main(){
    push1(1);
    push1(2);
    push1(3);
    push2(1);
    push2(2);
    push2(3);

    display1();
    display2();

    printf("Popped from S1: %d\n", pop1());
    printf("Popped from S2: %d\n", pop2());

    display1();
    display2();

    printf("Array:\n");
    for(int i=0; i<MAX; i++)
        printf("%d ", arr[i]);
    
    return 0;
}