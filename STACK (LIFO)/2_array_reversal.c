#include<stdio.h>
#include<string.h>
#define MAX 100

char stack[MAX];
int top=-1;

void push(char ch){
    stack[++top] = ch;
}

char pop(){
    if (top==-1)
        return '\0';
    return stack[top--];
}

void reversal(char str[]){
    int i;

    for (int i=0; str[i]!='\0'; i++){
        push(str[i]);
    }
    for(int i=0; str[i]!='\0'; i++){
        str[i]=pop();
    }
}

int main(){
    char example[] = "hello";
    reversal(example);
    printf("%s", example);
    return 0;
}