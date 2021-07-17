#include <bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node* link;

    Node(int num){
        data = num;
        link = NULL;
    }
};

Node* head;

void insert_node(int num){
    Node* temp = new Node(num);
    if(head==NULL){
        head = temp;
        return;
    }
    Node* temp1 = head;
    while (temp1->link!=NULL)
    {
        temp1 = temp1->link;
    }
    temp1->link = temp;  
}

void Reverse(){
    stack<Node*> S;
    Node* temp = head;
    while (temp!=NULL)
    {
        S.push(temp);
        temp = temp->link;
    }

    temp = S.top();
    head = temp;
    S.pop();

    while (!S.empty())
    {
        temp->link = S.top();
        S.pop();
        temp = temp->link;
    }
    temp->link = NULL;
}

void print(){
    Node* temp = head;
    while (temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp = temp->link;
    }
}


int main(){
    insert_node(1);
    insert_node(2);
    insert_node(3);
    insert_node(4);
    insert_node(5);

    Reverse();
    print();
}

// output : 5 4 3 2 1