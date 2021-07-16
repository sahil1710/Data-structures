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

// insert a node at the front of linked list

void insert_head(int num){
    struct Node *temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = num;
    if(head == NULL){
        temp->link = NULL;
    }

    else{
        temp->link = head;
    }
    head = temp;
}

// insert a node at given position

void insert_nth(int num,int loc){
    struct Node *temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = num;

    if(loc == 1){
        temp->link = NULL;
        head = temp;
    }

    else{
        loc -= 2;
        struct Node *temp1 = head;
        while (loc--)
        {
            temp1 = temp1->link;
        }
        temp->link = temp1->link;
        temp1->link = temp; 
    }
}

// print

void print_list(){
    struct Node *temp = head;
    while (temp!=NULL)
    {
        printf("%d ", temp->data);
        temp = temp->link;
    }
}

// main

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

    insert_head(40);

    insert_nth(50,3);

    print_list();
}
