#include<stdio.h>
#include <string.h>
#define MAX 100

char stack[MAX];
int top=-1;

void push(char ch){
    top++;
    stack[top] = ch;
}

char pop(){
    if (top==-1){
        return '\0';
    }
    return stack[top--];
}

int isEmpty(){
    return top==-1;
}

int isbalanced(char str[]){
    int i;
    char ch, temp;
    for (i=0; str[i]!='\0'; i++){
        ch = str[i];

        if (ch=='(' || ch=='{' || ch=='[')
            push(ch);
        else if (ch==')' || ch=='}' || ch==']'){
            if(isEmpty())
                return 0;
            temp=pop();
            if ((ch==')' && temp!='(')||(ch=='}' && temp!='{')||(ch==']' && temp!='['))
                return 0;
        }
    }
    if (isEmpty())
        return 1;
    else
        return 0;
}


int main() {
    char str[] = "ABXKI839034RFJ";

    if (isbalanced(str))
        printf("TRUE");
    else
        printf("FALSE");

    return 0;
}