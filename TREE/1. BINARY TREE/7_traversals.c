#include <stdio.h>
#include <stdlib.h>
#define MAX 100

struct Node{
    int data;
    struct Node *left, *right;
};

struct Node *createNode(int value){
    struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));
    newnode -> data = value;
    newnode -> left = NULL;
    newnode -> right = NULL;
    return newnode;
}

struct Node *insertion(struct Node *root, int key){
    if (root==NULL)
        root = createNode(key);
        return root;
    
    struct Node *queue[MAX];
    int front=0, rear=0;

    queue[rear++]=root;

    while(front<rear){
        struct Node *temp = queue[front++];

        if(temp->left==NULL){
            temp->left=createNode(key);
            return root;
        } else{
            queue[rear++]=temp->left;
        }

        if(temp->right==NULL){
            temp->right=createNode(key);
            return root;
        } else{
            queue[rear++]=temp->right;
        }
    }
    return root;
}

void inorder(struct Node *root){
    if(root!=NULL){
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

void preorder(struct Node *root){
    if(root!=NULL){
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(struct Node *root){
    if(root!=NULL){
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

int main(){
    struct Node *root = createNode(0);
    root->left = createNode(1);
    root->left->left = createNode(3);
    root->left->left->left = createNode(7);
    root->left->right = createNode(4);
    root->left->right->left = createNode(8);
    root->left->right->right = createNode(9);
    root->right = createNode(2);
    root->right->left = createNode(5);
    root->right->right = createNode(6);

    printf("Inorder traversal  : ");
    inorder(root);

    printf("\n");

    printf("Preorder traversal : ");
    preorder(root);
    
    printf("\n");
    
    printf("Postorder traversal: ");
    postorder(root);

    return 0;
}