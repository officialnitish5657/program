#include <stdio.h>
#include <stdlib.h>

// Define structure for a node
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int newData) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = newData;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a new node at the beginning of the linked list
void insertAtBeginning(struct Node** head, int newData) {
    struct Node* newNode = createNode(newData);
    if (*head == NULL) {
        *head = newNode;
    } else {
        newNode->next = *head;
        (*head)->prev = newNode;
        *head = newNode;
    }
    printf("Inserted %d at the beginning.\n", newData);
}

// Function to delete the first occurrence of a key from the linked list
void deleteNode(struct Node** head, int key) {
    if (*head == NULL) {
        printf("List is empty. Cannot delete.\n");
        return;
    }
    struct Node* temp = *head;
    while (temp != NULL && temp->data != key) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("%d not found in the list. Cannot delete.\n", key);
        return;
    }
    if (temp->prev != NULL) {
        temp->prev->next = temp->next;
    } else {
        *head = temp->next;
    }
    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }
    printf("Deleted %d from the list.\n", key);
    free(temp);
}

// Function to display the linked list in forward direction
void displayForward(struct Node* head) {
    printf("Linked List (Forward): ");
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

// Function to display the linked list in backward direction
void displayBackward(struct Node* head) {
    if (head == NULL) {
        printf("Linked List (Backward): NULL\n");
        return;
    }
    // Go to the end of the list
    while (head->next != NULL) {
        head = head->next;
    }
    printf("Linked List (Backward): ");
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->prev;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;
    int choice, data;

    while (1) {
        printf("\n1. Insert Element\n");
        printf("2. Delete Element\n");
        printf("3. Display List (Forward)\n");
        printf("4. Display List (Backward)\n");
        printf("5. Exit\n");
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
                displayForward(head);
                break;
            case 4:
                displayBackward(head);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice! Please enter a valid option.\n");
        }
    }

    return 0;
}
