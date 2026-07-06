#include <stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *left, *right;
};

struct Node *createNode(int value){
    struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));
    newnode ->data = value;
    newnode -> left = NULL;
    newnode -> right = NULL;
    return newnode;
}

struct Node *insertion(struct Node *root, int key){
    if (root==NULL)
        return createNode(key);
    
    if (key < root->data){
        root->left=insertion(root->left, key);
    } else if(key>root->data){
        root ->right = insertion(root->right, key);
    }
    return root;
}

void inorder(struct Node *root){
    if(root==NULL)
        return;

    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
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

    printf("Original tree:\n");
    inorder(root);

    printf("\n");

    int key=10;
    insertion(root, key);

    printf("After insertion:\n");
    inorder(root);

    return 0;
}
