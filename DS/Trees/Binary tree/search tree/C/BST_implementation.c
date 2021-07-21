
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

int search(struct bstNode* pointer, int data){
    if(pointer==NULL) return 0;
    if(data == pointer->data) 
    return 1;

    else if(data < pointer->data)
    return search(pointer->left, data);

    else
    return search(pointer->right, data);
} 

int main(){
    struct bstNode* root = NULL;
    root = insert(root, 10);
    root = insert(root, 25);
    root = insert(root, 8);
    root = insert(root, 9);
    root = insert(root, 7);
    root = insert(root, 15);
    root = insert(root, 30);

    int num;
    printf("Enter a number: ");
    scanf("%d", &num);

    if(search(root, num)){
        printf("\nFound");
    }

    else{
        printf("\nNot found");
    }
}
