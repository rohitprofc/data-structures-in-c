// Insert a node into CLL

#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *link;
} *header = NULL;

void insertion();
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
        printf("\nEnter the choice of operation\n1. Insertion  2. Display  3. Exit: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                insertion();
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

void insertion() {
    int dataElement, key, position;
    printf("Enter data value to insert: ");
    scanf("%d", &dataElement);
    
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    if (!newNode) {
        printf("Memory allocation failed\n");
        return;
    }
    newNode->data = dataElement;

    printf("\nEnter the position of insertion\n1. Beginning  2. End  3. At any position: ");
    scanf("%d", &position);

    if (position == 1) {
        if (header->link == header) {  // List is empty
            newNode->link = header;
            header->link = newNode;
        } else {  // List is not empty
            newNode->link = header->link;
            header->link = newNode;
        }
    } else if (position == 2) {
        struct node *ptr = header;
        while (ptr->link != header) {
            ptr = ptr->link;  // Traverse to the last node
        }
        ptr->link = newNode;
        newNode->link = header;  // New node points to header
    } else if (position == 3) {
        printf("\nEnter key value: ");
        scanf("%d", &key);
        struct node *ptr = header;
        while (ptr->link != header && ptr->data != key) {
            ptr = ptr->link;  // Traverse until we find the key or come back to header
        }
        if (ptr->data == key) {
            newNode->link = ptr->link;
            ptr->link = newNode;  // Insert new node after the found node
        } else {
            printf("\nKey not available\n");
            free(newNode);  // Free allocated memory if not inserted
        }
    } else {
        printf("Invalid position choice.\n");
        free(newNode);  // Free allocated memory if not inserted
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
        printf(" %d ", ptr->data);
        ptr = ptr->link;  // Move to the next node
    } while (ptr != header->link);  // Stop when we circle back to the start
    printf("\n");
}
