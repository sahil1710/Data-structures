#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *link;
};

struct Node *head; //pointer to head node

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

// delete function
void delete(int loc){
    struct Node *temp1 = (struct Node*)malloc(sizeof(struct Node));
    temp1 = head;

    if(loc == 1){
       head = temp1->link;
       free(temp1);
    }

    else{
        loc -= 2;

        while (loc--)
        {
           temp1 = temp1->link; 
        }
        struct Node *temp = temp1->link;
        temp1->link = temp->link;
        free(temp);
    }
    
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

    while (size--)
    {
        int num;
        scanf("%d", &num);
        insert_end(num);
    }

    delete(3);
    
    print_list();
}