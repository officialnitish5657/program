#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5

int front = -1, rear = -1;
int queue[MAX_SIZE];

// Function to check if the queue is full
int isFull() {
    return (front == 0 && rear == MAX_SIZE - 1) || (front == rear + 1);
}

// Function to check if the queue is empty
int isEmpty() {
    return front == -1;
}

// Function to insert an element into the circular queue
void enqueue(int item) {
    if (isFull()) {
        printf("Queue is full. Cannot enqueue.\n");
        return;
    }
    if (front == -1) {
        front = 0;
    }
    rear = (rear + 1) % MAX_SIZE;
    queue[rear] = item;
    printf("Inserted %d into the queue.\n", item);
}

// Function to delete an element from the circular queue
int dequeue() {
    if (isEmpty()) {
        printf("Queue is empty. Cannot dequeue.\n");
        return -1;
    }
    int deletedItem = queue[front];
    if (front == rear) {
        front = rear = -1;
    } else {
        front = (front + 1) % MAX_SIZE;
    }
    printf("Deleted %d from the queue.\n", deletedItem);
    return deletedItem;
}

// Function to display the elements in the circular queue
void display() {
    if (isEmpty()) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Elements in the queue are: ");
    int i = front;
    do {
        printf("%d ", queue[i]);
        i = (i + 1) % MAX_SIZE;
    } while (i != (rear + 1) % MAX_SIZE);
    printf("\n");
}

int main() {
    int choice, item;
    int num_elements;
    printf("Enter the number of elements to insert: ");
    scanf("%d", &num_elements);
    if (num_elements > MAX_SIZE) {
        printf("Number of elements exceeds maximum queue size. Exiting...\n");
        return 0;
    }
    printf("Enter the elements to insert: ");
    for (int i = 0; i < num_elements; ++i) {
        scanf("%d", &item);
        enqueue(item);
    }
    while (1) {
        printf("\n1. Insert Element\n");
        printf("2. Delete Element\n");
        printf("3. Display Queue\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter the element to insert: ");
                scanf("%d", &item);
                enqueue(item);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice! Please enter a valid option.\n");
        }
    }
    return 0;
}
