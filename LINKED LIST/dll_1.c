#include <stdio.h>
#include <stdlib.h>


struct Node{
    int data;
    struct Node *next;
    struct Node *prev;
};

struct Node *createNode(int value){
    struct Node *newnode = (struct Node*)malloc(sizeof(struct Node));
    newnode -> data = value;
    newnode -> next = NULL;
    newnode -> prev = NULL;
    return newnode;
}

//INSERTION AT FRONT
struct Node *insertatfront(struct Node *head, int value){
    struct Node *newnode = createNode(value);
    newnode -> next = head;
    newnode ->prev = NULL;
    if (head!=NULL)
        head -> prev = newnode;
    head = newnode;
    return head;
}

//INSERTION AT END
struct Node *insertatend(struct Node *head, int value){
    struct Node *newnode = createNode(value);
    if (head==NULL){
        head = newnode;
        return head;
    }
    struct Node *temp = head;
    while (temp->next!=NULL){
        temp = temp->next;
    }
    temp->next=newnode;
    newnode->prev=temp;
    return head;
}

//INSERTION AFTER A POSITION



//DELETE FIRST NODE
struct Node *deletefirst(struct Node *head){
    if(head==NULL){
        return head;
    }
    struct Node *temp = head;
    head = head->next;
    if(head!=NULL){
        head->prev = NULL;
    }
    free(temp);
    return head;
}

//DELETE LAST NODE
struct Node *deletelast(struct Node *head){
    if (head==NULL)
        return head;
    if (head->next==NULL){
        free(head);
        return NULL;
    }
    struct Node *temp = head;
    while(temp->next!=NULL)
        temp = temp->next;
    temp->prev->next = NULL;
    free(temp);
    return head;
}

//DELETE A VALUE
struct Node *deletevalue(struct Node *head, int key){
    struct Node *temp = head;

    while(temp!=NULL && temp->data!=key){
        temp=temp->next;
    }

    if (temp==NULL)
        return head;
    
    if (temp==head){
        return deletefirst(head);
    }

    if (temp->next == NULL){
        return deletelast(head);
    }

    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    
    free(temp);
    return head;
}

//REVERSE PRINT DLL
struct Node* printreverse(struct Node *head){
    if (head == NULL) return head;
    struct Node *tail = head;
    while (tail->next != NULL){
        tail = tail->next;
    }
    while(tail!=NULL){
        printf(" %d -> ", tail->data);
        tail = tail->prev;
    }
    return head;
}

//REVERSE LL
struct Node *reverseLL(struct Node *head){
    struct Node *temp = NULL;
    struct Node *curr = head;
    while (curr!=NULL){
        temp = curr->prev;
        curr->prev = curr->next;
        curr->next = temp;
        curr = curr->prev;
    }
    if (temp!=NULL){
        head = temp->prev;
    }
    return head;
}







//DISPLAY
struct Node *display(struct Node *head){
    while (head!=NULL){
        printf(" %d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main(){
    struct Node *head = NULL;

    head = insertatfront(head, 10);
    head = insertatfront(head, 20);
    head = insertatfront(head, 30);
    printf("Initial list        : ");
    display(head);
    printf("\n");

    head = insertatfront(head, 0);
    head = insertatend(head, 60);
    printf("After insertions    : ");
    display(head);
    printf("\n");

    head = deletefirst(head);
    printf("After deletion      : ");
    display(head);
    printf("\n");

    head = deletelast(head);
    printf("After deletion      : ");
    display(head);
    printf("\n");
    
    head = deletevalue(head, 60);
    printf("After deletion      : ");
    display(head);
    printf("\n");

    printf("Reverse print       : ");
    printreverse(head); printf("NULL\n");
    printf("\n");

    head = reverseLL(head);
    printf("Reversed LL         : ");
    display(head);
    printf("\n");
}