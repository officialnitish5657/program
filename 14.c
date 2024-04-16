#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5

int stack[MAX_SIZE];
int top = -1;

// Function to check if the stack is full
int isFull() {
    return top == MAX_SIZE - 1;
}

// Function to check if the stack is empty
int isEmpty() {
    return top == -1;
}

// Function to push an element onto the stack
void push(int item) {
    if (isFull()) {
        printf("Stack is full. Cannot push.\n");
        return;
    }
    stack[++top] = item;
    printf("Pushed %d onto the stack.\n", item);
}

// Function to pop an element from the stack
int pop() {
    if (isEmpty()) {
        printf("Stack is empty. Cannot pop.\n");
        return -1;
    }
    int poppedItem = stack[top--];
    printf("Popped %d from the stack.\n", poppedItem);
    return poppedItem;
}

// Function to display the elements in the stack
void display() {
    if (isEmpty()) {
        printf("Stack is empty.\n");
        return;
    }
    printf("Elements in the stack are: ");
    for (int i = 0; i <= top; ++i) {
        printf("%d ", stack[i]);
    }
    printf("\n");
}

int main() {
    int num_elements, item;
    printf("Enter the number of elements to push onto the stack: ");
    scanf("%d", &num_elements);
    if (num_elements > MAX_SIZE) {
        printf("Number of elements exceeds maximum stack size. Exiting...\n");
        return 0;
    }
    printf("Enter the elements to push onto the stack: ");
    for (int i = 0; i < num_elements; ++i) {
        scanf("%d", &item);
        push(item);
    }
    int choice;
    while (1) {
        printf("\n1. Push Element\n");
        printf("2. Pop Element\n");
        printf("3. Display Stack\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter the element to push: ");
                scanf("%d", &item);
                push(item);
                break;
            case 2:
                pop();
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
