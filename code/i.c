// Create a SLL

#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *link;
};

struct node *header = NULL; // Initialize header to NULL

void creation();
void display();

int main() {
    int choice;
    
    while (1) {
        printf("\nEnter the choice of operation\n1. Creation    2. Display    3. Exit: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                creation();
                break;
            case 2:
                display();
                break;
            case 3:
                exit(0);  // Exit the program
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

void creation() {
    int dataElement;
    struct node *newNode, *ptr;

    // Allocate memory for a new node
    newNode = (struct node *)malloc(sizeof(struct node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        return;
    }

    printf("Enter data value to insert: ");
    scanf("%d", &dataElement);

    newNode->data = dataElement;
    newNode->link = NULL;

    if (header == NULL) {
        header = newNode;  // First node becomes the header
    } else {
        ptr = header;
        while (ptr->link != NULL) {
            ptr = ptr->link;  // Traverse to the last node
        }
        ptr->link = newNode;  // Link the new node at the end
    }

    printf("Node inserted successfully.\n");
}

void display() {
    struct node *ptr;

    if (header == NULL) {
        printf("The list is empty.\n");
        return;
    }

    printf("\nElements in the list are:\n");
    ptr = header;
    while (ptr != NULL) {
        printf("%d -> ", ptr->data);
        ptr = ptr->link;
    }
    printf("NULL\n");
}
