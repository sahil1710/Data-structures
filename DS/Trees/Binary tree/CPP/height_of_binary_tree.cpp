#include <bits/stdc++.h>
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

// insert function

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

// function to find height

int findHeight(btNode* root){
    if(root == NULL){
        return -1;
    }

    int leftHeight = findHeight(root->left);
    int rightHeight = findHeight(root->right);

    return max(leftHeight, rightHeight) + 1;
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
    root = Insert(root, 45);

    cout<<"Height of binary tree: "<<findHeight(root);
}

// output:- Height of binary tree: 3
