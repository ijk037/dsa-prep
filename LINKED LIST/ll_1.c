#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

//NODE CREATION
struct Node *createNode(int value){
    struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));
    newnode -> data = value;
    newnode -> next = NULL;
    return newnode;
}

//NODE INSERTION AT FRONT
void insertatfront(struct Node **head, int value){
    struct Node *newnode = createNode(value);
    newnode -> next = *head;
    *head = newnode;
}

//NODE INSERTION AT END
void insertatend(struct Node **head, int value){
    struct Node *newnode = createNode(value);
    if(*head == NULL){
        *head = newnode;
        return;
    }
    struct Node *temp = *head;
    while(temp->next !=NULL){
        temp = temp->next;
    }
    temp->next = newnode;
}

//NODE INSERTION AFTER A POSITION
void insertafterpos(struct Node *head, int key, int value){
    while (head!=NULL && head->data!=key){
        head = head->next;
    }
    if (head==NULL){
        printf("Element not found!\n");
        return;
    }
    struct Node* newnode = createNode(value);
    newnode->next = head->next;
    head->next = newnode;
}

//DELETION FROM POSITION
void deletion(struct Node **head, int key){
    struct Node *temp = *head;
    struct Node *prev = NULL;

    if (*head==NULL)
        return;
    if (temp->data ==key){
        *head = temp->next;
        free(temp);
        return;
    }
    while (temp!=NULL && temp->data!=key){
        prev = temp;
        temp = temp->next;
    }
    if (temp==NULL){
        printf("Element not found!\n");
        return;
    }
    prev->next = temp->next;
    free(temp);
}

//ITERATIVE COUNTING
int iterativecount(struct Node *head){
    int count = 0;
    while (head!=NULL){
        count++;
        head = head->next;
    }
    return count;   
}

//RECURSIVE COUNTING
int recursivecount(struct Node *head){
    if (head==NULL)
        return 0;
    else
        return 1+recursivecount(head->next);
}

//PRINTING LL BACKWARDS
void printreverseLL(struct Node* head){
    if (head==NULL){
        return;
    }
    printreverseLL(head->next);
    printf("%d -> ", head->data);
}

//REVERSED LINKED LIST
void reverseLL(struct Node **head){
    struct Node *prev = NULL;
    struct Node *curr = *head;
    struct Node *next = NULL;

    while (curr!=NULL){
        next = curr->next;
        curr->next = prev;
        prev=curr;
        curr = next;
    }
    *head = prev;
}

//INSERT IN SORTED LL
void sortedinsertion(struct Node **head, int value){
    struct Node *newnode = createNode(value);
    if(*head==NULL || (*head)->data>=value){
        newnode->next=*head;
        *head = newnode;
        return;
    }

    struct Node *temp = *head;
    while (temp->next!=NULL && temp->next->data<value){
        temp=temp->next;
    newnode->next = temp->next;
    temp->next=newnode;
    }
}


struct Node *sortedinsertionnew(struct Node *head, int value){
    struct Node *newnode = createNode(value);

    if (head==NULL || head->data>=value){
        newnode->next=head;
        head = newnode;
        return head;
    }
    while (head->next!=NULL && head->next->data<value){
        head=head->next;
    newnode->next = head->next;
    head->next = newnode;
    return head;
    }
}



//MERGING 2 SORTED LL INTO A SORTED LL



//DISPLAY LL
void display(struct Node *head){
    while (head!=NULL){
        printf(" %d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}


int main(){
    createNode(10);
    createNode(20);
    createNode(30);

    display();

    insertatfront(0);
    insertatend(60);
    insertafterpos(30, 40);

    display();

    deletion(60);

    display();

    iterativecount();
    recursivecount();

    printreverseLL();

    reverseLL();

    sortedinsertion();

    display();

    sortedinsertionnew();

    display();

}