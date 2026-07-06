#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

struct Node *createNode(int value){
    struct Node *newnode = (struct Node*)malloc(sizeof(struct Node));
    newnode -> data = value;
    newnode -> left = NULL;
    newnode -> right = NULL;
    return newnode;
}

struct Node *search_node(struct Node *root, int key){
    if(root==NULL)
        return NULL;
    if (root->data == key){
        return root;
    }

    struct Node *found = search_node(root->left, key);

    if (found!=NULL)
        return found;

    return search_node(root->right, key);
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

    int key = 4;

    if (search_node(root, key))
        printf("True");
    else
        printf("False");
}