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

// print list
void print(struct Node *pointer){
    if(pointer == NULL) return;
    printf("%d ",pointer->data);
    print(pointer->link);
}

// print linked list in reverse order
void print_reverse(struct Node *pointer){
    if(pointer == NULL) return;
    print_reverse(pointer->link);
    printf("%d ",pointer->data);
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
    print_reverse(head);
    printf("\n");
    print(head);
}