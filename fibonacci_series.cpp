#include<stdio.h>
int Fib(int n){
    if(n==0)
    return 0;
    else if (n==1)
    return 1;
    else 
    return Fib(n-1)+Fib(n-2);
}
int main(){
    int n;
    printf("Enter the number of terms: ");
    scanf("%d",&n);
    printf("The fibonacci series is:");
    for(int i=0;i<=n;i++){
        printf("%d\t",Fib(i));
    }
}