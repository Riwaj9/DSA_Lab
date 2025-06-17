#include<stdio.h>
void array_insertion(int arr[], int size, int index, int element){
    //Check if the index is valid
    
        if(index<0 || index > size-1){
            printf("Invalid index\n");
            return;
        }
    
        //Shift elements to the right
        for(int i=size-1; i>=index; i--){
            arr[i+1] = arr[i];
        }
        //Insert the element at the specified index
        arr[index] = element;
        //Increment the size of the array
       
    
}
void display(int arr[], int size) {
    for(int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
 int main()
{
    int arr[10]={1, 2, 3, 4, 5};
    int size = 5; // Current size of the array
    int index = 2; // Index at which to insert the new element
    int element = 10; // Element to be inserted
    array_insertion(arr, size, index, element);
    display(arr, size + 1); // Display the array after insertion
    return 0;
}