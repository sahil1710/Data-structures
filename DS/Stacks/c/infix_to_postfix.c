#include <stdio.h>
#include <string.h>
#include <ctype.h>
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

//input precedence function - f
int f(char ch)
{
    if (ch == '+' || ch == '-')
    {
        return 1;
    }
    else if (ch == '*' || ch == '/')
    {
        return 3;
    }
    else if (ch == '^')
    {
        return 6;
    }
    else if (isalnum(ch))
    {
        return 7;
    }
    else if (ch == '(')
    {
        return 9;
    }
    else if (ch == ')')
    {
        return 0;
    }
    else{
        return -1;
    } 
}

//stack precedence function - g
int g(char ch)
{
    if (ch == '+' || ch == '-')
    {
        return 2;
    }
    else if (ch == '*' || ch == '/')
    {
        return 4;
    }
    else if (ch == '^')
    {
        return 5;
    }
    else if (isalnum(ch))
    {
        return 8;
    }
    else if (ch == '(')
    {
        return 0;
    }
    else{
        return -1;
    }
}

//rank function - to check whether the character is a valid operator
int rank(char ch)
{
    if (ch == '^' || ch == '*' || ch == '/' || ch == '+' || ch == '-')
    {
        return -1;
    }
    else if (isalnum(ch))
    {
        return 1;
    }
    else{
        return -1;
    }
}

//infixToPostfix function converts infix expression to postfix expression
void infixtoPostfix(char *infix)
{
    char stack[MAX],postfix[100];
    int i, j, r;
    i = j = r = 0;
    
    push(stack,'(');              
    strcat(infix, ")");

    while (infix[i] != '\0')        //traversing through string
    {
        //popping greater precedence element from stack

        while (f(infix[i]) < g(Top(stack)))
        {
            postfix[j] = Top(stack);
            pop();
            r += rank(postfix[j]);
            j++;
            if (r < 1)
            {
                printf("INVALID!\n");
                return;
            }
        }

        //looking for matching parentheses
        if (f(infix[i]) != g(Top(stack)))
        {
            push(stack,infix[i]);
        }
        else
        {
            pop();
        }
        
        i++;
    }

    //checking whether the expression is valid
    if (top != -1 || r != 1)
    {
        printf("INVALID!\n");
        return;
    }
    else
    {
        //closing the postfix expression
        postfix[j] = '\0';
    }
    
    printf("\npostfix expression:\n");
    printf("%s",postfix);
}

int main(){
    char infix[100];

    // taking infix expression as string input
    printf("Enter infix expression:\n");
    scanf("%[^\n]s", infix);
    infixtoPostfix(infix);
}

// Input:
// a+b*(c^d-e)^(f+g*h) 

// Output:

// postfix expression:
// abcd^e-fgh*+^*+
