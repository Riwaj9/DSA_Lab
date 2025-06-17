#include<stdio.h>
int isFull(int top,int size){
    if(top==size-1)
    return 1;
    else
    return 0;
}
void push(int data,int*top,int stack[],int size){
    if(isFull(*top,size)){
        printf("Error.Stack is full.\n");
        }
    else{(*top)++;
        stack[*top]=data;
        printf("Successfully pushed into stack.\n");
        
    }
}
int main(){
    int size=5;
    int stack[size];
    int top=-1;
    push(10,&top, stack,size);
    push(20,&top, stack,size);
    push(30,&top, stack,size);
    push(40,&top, stack,size);
    push(50,&top, stack,size);
    push(60,&top, stack,size);
    for(int i=0;i<size;i++){
    printf("%d\t",stack[i]);
    }
}