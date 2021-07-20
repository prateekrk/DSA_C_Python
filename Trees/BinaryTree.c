#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct BinaryTreeNode
{
    int data;
    struct BinaryTreeNode *left;
    struct BinaryTreeNode *right;
};
int tsize=0;
struct BinaryTreeNode *node=NULL;

struct BinaryTreeNode * createNode(int n){
    struct BinaryTreeNode *newNode=(struct BinaryTreeNode *) malloc(sizeof(struct BinaryTreeNode));
    newNode->data=n;
    newNode->left=newNode->right=NULL;
    return newNode;
}

struct BinaryTreeNode * insertAtNode(struct BinaryTreeNode * node,int n){

    if(node==NULL){
        return createNode(n);
    }
    else if(n<node->data){
        node->left=insertAtNode(node->left,n);
    }
    else{
        node->right=insertAtNode(node->right,n);
    }
    return node;
}

void inorder(struct BinaryTreeNode *node) {
  if (node != NULL) {
    inorder(node->left);
    printf("%d -> ", node->data);
    inorder(node->right);
  }
}

void preorder(struct BinaryTreeNode * node){
    if(node!=NULL){
        printf("%d ",node->data);
        preorder(node->left);
        preorder(node->right);
    }
}

void postorder(struct BinaryTreeNode * node){
    if(node!=NULL){
        postorder(node->left);
        postorder(node->right);
        printf("%d ",node->data);
    }
}

int sizeOfBinaryTree(struct BinaryTreeNode * node){
    if(node==NULL){
        return 0;
    }
    return (sizeOfBinaryTree(node->left)+1+sizeOfBinaryTree(node->right));
}

int findMax(struct BinaryTreeNode * node){
    int n=-9999999;
    // while(node){
    //     n=node->data;
    //     node=node->right;
    // }
    while(node){
        n=node->data;
        node=node->right;
    }
    return n;
}

bool search(struct BinaryTreeNode * node,int n){
    if(node==NULL){
        return 0;
    }
    if(n==node->data){
        return 1;
    }
    return search(node->left,n)+search(node->right,n);
}

int heightOfTree(struct BinaryTreeNode * node){
     int l,r;
    if(node==NULL){
        return 0;
    }
   else{
    l=heightOfTree(node->left);
    r=heightOfTree(node->right);
    if(l>r){
        return l+1;
    }
    else{
        return r+1;
    }
   }
}

int main(){
    struct BinaryTreeNode *root=NULL;
    root=insertAtNode(root,2);
    insertAtNode(root,1);
    // insertAtNode(root,2);
    insertAtNode(root,3);
    insertAtNode(root,4);
    insertAtNode(root,5);
    // insertAtNode(root,6);
    // insertAtNode(root,7);
    printf("%d\n",sizeOfBinaryTree(root));
    printf("\n------------preorder--------------\n");
    preorder(root);
    printf("\n------------inorder--------------\n");
    inorder(root);
    printf("\n------------postorder--------------\n");
    postorder(root);
    printf("\n Max Element:%d",findMax(root));
    printf("\n searchResult:%d",search(root,9));
    printf("\n Height:%d",heightOfTree(root));
}