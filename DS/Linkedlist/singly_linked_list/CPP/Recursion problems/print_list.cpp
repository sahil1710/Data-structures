#include <iostream>
using namespace std;

class Node 
{
public:
    int data;
    Node* link;

    Node(int num){
        data = num;
        link = NULL;
    } 
};

Node* head; //pointer to head node

// insert node at the end of linked list
void insert_end(int num){
    Node* temp = new Node(num);

    if(head == NULL){
        head = temp;
        return;
    }

    Node* temp1 = head;
    while (temp1->link != NULL)
    {
        temp1 = temp1->link;
    }

    temp1->link = temp;   
}

// print list
void print(Node* pointer){
    if(pointer==NULL) return;
    cout<<pointer->data<<" ";
    print(pointer->link);
}

// print list in reverse order
void print_reverse(Node* pointer){
    if(pointer==NULL) return;
    print_reverse(pointer->link);
    cout<<pointer->data<<" ";
}

int main(){
    int size;
    cin>>size;
    head = NULL;
    while (size--)
    {
        int num;
        cin>>num;
        insert_end(num);
    }
    print_reverse(head);
    cout<<"\n";
    print(head); 
}

