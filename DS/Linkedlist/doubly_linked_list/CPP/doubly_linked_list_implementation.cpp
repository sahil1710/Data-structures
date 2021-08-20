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
    if(index==1||index>nodeCount){
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

//delete node 
void remove(int index){
    //check index value
    //if index is invalid then exit
    if(index<0||index>nodeCount){
        cout<<"Invalid index";
        return;
    }
    node* temp = head;
    if(index==1){
        head = temp->next;
        head->prev = NULL;
        free(temp);
        return;
    }
    
    index -= 1;
    while (index--)           //going at index node
    {
        temp = temp->next;
    }

    if(temp->next!=NULL){
        temp->next->prev = temp->prev;
    }

    if(temp->prev!=NULL){
        temp->prev->next = temp->next;
    }

    free(temp);
    nodeCount--;
}

//print list elements
void print(){
    node* temp = head;
    while (temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}

int main(){
    head = NULL;
    insertAtEnd(1);
    insertAtEnd(2);
    insertAtEnd(3);
    insertAtEnd(4);
    insert(2,6);
    remove(5);
    print();
}

// output
// 1 6 2 3 
