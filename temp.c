#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// Function to display the list
void displayList(int list[], int size) {
    printf("List: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", list[i]);
    }
    printf("\n");
}

// Function to insert an element into the list
void insertElement(int list[], int *size, int index, int element) {
    if (*size == MAX_SIZE) {
        printf("List is full. Cannot insert.\n");
        return;
    }
    if (index < 0 || index > *size) {
        printf("Invalid index. Cannot insert.\n");
        return;
    }
    // Shift elements to the right to make space for the new element
    for (int i = *size - 1; i >= index; i--) {
        list[i + 1] = list[i];
    }
    list[index] = element;
    (*size)++;
    printf("Inserted %d at index %d.\n", element, index);
}

// Function to delete an element from the list
void deleteElement(int list[], int *size, int index) {
    if (*size == 0) {
        printf("List is empty. Cannot delete.\n");
        return;
    }
    if (index < 0 || index >= *size) {
        printf("Invalid index. Cannot delete.\n");
        return;
    }
    printf("Deleted %d from index %d.\n", list[index], index);
    // Shift elements to the left to fill the gap created by deletion
    for (int i = index; i < *size - 1; i++) {
        list[i] = list[i + 1];
    }
    (*size)--;
}

int main() {
    int list[MAX_SIZE];
    int size = 0;
    int choice, index, element;

    printf("Enter the number of elements in the list: ");
    scanf("%d", &size);

    printf("Enter the elements of the list: ");
    for (int i = 0; i < size; i++) {
        scanf("%d", &list[i]);
    }

    while (1) {
        printf("\n1. Insert Element\n");
        printf("2. Delete Element\n");
        printf("3. Display List\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the index to insert: ");
                scanf("%d", &index);
                printf("Enter the element to insert: ");
                scanf("%d", &element);
                insertElement(list, &size, index, element);
                break;
            case 2:
                printf("Enter the index to delete: ");
                scanf("%d", &index);
                deleteElement(list, &size, index);
                break;
            case 3:
                displayList(list, size);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice! Please enter a valid option.\n");
        }
    }

    return 0;
}
