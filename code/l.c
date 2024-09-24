// Create a CLL

#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *link;
} *header = NULL;

void create();
void display();

int main() {  // Changed from void main() to int main()
    int choice;

    // Initialize header
    header = (struct node *)malloc(sizeof(struct node));
    if (!header) {
        printf("Memory allocation failed\n");
        return 1;
    }
    header->link = header;  // Initialize to point to itself (circular)

    while (1) {
        printf("\nEnter the choice of operation\n1. Creation  2. Display  3. Exit: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                create();
                break;
            case 2:
                display();
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}

void create() {
    int dataElement;
    printf("Enter data value to insert: ");
    scanf("%d", &dataElement);

    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    if (!newNode) {
        printf("Memory allocation failed\n");
        return;
    }
    
    newNode->data = dataElement;

    if (header->link == header) {  // List is empty
        newNode->link = header;     // Link the new node to header
        header->link = newNode;     // Header points to the new node
    } else {
        struct node *last = header;
        // Find the last node
        while (last->link != header) {
            last = last->link;
        }
        last->link = newNode;  // Link last node to new node
        newNode->link = header; // New node points to header
    }
}

void display() {
    if (header->link == header) {
        printf("The list is empty.\n");
        return;
    }

    printf("\nElements in the list are:\n");
    struct node *ptr = header->link;  // Start from the first node
    do {
        printf("%d ", ptr->data);
        ptr = ptr->link;  // Move to the next node
    } while (ptr != header->link);  // Stop when we circle back to the start
    printf("\n");
}
