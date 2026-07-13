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

void reverse(char str[]){
    int i=0, j=strlen(str)-1;
    while(i<j){
        char temp = str[i];
        str[i]= str[j];
        str[j]=temp;
        i++;
        j--;
    }
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

void infixtoprefix(char infix[]){
    char prefix[MAX];
    int i=0, j=0;

    reverse(infix);

    for(i=0; infix[i]!='\0'; i++){
        if(infix[i] == '(')
            infix[i]=')';
        else if(infix[i] == ')')
            infix[i]='(';
    }

    top=-1;

    for(i=0; infix[i]!='\0'; i++){
        if (isalnum(infix[i]))
            prefix[j++]=infix[i];
        else if(infix[i] == '(')
            push(infix[i]);
        else if (infix [i] == ')'){
            while (peek()!='(')
                prefix[j++]=pop();
            pop();
        }
        else{
            while(top!=-1 && prec(peek())>=prec(infix[i]))
                prefix[j++]=pop();
            push(infix[i]);
        }
    }
    
    while(top!=-1)
        prefix[j++]=pop();
    prefix[j]='\0';
    reverse(prefix);
    printf("Prefix exp: %s", prefix);
}

int main(){
    char infix[MAX];
    printf("Enter infix expression: ");
    scanf("%s", infix);

    infixtoprefix(infix);

    return 0;
}