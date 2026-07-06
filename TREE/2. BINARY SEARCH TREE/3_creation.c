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
    int arr[] = {10, 20, 30, 40, 50, 60};
    int n = sizeof(arr)/sizeof(arr[0]);

    struct Node *root = NULL;

    for(int i=0; i<n; i++){
        root=insertion(root, arr[i]);
    }

    printf("Final Tree:\n");
    inorder(root);

    return 0;
}
