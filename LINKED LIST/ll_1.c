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
struct Node *insertatfront(struct Node *head, int value){
    struct Node *newnode = createNode(value);
    newnode -> next = head;
    head = newnode;
    return head;
}

//NODE INSERTION AT END
struct Node *insertatend(struct Node *head, int value){
    struct Node *newnode = createNode(value);
    if(head == NULL){
        head = newnode;
        return head;
    }
    struct Node *temp = head;
    while(temp->next !=NULL){
        temp = temp->next;
    }
    temp->next = newnode;
    return head;
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
struct Node *deletion(struct Node *head, int key){
    struct Node *temp = head;
    struct Node *prev = NULL;

    if (head==NULL)
        return head;
    if (temp->data ==key){
        head = temp->next;
        free(temp);
        return head;
    }
    while (temp!=NULL && temp->data!=key){
        prev = temp;
        temp = temp->next;
    }
    if (temp==NULL){
        printf("Element not found!\n");
        return head;
    }
    prev->next = temp->next;
    free(temp);
    return head;
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
struct Node *reverseLL(struct Node *head){
    struct Node *prev = NULL;
    struct Node *curr = head;
    struct Node *next = NULL;

    while (curr!=NULL){
        next = curr->next;
        curr->next = prev;
        prev=curr;
        curr = next;
    }
    head = prev;
    return head;
}


//.................................
//SORTING THE LL
void splitlist(struct Node *head, struct Node **left, struct Node **right){
    struct Node *slow = head;
    struct Node *fast = head->next;     // fast starts ahead so mid rounds down

    while(fast!=NULL && fast->next!=NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    *left  = head;
    *right = slow->next;
    slow->next = NULL;
}

struct Node *merge(struct Node *left, struct Node *right){
    if(left==NULL)  return right;
    if(right==NULL) return left;

    if(left->data <= right->data){
        left->next = merge(left->next, right);
        return left;
    } else {
        right->next = merge(left, right->next);
        return right;
    }
}

struct Node *mergesort(struct Node *head){
    if(head==NULL || head->next==NULL)
        return head;

    struct Node *left, *right;
    splitlist(head, &left, &right);
    left  = mergesort(left);
    right = mergesort(right);
    return merge(left, right);
}
//.................................

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
    }
    newnode->next = temp->next;
    temp->next=newnode;
}


struct Node *sortedinsertionnew(struct Node *head, int value){
    struct Node *newnode = createNode(value);

    if (head==NULL || head->data>=value){
        newnode->next=head;
        return newnode;
    }
    struct Node *temp = head;
    while (temp->next!=NULL && temp->next->data<value){
        temp=temp->next;
    }
    newnode->next = temp->next;
    temp->next = newnode;
    return head;
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
    struct Node *head = NULL;

    head = insertatend(head, 20);
    head = insertatend(head, 80);
    head = insertatend(head, 46);
    printf("Initial list        : ");
    display(head);
    printf("\n");

    head = insertatfront(head, 0);
    head = insertatend(head, 60);
    insertafterpos(head, 80, 40);
    printf("After insertions    : ");
    display(head);
    printf("\n");

    head = deletion(head, 60);
    printf("After deletion      : ");
    display(head);
    printf("\n");

    printf("Iterative counting result = %d\n", iterativecount(head));
    printf("Recursive counting result = %d\n", recursivecount(head));
    printf("\n");

    printf("Reverse print       : ");
    printreverseLL(head); printf("NULL\n");
    printf("\n");

    head = reverseLL(head);
    printf("Reversed LL         : ");
    display(head);
    printf("\n");

    head = mergesort(head);
    printf("After mergesort     : ");
    display(head);
    printf("\n");

    sortedinsertion(&head, 25);
    printf("Inserting in sorted list        : ");
    display(head);
    printf("\n");

    head = sortedinsertionnew(head, 27);
    printf("Inserting in sorted list        : ");
    display(head);
    printf("\n");
}