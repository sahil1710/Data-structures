#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *link;
};

struct Node *head;//pointer to head node

// insert node at the end of linked list
void insert_end(int num){
    struct Node *temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = num;
    if(head == NULL){
        temp->link = NULL;
        head = temp;
    }

    else{
        temp->link = NULL;
        struct Node *temp1 = head;
        while (temp1->link!=NULL)
        {
            temp1 = temp1->link;
        }

        temp1->link = temp;  
    } 
}

// reverse funtion
void reverse(){
    struct Node *temp,*prev,*next;
    temp = head;
    prev = NULL;

    while (temp!=NULL)
    {
        next = temp->link;
        temp->link = prev;
        prev = temp;
        temp = next;
    }
    head = prev; 
}

// print list
void print_list(){
    struct Node *temp = head;
     while (temp!=NULL)
     {
        printf("%d ", temp->data);
        temp = temp->link;
     }
}


int main(){
    int size;
    scanf("%d", &size);

    head = NULL;

    while (size--)
    {
        int num;
        scanf("%d", &num);
        insert_end(num);
    }
    reverse();
    print_list();
}