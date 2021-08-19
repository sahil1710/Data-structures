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

//insert node at the front of doublylinked list
void insertAtHead(int data){
    node* temp = new node(data);    //create node
    nodeCount++;
    if(head==NULL){
        head = temp;
        return;
    }
    // linking new node with list
    head->prev = temp;
    temp->next = head;
    head = temp;                //changing head pointer
}

void insert(int index,int data){
    //check index value
    //if index is invalid then exit
    if(index==1||index>=nodeCount){
        cout<<"Invalid index";
        return;
    }

    // else create node
    node* temp = new node(data);
    index -=2;

    node* temp1 = head;
    while (index--)              //going at (index-1) node
    {
        temp1 = temp1->next;
    }

    // linking new node with list
    temp->next = temp1->next;
    temp->prev = temp1;
    temp1->next = temp;
    nodeCount++;
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
    insert(2,2);
    insertAtEnd(3);
    reversePrint();
}

// output
// 3 2 1 
