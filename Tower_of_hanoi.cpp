//Step 1 − Move n-1 disks from source to aux
//Step 2 − Move nth disk from source to dest
//Step 3 − Move n-1 disks from aux to dest

#include<stdio.h>
void hanoi(int n, char src,char dest,char aux){
    if(n==1){
        printf("Move disk 1 from %c to %c\n",src,dest);
    }
    else{
        hanoi(n-1,src,aux,dest);
        printf("Move disk %d from %c to %c\n",n,src,dest);
        hanoi(n-1,aux,dest,src);
    }

}
int main()
{
    int n=4;
    char src= 'A';
    char dest= 'B';
    char aux='C';
    hanoi(n,src,dest,aux);
}