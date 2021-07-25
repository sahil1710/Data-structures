#include <stdio.h>
#define MAX 100000
struct stack
{
    int stack[MAX];
};

int top = -1;

// push function

void push(struct stack* s,int num){
    if(top == MAX-1){
        printf("Error: stack overflow");
        return;
    }
    s->stack[++top] = num;
}

// pop function

void pop(){
    if(top == -1){
        printf("stack is empty");
        return;
    }
    top--;
}

// top function

int Top(struct stack* s){
    return s->stack[top];
}

// empty function

int empty(struct stack s){
    if(top==-1){
        return 1;
    }
    return 0;
}

// main

int main(){
    struct stack s;

    push(&s, 1);
    push(&s, 2);
    push(&s, 3);
    push(&s, 4);
    pop();
    push(&s, 4);
    push(&s, 5);

    if(!empty(s)){
        pop();
    }
    
    for(int i=0; i<=top; i++){
        printf("%d ", s.stack[i]);
    }
     
}

// output:
// 1 2 3 4
