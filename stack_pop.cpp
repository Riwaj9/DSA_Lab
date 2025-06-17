#include<stdio.h>
int top=5;
int stack[5]={10,20,30,40,50};
int isEmpty(){
    if (top==0)
    return 1;
    else
    return 0;
}

void pop(){
    if(isEmpty()){
        printf("Error.Stack is empty.\n");
    }
    else{
        printf("%d\n",stack[top-1]);
        top--;
    }
}
int main(){
    pop();
    pop();
    pop();
    pop();
    pop();
    pop();
}