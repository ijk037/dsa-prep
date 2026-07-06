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

void inorder(struct Node *root){
    if(root==NULL)
        return;

    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

struct Node *insertion(struct Node *root, int key){
    if(root==NULL)
        return createNode(key);
    if(key<root->data)
        root->left = insertion(root->left, key);
    else if (key>root->data)
        root->right = insertion(root->right, key);
    return root;
}

struct Node *minimumNode(struct Node *root){
    while(root->left!=NULL)
        root=root->left;
    return root;
}

struct Node *deletion(struct Node *root, int key){
    if(root==NULL)
        return NULL;

    if(key<root->data)
        root->left = deletion(root->left, key);
    else if(key>root->data)
        root->right = deletion(root->right, key);
    else{
        if(root->left==NULL && root->right==NULL){
            free(root);
            return NULL;
        } else if(root->left==NULL){
            struct Node *temp = root->right;
            free(root);
            return temp;
        } else if(root->right == NULL){
            struct Node *temp = root->left;
            free(root);
            return temp;
        }
        struct Node *temp = minimumNode(root->right);
        root->data = temp->data;
        root->right = deletion(root->right, temp->data);
    }
    return root;
}

int main(){
    int arr[] = {10, 20, 30, 40, 50, 60};
    int n = sizeof(arr)/sizeof(arr[0]);

    struct Node *root = NULL;

    for(int i=0; i<n; i++){
        root=insertion(root, arr[i]);
    }

    printf("Original tree:\n");
    inorder(root);

    root = deletion(root, 40);
    printf("\n");

    printf("After deletion:\n");
    inorder(root);
    
    return 0;
}
