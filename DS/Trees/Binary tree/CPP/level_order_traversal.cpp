#include <iostream>
#include <queue>
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

// levelorder traversal

void levelOrder(btNode* root){
    if(root == NULL){
        cout<<"Tree is empty";
        return;
    }

    queue<btNode*> Q;
    Q.push(root);

    while (!Q.empty())
    {
        btNode* node = Q.front();
        cout<<node->data<<" ";

        if(node->left!=NULL){Q.push(node->left);}
        if(node->right!=NULL){Q.push(node->right);}
        Q.pop();
    }
}

//main

int main(){
    btNode* root = NULL;
    root = Insert(root, 10);
    root = Insert(root, 25);
    root = Insert(root, 8);
    root = Insert(root, 9);
    root = Insert(root, 7);
    root = Insert(root, 15);
    root = Insert(root, 30);

    levelOrder(root);
}

// output: 10 8 25 7 9 15 30
