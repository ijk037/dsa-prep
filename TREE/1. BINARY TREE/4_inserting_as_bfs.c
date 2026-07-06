#include <stdio.h>
#include <stdlib.h>
#define MAX 100

struct Node{
    int data;
    struct Node *left, *right;
};

struct Node *createNode(int value){
    struct Node *newnode = (struct Node*)malloc(sizeof(struct Node));
    newnode->data = value;
    newnode ->left = NULL;
    newnode->right = NULL;
    return newnode;
}

void insertion(struct Node *root, int key){
    if(root==NULL){
        root= createNode(key);
        return ;
    }

    struct Node *queue[MAX];
    int front=0, rear=0;

    queue[rear++]=root;

    while(front<rear){
        struct Node *temp = queue[front++];

        if(temp->left==NULL){
            temp->left=createNode(key);
            return;
        } else{
            queue[rear++]=temp->left;
        }

        if(temp->right==NULL){
            temp->right=createNode(key);
            return;
        } else{
            queue[rear++]=temp->right;
        }
    }
}

void traversal_bfs(struct Node *root){
    if(root==NULL){
        return ;
    }
    struct Node *queue[MAX];
    int front=0, rear=0;

    queue[rear++]=root;
    while(front<rear){
        struct Node *temp = queue[front++];
        printf("%d ", temp->data);

        if(temp->left)
            queue[rear++]=temp->left;
        if(temp->right)
            queue[rear++]=temp->right;
    }
    printf("\n");
}

int main(){
    struct Node* root = createNode(0);
    root->left = createNode(1);
    root->left->left = createNode(3);
    root->left->left->left = createNode(7);
    root->left->right = createNode(4);
    root->left->right->left = createNode(8);
    root->left->right->right = createNode(9);
    root->right = createNode(2);
    root->right->left = createNode(5);
    root->right->right = createNode(6);

    printf("Before insertion:\n");
    traversal_bfs(root);

    int key = 10;
    insertion(root, key);

    printf("After insertion:\n");
    traversal_bfs(root);

    return 0;
}