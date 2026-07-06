#include <stdio.h>
#include <stdlib.h>
#define MAX_LEVEL 100
#define MAX_NODE 100

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

int levelorder[MAX_LEVEL][MAX_NODE];
int count[MAX_LEVEL]={0};

void traversal_bfs(struct Node *root, int level){
    if(root==NULL){
        return ;
    }
    levelorder[level][count[level]++]=root->data;

    traversal_bfs(root->left, level+1);
    traversal_bfs(root->right, level+1);
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

    traversal_bfs(root, 0);

    for(int i=0; i<MAX_LEVEL && count[i]!=0; i++){
        printf("Level %d: ", i);
        for (int j=0; j<count[i]; j++){
            printf("%d ", levelorder[i][j]);
        }
        printf("\n");
    }
    return 0;
}