#include <iostream>
using namespace std;

//node structure 
struct node{
    int data;
    node* prev;
    node* next;

    //node constructor
    node(int num){
        data = num;
        prev = NULL;
        next = NULL;
    }
};

node* head;          //head pointer
int nodeCount=0;     //node counter

//insert node at the end of doublylinked list
void insertAtEnd(int data){
    node* temp = new node(data);    //create node
    nodeCount++;
    if(head == NULL){
        head = temp;
        return;
    }

    node* temp1 = head;
    while (temp1->next!=NULL)   //going at last node
    {
        temp1 = temp1->next;    
    }
    
    // linking new node with list
    temp1->next = temp;         
    temp->prev = temp1;
}
//print list elements
void print(){
    node* temp = head;
    while (temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<"\n";
}

//print linked list in reverse order
void reversePrint(){
    node* temp = head;
    if(head==NULL){
        cout<<"list is empty";      //empty list,exit
        return;
    }

    while (temp->next!=NULL)        //going at last node
    {
        temp = temp->next;
    }

    //traverse in backward direction
    //by using prev pointer
    while (temp!=NULL)              
    {
        cout<<temp->data<<" ";         //print data;
        temp = temp->prev;
    }
}


int main(){
    head = NULL;
    insertAtEnd(1);
    insertAtEnd(2);
    insertAtEnd(3);
    cout<<"list: ";
    print();
    
    cout<<"Reversed list: ";
    reversePrint();
}

// output:
// list: 1 2 3 
// Reversed list: 3 2 1
