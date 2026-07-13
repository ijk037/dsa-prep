#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include<ctype.h>
#include <string.h>
#define MAX 100

char stack[MAX];
int top = -1;

void push(char ch){
    if(top==MAX-1)
        return;
    stack[++top] = ch;
}

char pop(){
    if(top==-1)
        return '\0';
    return stack[top--];
}

char peek(){
    if(top==-1)
        return '\0';
    return stack[top];
}

int prec(char c){
    if (c=='^')
        return 3;
    else if (c=='*' || c=='/')
        return 2;
    else if (c=='+' || c=='-')
        return 1;
    else
        return -1;
}

void infixtopostfix(char infix[]){
    char postfix[MAX];
    int i=0, j=0;
    while(infix[i]!='\0'){
        if(isalnum(infix[i]))
            postfix[j++]=infix[i];
        else if(infix[i] == '(')
            push(infix[i]);
        else if (infix [i] == ')'){
            while (peek()!='(')
                postfix[j++]=pop();
            pop();
        }
        else{
            while(top!=-1 && prec(peek())>=prec(infix[i]))
                postfix[j++]=pop();
            push(infix[i]);
        }
        i++;
    }
    while(top!=-1)
        postfix[j++]=pop();
    postfix[j]='\0';
    printf("Postfix exp: %s", postfix);
}

int main(){
    char infix[MAX];
    printf("Enter infix expression: ");
    scanf("%s", infix);

    infixtopostfix(infix);

    return 0;
}