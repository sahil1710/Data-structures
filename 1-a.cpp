#include <iostream>
using namespace std;

struct employee{
    int id;
    string name;
    int salary;
    string address;
};

struct node
{
    struct employee emp;
    struct node* link;
};

node* head;

void add(){
    node*temp = new node();
    cout<<"Enter id:"<<endl;
    cin>>temp->emp.id;
    cout<<"\n";

    cout<<"Enter name:"<<endl;
    cin>>temp->emp.name;
    cout<<"\n";

    cout<<"Enter salary:"<<endl;
    cin>>temp->emp.salary;
    cout<<"\n";

    cout<<"Enter address:"<<endl;
    cin>>temp->emp.address;
    cout<<"\n";

    temp->link = NULL;
    if(head==NULL){
        head = temp;
        cout<<"Employee's details added successfully.\n"; 
        return;
    }
    node* temp1 = head;

    while (temp1->link!=NULL)
    {
        temp1 = temp1->link;
    }
    temp1->link = temp;
    cout<<"Employee's details added successfully.\n"; 
}

void view(){
    int id;
    cout<<"Enter Id:"<<endl;
    cin>>id;
    system("clear");
    node* temp1 = head;
    while (temp1!=NULL && temp1->emp.id != id)
    {
        temp1 = temp1->link;
    }
    if(temp1 == NULL){
        cout<<"Id not found.\n";
        return;
    }
    cout<<"-----------------\n";
    cout<<"\n";
    cout<<"Id     : "<<temp1->emp.id<<endl;
    cout<<"Name   : "<<temp1->emp.name<<endl;
    cout<<"Salary : "<<temp1->emp.salary<<endl;
    cout<<"Address: "<<temp1->emp.address<<endl;
    cout<<"\n";
    cout<<"-----------------\n";
}

void print(){
    if(head == NULL){
        cout<<"please enter employee's details first."<<endl;
        return;
    }
    cout<<"-----------------\n";
    node* temp1 = head;
    while(temp1!=NULL){

        cout<<"Id     : "<<temp1->emp.id<<endl;
        cout<<"Name   : "<<temp1->emp.name<<endl;
        cout<<"Salary : "<<temp1->emp.salary<<endl;
        cout<<"Address: "<<temp1->emp.address<<endl;
        cout<<"\n";
        cout<<"-----------------\n";
        temp1 = temp1->link;
    }
}

void Delete(){
    int id;
    cout<<"Enter id of employee:"<<endl;
    cin>>id;

    system("clear");
    
    node* temp1 = head;

    while (temp1!=NULL && temp1->emp.id != id)
    {
        temp1 = temp1->link;
    }

    if(temp1 == head){
        head = temp1->link;
        delete(temp1);
        cout<<"Employee's details deleted successfully"<<endl;
        return;
    }

    else if(temp1 == NULL){
        cout<<"Id not found.\n";
        return;
    }

    node* temp2 = head;
    while (temp2->link != temp1)
    {
        temp2 = temp2->link;
    }

    temp2->link = temp1->link;
    cout<<"Employee's details deleted successfully"<<endl;
    delete(temp1);
}


int main(){
    int num;
    char ch;
    start:
    cout<<"1. Add employee's details"<<endl;
    cout<<"2. view employee's details"<<endl;
    cout<<"3. Delete employee's details"<<endl;
    cout<<"4. View all employee's details"<<endl;
    cout<<"5. Exit"<<endl;
    cout<<"\n";

    cout<<"Enter your choice:"<<endl;
    cin>>num;

    switch (num)
    {
    case 1:
        system("clear");
        add();
        cout<<"Type Y to exit:"<<endl;
        cin>>ch;
        if(ch=='Y')
        {system("clear");
        goto start;}
        break;

    case 2:
        system("clear");
        view();
        cout<<"Type Y to exit:"<<endl;
        cin>>ch;
        if(ch=='Y')
        {system("clear");
        goto start;}
        break;

    case 3:
        system("clear");
        Delete();
        cout<<"Type Y to exit:"<<endl;
        cin>>ch;
        if(ch=='Y')
        {system("clear");
        goto start;}
        break;

    case 4:
        system("clear");
        print();
        cout<<"Type Y to exit:"<<endl;
        cin>>ch;
        if(ch=='Y')
        {system("clear");
        goto start;}
        break;
    
    case 5:
        return 0;
    
    default:
        break;
    }
    return 0;
}