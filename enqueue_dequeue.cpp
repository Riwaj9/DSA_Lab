#include <stdio.h>
#define MAX 6

int Queue[MAX];
int front = 0;
int rear = -1;
int Count = 0;

bool isFull() {
    return Count == MAX;
}

bool isEmpty() {
    return Count == 0;
}

void insert(int data) {
    if (!isFull()) {
        if (rear == MAX - 1) {
            rear = -1;
        }
       Queue[++rear] = data;
        Count++;
    } else {
        printf("Queue is full.\n");
    }
}

int removeData() {
    if (!isEmpty()) {
        int data = Queue[front++];
        if (front == MAX) {
            front = 0;
        }
        Count--;
        return data;
    } else {
        printf("Queue is empty.\n");
        return -1;  
    }
}

int main() {
    int i;
    insert(3);
    insert(5);
    insert(9);
    insert(1);
    insert(12);
    insert(15);

    printf("Queue: ");
    for (i = 0; i < MAX; i++)
        printf("%d ", Queue[i]);

    int num = removeData();
    printf("\nElement removed: %d\n", num);

    printf("Updated Queue : ");
    while (!isEmpty()) {
        int n = removeData();
        printf("%d ", n);
    }

    return 0;
}
