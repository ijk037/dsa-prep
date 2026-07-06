#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *left, *right;
};

struct Node *createNode(int value){
    struct Node *newnode = (struct Node*)malloc(sizeof(struct Node));
    newnode->data = value;
    newnode->left = NULL;
    newnode ->right = NULL;
    return newnode;
}

struct Node *findparent(struct Node *root, struct Node *parent, int key){
    if (root==NULL)
        return NULL;
    
    if(root->data == key)
        return parent;
    
    struct Node *temp = findparent(root->left, root, key);
    if(temp!=NULL)
        return temp;
    return findparent(root->right, root, key);
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

    int key = 7;

    struct Node *parent = findparent(root, NULL, key);

    if (parent==NULL)
        printf("Nill");
    else
        printf("Parent of %d = %d", key, parent->data);
}