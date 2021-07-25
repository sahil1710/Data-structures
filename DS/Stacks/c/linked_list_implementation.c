#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *link;
};

struct Node *head;//pointer to head node

// insert a node at the front of linked list
void push(int num){
    struct Node *temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = num;
    temp->link = head;
    head = temp;
}

//pop function

void pop(){
    struct Node* temp = head;
    if(head==NULL) return;
    head = temp->link;
    free(temp);
}

// top function

int Top(){
    return head->data;
}

// empty function

int empty(){
    if(head==NULL){
        return 1;
    }
    return 0;
}

// print function

void print_stack(struct Node *temp){
    if(temp==NULL) return;
    print_stack(temp->link);
    printf("%d ", temp->data);
}

// main

int main(){

    head = NULL;
    push(1);
    push(2);
    push(3);
    push(4);
    printf("%d\n", Top());
    pop();
    push(4);
    push(5);

    print_stack(head);
}

// output:
// 4
// 1 2 3 4 5
