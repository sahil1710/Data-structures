#include <stdio.h>
#include <stdlib.h>

struct bstNode
{
    int data;
    struct bstNode* left;
    struct bstNode* right;
};

struct bstNode* bstNode(int data){
    struct bstNode* temp = (struct bstNode*)malloc(sizeof(struct bstNode));
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;   
} 

// insert function

struct bstNode* insert(struct bstNode* pointer, int data){
    if(pointer == NULL){
        pointer = bstNode(data);
    }

    else if(data <= pointer->data){
        pointer->left = insert(pointer->left, data);
    }

    else{
        pointer->right = insert(pointer->right, data);
    }

    return pointer;
}

// function to find max integer in BST

int findMax(struct bstNode* root){
    if(root == NULL){
        printf("Error: tree is empty");
        return 0;
    }

    while (root->right != NULL)
    {
        root = root->right;
    }

    return root->data;
}

// function to find min integet in BST

int findMin(struct bstNode* root){
    if(root == NULL){
        printf("Error: tree is empty");
        return 0;
    }

    while (root->left != NULL)
    {
        root = root->left;
    }

    return root->data;
}

//main

int main(){
    struct bstNode* root = NULL;
    root = insert(root, 10);
    root = insert(root, 25);
    root = insert(root, 8);
    root = insert(root, 9);
    root = insert(root, 7);
    root = insert(root, 15);
    root = insert(root, 30);

    printf("MAX: %d\n", findMax(root));
    printf("MIN: %d\n", findMin(root));
    
}

// output:
// MAX: 30
// MIN: 7
