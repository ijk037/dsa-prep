#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

struct Node *createNode(int value){
    struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));
    newnode -> data = value;
    newnode -> next = NULL;
    return newnode;
}

int getlength(struct Node *head){
    int length = 0;
    while (head!=NULL){
        length++;
        head = head->next;
    }
    return length;
}

int getmiddle(struct Node*head){
    struct Node *slowptr = head;
    struct Node *fastptr = head;
    while (fastptr!=NULL && fastptr->next!=NULL){
        slowptr = slowptr ->next;
        fastptr = fastptr->next->next;
    }
    return slowptr->data;
}

int main() {
    struct Node* head = createNode(10);
    head->next = createNode(20);
    head->next->next = createNode(30);
    head->next->next->next = createNode(40);
    head->next->next->next->next = createNode(50);
    head->next->next->next->next->next = createNode(60);

    printf("%d\n", getmiddle(head));

    return 0;
}