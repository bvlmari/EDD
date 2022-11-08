//Creating and traversing a binary tree
//preorder, inorder, and postorder
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


struct BinaryTreeNode{
    int data;
    struct BinaryTreeNode *left;
    struct BinaryTreeNode *right;
};

void PreOrder(struct BinaryTreeNode *root){
    if(root){
        printf("%d",root->data);
        PreOrder(root->left);
        PreOrder(root->right);
    }
}

void PreOrderNonrecursive(struct BinaryTreeNode *root){
    struct Stack *S = CreateStack();
    while(1){
        while(root){
            //Process current node
            printf("%d", root->data);
            Push(S,root);
            //If left subtree exists, add to stack
            root = root -> left;
        }
        if(IsEmptyStack(S))
            break;
        root = Pop(S);
        //Indicates completion of left subtree and current node, now go to right subtree
        root = root->right;
    }
    DeleteStack(S);
}

void InOrderNonRecursive(struct BinaryTreeNode *root){
    struct Stack *S = CreateStack();
    while(1){
        while(root){
            Push(S,root);
            //Got left subtree and keep on adding to stack
            root = root->left;
        }
        if(IsEmptyStack(S))
            break;
        root = Pop(S);
        printf("%d",root->data); //After popping, process the current node
        //Indicates completion of left subtree and current node, now go into right subtree
        root=root->right;
    }
    DeleteStack(S);
}

void PostOrderNonRecursive(struct BinaryTreeNode *root){
    struct SimpleArrayStack *S = CreateStack();
    struct BinaryTreeNode *previous = NULL;
    do{
        while(root!=NULL){
            Push(S,root);
            root = root->left;
        }
        while(root == NULL && !IsEmptyStack(S)){
            root = Top(S);
            if(root->right==NULL||root->right==previous){
                printf("%d",root->data);
                Pop(S);
                previous = root;
                root = NULL;
            }
            else
                root = root->right;
        }
    }while(!IsEmptyStack(S));
}

void LevelOrder(struct BinaryTreeNode *root){
    struct BinaryTreeNode *temp;
    struct Queue *Q = CreateQueue();
    if(!root)
        return;
    EnQueue(Q,root);
    while(!IsEmptyQueue(Q)){
        temp = DeQueue(Q);
        //Process current node
        printf("%d",temp->data);
        if(temp->left)
            EnQueue(Q, temp->left);
        if(temp->right)
            EnQueue(Q, temp->right);
    }
    DeleteQueue(Q);
}




