#include <stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

struct Node *createNode(int value){
    struct Node *newnode = (struct Node*)malloc(sizeof(struct Node));
    newnode->data = value;
    newnode->next = NULL;
    return newnode;
}

void display(struct Node *head){
    while (head!=NULL){
        printf(" %d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

struct Node *removing_kth_element(struct Node *head, int k){
    if (head==NULL){
        printf("List is empty.");
        return head;
    }
    
    if(k==1){
        struct Node *temp = head;
        head = head->next;
        free(temp);
        return head;
    }
    
    struct Node*temp = head;
    for (int i=1; i<k-1 && temp!=NULL; i++){
        temp=temp->next;
    }

    if(temp==NULL || temp->next==NULL){
        printf("Position out of bounds!");
        return head;
    }

    temp->next=temp->next->next;
    head->next=temp;

    display(head);
}

int main(){
    struct Node* head = createNode(10);
    head->next = createNode(20);
    head->next->next = createNode(30);
    head->next->next->next = createNode(70);
    head->next->next->next->next = createNode(40);
    head->next->next->next->next->next = createNode(50);

    display(head);
    printf("\n");
    int pos;
    printf("Enter the position of the element you want to delete:");
    scanf ("%d", &pos);

    removing_kth_element(head, pos);
    printf("\n");
    display(head);

    return 0;
}