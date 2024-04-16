#include <stdio.h>
#include <stdlib.h>

// Define structure for a node
struct Node {
    int data;
    struct Node* next;
};

// Function to insert a new node at the beginning of the linked list
void insertAtBeginning(struct Node** head, int newData) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = newData;
    newNode->next = *head;
    *head = newNode;
    printf("Inserted %d at the beginning.\n", newData);
}

// Function to delete the first occurrence of a key from the linked list
void deleteNode(struct Node** head, int key) {
    struct Node* temp = *head;
    struct Node* prev = NULL;

    // If key is present at the head node
    if (temp != NULL && temp->data == key) {
        *head = temp->next;
        free(temp);
        printf("Deleted %d from the list.\n", key);
        return;
    }

    // Search for the key to be deleted, keep track of the previous node
    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    // If key is not present in the list
    if (temp == NULL) {
        printf("%d not found in the list.\n", key);
        return;
    }

    // Unlink the node containing the key
    prev->next = temp->next;
    free(temp);
    printf("Deleted %d from the list.\n", key);
}

// Function to display the linked list
void display(struct Node* head) {
    printf("Linked List: ");
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;
    int choice, data;

    while (1) {
        printf("\n1. Insert Element\n");
        printf("2. Delete Element\n");
        printf("3. Display List\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the element to insert: ");
                scanf("%d", &data);
                insertAtBeginning(&head, data);
                break;
            case 2:
                printf("Enter the element to delete: ");
                scanf("%d", &data);
                deleteNode(&head, data);
                break;
            case 3:
                display(head);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice! Please enter a valid option.\n");
        }
    }

    return 0;
}
