#include <stdio.h>
#include <string.h>
#define MAX 1000

int top = -1;   //top - store top pointer value of stack

// push function adds element on the top of stack
void push(char st[],char ch){
    if(top == MAX-1){
        printf("Error: stack overflow");
        return;
    }
    st[++top] = ch;
}

// pop function removes top most element in the stack
void pop(){
    if(top<0){
        printf("stack is empty");
        return;
    }
    top--;
}

// top function returns top element of stack
char Top(char st[]){
    if(top<0){
        printf("stack is empty");
        return '\0';
    }
    return st[top];
}

//empty function to check stack is empty or not
int empty(char st[]){
    if(top<0){
        return 1;
    }
    return 0;
};

// main
int main(){
    char string[100],result[100],stack[MAX];
    int i = 0;

    // taking input
    printf("Enter string:\n");
    scanf("%[^\n]s",string);

    //push all character of string from right to left in stack 
    while (string[i]!='\0')
    {
        push(stack, string[i]);
        i++;
    }

    /*pop all elements of stack one by one
    and store it in result array*/
    i = 0;
    while (!empty(stack))
    {
        result[i] = Top(stack);
        pop();
        i++;
    }

    //output: reversed string
    printf("\nReversed string:\n");
    i=0;
    while (result[i]!='\0')
    {
        printf("%c",result[i]);
        i++;
    }  
}

// input:
// HELLO

// output:
// OLLEH
