#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *left, *right;
    int height;
};

struct Node *createNode(int value){
    struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));
    newnode ->data = value;
    newnode -> left = NULL;
    newnode -> right = NULL;
    newnode -> height = 1;
    return newnode;
}

int tree_height(struct Node *root){
    if(root==NULL)
        return 0;
    return root->height;
}

int max(int a, int b){
    return (a>b)?a:b ;
}

int balance_factor(struct Node *root){
    if (root==NULL)
        return 0;
    return tree_height(root->left)-tree_height(root->right);
}

struct Node *leftrotation(struct Node *x){
    struct Node *y = x->right;
    struct Node *z = y->left;

    y->left = x;
    x->right = z;

    x->height = 1+max(tree_height(x->left), tree_height(x->right));
    y->height = 1+max(tree_height(y->left), tree_height(y->right));

    return y;
}

struct Node *rightrotation(struct Node *y){
    struct Node *x = y->left;
    struct Node *z = x->right;

    x->right = y;
    y->left = z;

    x->height = 1+max(tree_height(x->left), tree_height(x->right));
    y->height = 1+max(tree_height(y->left), tree_height(y->right));

    return x;
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

    if(balance>1 && key<root->left->data)                                   //LL
        return rightrotation(root);
    if(balance>1 && key>root->left->data){                                  //LR
        root->left = leftrotation(root->left);
        return rightrotation(root);
    }

    if(balance<-1 && key>root->right->data)                                 //RR
        return leftrotation(root);
    if(balance<-1 && key<root->right->data){                                //RL
        root->right = rightrotation(root->right);
        return leftrotation(root);
    }

    return root;
}

struct Node *deletion(struct Node *root){
    //......................................................
}

void inorder(struct Node *root){
    if(root==NULL)
        return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

int main(){
    int arr[] = {1, 2, 3, 4, 5, 7};
    int n = sizeof(arr)/sizeof(arr[0]);

    struct Node *root = NULL;

    for(int i=0; i<n; i++)
        root = insertion(root, arr[i]);
    
    printf("Tree:\n");
    inorder(root);

    return 0;
}