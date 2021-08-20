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
    cout<<"\n";
}

int main(){
    head = NULL;
    insertAtEnd(1);
    insertAtEnd(2);
    insertAtEnd(3);
    insertAtEnd(4);
    cout<<"List: ";
    print();

    //remove element
    remove(4);
    cout<<"List after removing element: ";
    print();
}

// output
// List: 1 2 3 4 
// List after removing element: 1 2 3 
