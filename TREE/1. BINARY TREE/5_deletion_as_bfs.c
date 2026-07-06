#include <stdio.h>
#include <stdlib.h>
#define MAX 100

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

void deletedeepest(struct Node *root, struct Node *deepestnode){
    struct Node *queue[MAX];
    int front=0, rear=0;

    queue[rear++]=root;

    while(front<rear){
        struct Node *temp = queue[front++];

        if(temp->left){
            if(temp->left==deepestnode){
                free(temp->left);
                temp->left=NULL;
                return;
            }
            queue[rear++]=temp->left;
        }

        if(temp->right){
            if(temp->right==deepestnode){
                free(temp->right);
                temp->right=NULL;
                return;
            }
            queue[rear++]=temp->right;
        }
    }
}

void deletenode(struct Node *root, int key){
    if(root==NULL)
        return;
    
    struct Node *queue[MAX];
    int front=0, rear=0;
    queue[rear++]=root;

    struct Node *keynode=NULL;
    struct Node *temp=NULL;

    while (front<rear){
        temp=queue[front++];

        if(temp->data==key){
            keynode=temp;
        }

        if(temp->left){
            queue[rear++]=temp->left;
        }

        if(temp->right){
            queue[rear++]=temp->right;
        }
    }
    if(keynode!=NULL){
        keynode->data = temp->data;
        deletedeepest(root, temp);
    }
}

void traversal_bfs(struct Node *root){
    if(root==NULL){
        return ;
    }
    struct Node *queue[MAX];
    int front=0, rear=0;

    queue[rear++]=root;
    while(front<rear){
        struct Node *temp = queue[front++];
        printf("%d ", temp->data);

        if(temp->left)
            queue[rear++]=temp->left;
        if(temp->right)
            queue[rear++]=temp->right;
    }
    printf("\n");
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

    printf("Before deletion: \n");
    traversal_bfs(root);
    
    deletenode(root, 4);

    printf("After deletion: \n");
    traversal_bfs(root);

    return 0;
}