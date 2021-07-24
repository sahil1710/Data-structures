#include <iostream>
using namespace std;

// node class

class btNode
{
public:
    int data;
    btNode* left;
    btNode* right;
    
    // Constructor to create a new node
    btNode(int num){
        data = num;
        left = right = NULL;
    }
};

//insert function

btNode* Insert(btNode* pointer, int data){
    if(pointer == NULL){
        pointer = new btNode(data);
    }

    else if(data<=pointer->data){
        pointer->left = Insert(pointer->left, data);
    }

    else{
        pointer->right = Insert(pointer->right, data);
    }

    return pointer;
}

// preorder traversal

void preorder(btNode* root){
    if(root == NULL){
        return;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

// pinorder traversal

void inorder(btNode* root){
    if(root == NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

// postorder traversal

void postorder(btNode* root){
    if(root == NULL){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}

// main

int main(){
    btNode* root = NULL;
    root = Insert(root, 10);
    root = Insert(root, 25);
    root = Insert(root, 8);
    root = Insert(root, 9);
    root = Insert(root, 7);
    root = Insert(root, 15);
    root = Insert(root, 30);

    cout<<"Preorder: ";
    preorder(root);

    cout<<"\nInorder: ";
    inorder(root);

    cout<<"\nPostorder: ";
    postorder(root);
}

// output: 
// Preorder: 10 8 7 9 25 15 30 
// Inorder: 7 8 9 10 15 25 30 
// Postorder: 7 9 8 15 30 25 10
