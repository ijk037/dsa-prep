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

void display_ll(struct Node *head){
    while(head!=NULL){
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

void display_arr(int arr[], int n){
    for (int i=0; i<n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

struct Node *conversion_from_array(int arr[], int n){
    if (n==0){
        printf("List is empty.");
        return NULL;
    }

    struct Node *head = createNode(arr[0]);
    struct Node *temp = head;
    int i=1;
    while(i<n){
        temp->next = createNode(arr[i]);
        temp = temp->next;
        i++;
    }
    return head;
}

int main(){
    int arr[] = {1, 2, 3, 4, 5, 6};
    int n = sizeof(arr)/sizeof(arr[0]);

    display_arr(arr, n);

    struct Node *head = head = conversion_from_array(arr, n);

    display_ll(head);
    return 0;
}