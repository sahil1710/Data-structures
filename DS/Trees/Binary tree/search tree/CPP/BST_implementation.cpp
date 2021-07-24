#include <bits/stdc++.h>
using namespace std;

// class for node

class bstNode
{
public:
    int data;
    bstNode* left;
    bstNode* right;

    bstNode(int num){
        data = num;
        left = NULL;
        right = NULL;
    }

};

//insert function

bstNode* insert(bstNode* pointer, int data){
    if(pointer == NULL){
        pointer = new bstNode(data);
    }

    else if(data <= pointer->data){
        pointer->left = insert(pointer->left, data);
    }

    else{
        pointer->right = insert(pointer->right, data);
    }

    return pointer;
}

//search function

bool search(bstNode* pointer, int data){
    if(pointer==NULL) return false;
    if(data == pointer->data) 
    return true;

    else if(data < pointer->data)
    return search(pointer->left, data);

    else
    return search(pointer->right, data);
} 

//main

int main(){
    bstNode* root = NULL;
    root = insert(root, 10);
    root = insert(root, 25);
    root = insert(root, 8);
    root = insert(root, 9);
    root = insert(root, 7);
    root = insert(root, 15);
    root = insert(root, 30);

    int num;
    cout<<"Enter a number: ";
    cin>>num;


    if(search(root, num) == true){
        cout<<"\nFound";
    }

    else{
        cout<<"\nNot found";
    }
}

// input: 8
// output: Found
