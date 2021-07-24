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

// function to find height

int findHeight(struct btNode* root){
    if(root == NULL){
        return -1;
    }

    int leftHeight = findHeight(root->left);
    int rightHeight = findHeight(root->right);

    return (leftHeight>rightHeight?leftHeight:rightHeight) + 1;
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
    root = Insert(root, 45);

    printf("Height of binary tree: %d", findHeight(root));
}

// Height of binary tree: 3
