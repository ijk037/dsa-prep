#include<stdio.h>
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

struct Node *searching(struct Node *root, int key){
    if(root==NULL || root->data==key)
        return root;
    if(key<root->data)
        return searching(root->left, key);
    else
        return searching(root->right, key);
}

int main(){
    struct Node *root = createNode(50);
    root->left = createNode(30);
    root->right = createNode(70);
    root->left->left = createNode(20);
    root->left->right = createNode(40);
    root->right->left = createNode(60);
    root->right->right = createNode(80);
    
    int key=30;
    struct Node *result = searching(root, key);

    if (result!=NULL)
        printf("%d found in BST.\n", key);
    else
        printf("Key not found.\n");
    return 0;
}
