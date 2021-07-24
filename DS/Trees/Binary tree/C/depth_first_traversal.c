#include <stdio.h>
#include <stdlib.h>

struct btNode
{
    int data;
    struct btNode* left;
    struct btNode* right;
};

struct btNode* bstNode(int data){
    struct btNode* temp = (struct btNode*)malloc(sizeof(struct btNode));
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;   
} 

// insert function

struct btNode* Insert(struct btNode* pointer, int data){
    if(pointer == NULL){
        pointer = bstNode(data);
    }

    else if(data <= pointer->data){
        pointer->left = Insert(pointer->left, data);
    }

    else{
        pointer->right = Insert(pointer->right, data);
    }

    return pointer;
}

// preorder traversal

void preorder(struct btNode* root){
    if(root == NULL){
        return;
    }
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

// pinorder traversal

void inorder(struct btNode* root){
    if(root == NULL){
        return;
    }
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

// postorder traversal

void postorder(struct btNode* root){
    if(root == NULL){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

// main

int main(){
    struct btNode* root = NULL;
    root = Insert(root, 10);
    root = Insert(root, 25);
    root = Insert(root, 8);
    root = Insert(root, 9);
    root = Insert(root, 7);
    root = Insert(root, 15);
    root = Insert(root, 30);

    printf("Preorder: ");
    preorder(root);

    printf("\nInorder: ");
    inorder(root);

    printf("\nPostorder: ");
    postorder(root);
}

// output: 
// Preorder: 10 8 7 9 25 15 30 
// Inorder: 7 8 9 10 15 25 30 
// Postorder: 7 9 8 15 30 25 10
