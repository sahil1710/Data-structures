#include <stdio.h>
#include <string.h>
#define MAX 1000

int top = -1;

// push function

void push(char st[],char ch){
    if(top == MAX-1){
        printf("Error: stack overflow");
        return;
    }
    st[++top] = ch;
}

// pop function

void pop(){
    top--;
}

// top function

char Top(char st[]){
    return st[top];
}

int main(){
    int i, n;
    char str1[100] = "[{()}]";
    char st[100];
    n = strlen(str1);
    for(i=0;i<n;i++){
           
        if(str1[i]=='(' || str1[i]=='{' || str1[i]=='['){
            // Push the element in the stack
            push(st,str1[i]);
        }

        else if(str1[i]==')' || str1[i]=='}' || str1[i]==']'){
            //if top element of stack is opening bracket of str1[i]
            //pop the element from stack else break the loop
            if(top<0){
                top = -1;
                break;
            }
            else if(str1[i]==')'&& (Top(st)=='{'||Top(st)=='[')){
                top = -1;
                break;
            }
            else if(str1[i]=='{'&& (Top(st)=='('||Top(st)=='[')){
                top = -1;
                break;
            }
            else if(str1[i]=='['&& (Top(st)=='{'||Top(st)=='(')){
                top = -1;
                break;
            }
            else pop();
        }
    }

    printf(top<0 ? "parentheses are balanced":"parentheses are not balanced");
}

// output:
// parentheses are balanced
