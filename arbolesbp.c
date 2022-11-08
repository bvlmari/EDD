//Creating and traversing a binary tree
//preorder, inorder, and postorder
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// self-referential structure
struct treeNode{
    struct treeNode *leftPtr; // pointer to left subtree
    int data; // node value
    struct treeNode *rightPtr; // pointer to right subtree
};

typedef struct treeNode TreeNode; //synonym for struct treeNode
typedef TreeNode *TreeNodePtr; //synonym for TreeNode *

//Prototypes
void insertNode(TreeNodePtr *treePtr, int value);
void inOrder(TreeNodePtr treePtr);
void preOrder(TreeNodePtr treePtr);
void postOrder(TreeNodePtr treePtr);

int main(void){
    TreeNodePtr rootPtr = NULL; //tree initially empty
    srand(time(NULL));
    puts("The numbers being placed in the tree are:");

    //Insert random values between 0 and 14 in the tree
    for(int i=1;i<=10;++i){
        int item=rand()%15;
        printf("%3d",item);
        insertNode(&rootPtr,item);
    }
    //Traverse the tree preOrder
    puts("\n\nThe preOrder traversal is:");
    preOrder(rootPtr);

    //Traverse the tree inOrder
    puts("\n\nThe inOrder traversal is:");
}

void PreOrder(struct BinaryTreeNode *root){
    if(root){
        printf("%d", root->data);
        PreOrder(root->left);
        PreOrder(root->right);
    }
}

void InOrder(struct BinaryTreeNode *root){
    if(root){
        InOrder(root->left);
        printf("%d",root->data);
        InOrder(root->right);
    }
}

void PostOrder(struct BinaryTreeNode *root){
    if(root){
        PostOrder(root->left);
        PostOrder(root->right);
        printf("%d",root->data);
    }
}