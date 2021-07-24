#include <bits/stdc++.h>
using namespace std;

// node class
class bstNode
{
public:
    int data;
    bstNode* left;
    bstNode* right;

    // Constructor to create a new node
    bstNode(int num){
        data = num;
        left = right = NULL;
    }
};

//insert function

bstNode* Insert(bstNode* pointer, int data){
    if(pointer == NULL){
        pointer = new bstNode(data);
    }

    else if(data<=pointer->data){
        pointer->left = Insert(pointer->left, data);
    }

    else{
        pointer->right = Insert(pointer->right, data);
    }

    return pointer;
}

// function to find max integer in BST

int findMax(bstNode* root){
    if(root == NULL){
        cout<<"Error: tree is empty";
        return 0;
    }

    while (root->right != NULL)
    {
        root = root->right;
    }

    return root->data;
}

// function to find min integet in BST

int findMin(bstNode* root){
    if(root == NULL){
        cout<<"Error: tree is empty";
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
    bstNode* root = NULL;
    root = Insert(root, 10);
    root = Insert(root, 25);
    root = Insert(root, 8);
    root = Insert(root, 9);
    root = Insert(root, 7);
    root = Insert(root, 15);
    root = Insert(root, 30);

    cout<<"MAX: "<<findMax(root)<<"\n";
    cout<<"MIN: "<<findMin(root)<<"\n";
}

// output:
// MAX: 30
// MIN: 7
