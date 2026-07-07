#include <stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *left, *right;
    int height;
};

struct Node *createNode(int value){
    struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));
    newnode -> data = value;
    newnode -> left = NULL;
    newnode -> right = NULL;
    newnode -> height = 1;
    return newnode;
}

int max(int a, int b){
    return(a>b)?a:b;
}

int tree_height(struct Node *root){
    if(root==NULL)
        return 0;
    return root->height;
}

int balance_factor(struct Node *root){
    if(root==NULL)
        return 0;
    return tree_height(root->left)-tree_height(root->right);
}

struct Node *leftrotation(struct Node *x){
    struct Node *y = x->right;
    struct Node *z = y->left;

    y->left = x;
    x->right = z;

    x->height = max(tree_height(x->left), tree_height(x->right))+1;
    y->height = max(tree_height(y->left), tree_height(y->right))+1;

    return y;
}

struct Node *rightrotation(struct Node *y){
    struct Node *x = y->left;
    struct Node *z = x->right;

    x->right = y;
    y->left = z;

    y->height = max(tree_height(y->left), tree_height(y->right))+1;
    x->height = max(tree_height(x->left), tree_height(x->right))+1;

    return x;
}

struct Node *minNode(struct Node *root){
    struct Node *current = root;
    while (current->left!=NULL){
        current = current->left;
    }
    return current;
}

struct Node *deletion(struct Node *root, int key){
    if(root==NULL)
        return NULL;
    
    if(key<root->data)
        root->left = deletion(root->left, key);
    else if(key > root->data)
        root->right = deletion(root->right, key);
    else{
        if(root->left==NULL || root->right == NULL){
            struct Node *temp;
            if(root->left)
                temp=root->left;
            else
                temp=root->right;
            if(temp==NULL){
                free(root);
                return NULL;
            }
            *root=*temp;
            free(temp);
        } else{
            struct Node *temp = minNode(root->right);
            root->data=temp->data;
            root->right = deletion(root->right, temp->data);

        }
    }
    if(root==NULL)
        return NULL;
    root->height=1+max(tree_height(root->left), tree_height(root->right));

    int balance = balance_factor(root);

    if(balance>1 && balance_factor(root->left)>=0)
        return rightrotation(root);
    if(balance>1 && balance_factor(root->left)<0){
        root->left = leftrotation(root->left);
        return rightrotation(root);
    }
    if(balance<-1 && balance_factor(root->right)<=0)
        return leftrotation(root);
    if(balance<-1 && balance_factor(root->right)>0){
        root->left = rightrotation(root->right);
        return leftrotation(root);
    }
    return root;
}

struct Node *insertion(struct Node *root, int key){
    if(root==NULL)
        return createNode(key);
    
    if(key<root->data)
        root->left = insertion(root->left, key);
    else if(key>root->data)
        root->right = insertion(root->right, key);
    else
        return root;
    
    root->height = 1+max(tree_height(root->left), tree_height(root->right));

    int balance = balance_factor(root);

    if(balance>1 && key<root->left->data)
        return rightrotation(root);
    if(balance<-1 && key>root->right->data)
        return leftrotation(root);
    if(balance>1&&key>root->left->data){
        root->left = leftrotation(root->left);
        return rightrotation(root);
    }
    if(balance<-1&&key<root->right->data){
        root->right = rightrotation(root->right);
        return leftrotation(root);
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
    struct Node *root = NULL;
    int arr[] = {50, 30, 70, 20, 40, 60, 80, 10};
    int n = sizeof(arr)/sizeof(arr[0]);

    for (int i = 0; i < n; i++)
        root = insertion(root, arr[i]);
    
    printf("Before deletion:\n");
    inorder(root);

    root = deletion(root, 50);
    printf("\n");

    printf("After deletion:\n");
    inorder(root);
    
    return 0;
}