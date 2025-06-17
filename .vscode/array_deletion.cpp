#include<stdio.h>
void array_deletion(int arr[],int size,int index){
    //Check if the index is valid
    
        if(index<0 || index > size-1){
            printf("Invalid index\n");
            return;
        }

    
    //array deletion
    for(int i=index;i<size-1;i++){
        arr[i]=arr[i+1];

    }
    

}
void display_array(int arr[],int size){
    for(int i=0;i<size;i++)
printf("%d ",arr[i]);
}
int main(){
 int arr[10]={1, 2, 3, 4, 5};
    int size = 5; // Current size of the array
    int index = 2; // Index at which to insert the new element
    array_deletion(arr, size, index);
    display_array(arr, size-1); // Display the array after insertion
    return 0;
}