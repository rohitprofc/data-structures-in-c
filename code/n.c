// Delete a node from CLL

#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *link;
} *header = NULL;

void create();
void deletion();
void display();

int main() {
    int choice;

    // Initialize header
    header = (struct node *)malloc(sizeof(struct node));
    if (!header) {
        printf("Memory allocation failed\n");
        return 1;
    }
    header->link = header;  // Initialize to point to itself (circular)

    while (1) {
        printf("\nEnter the choice of operation\n1. Create  2. Deletion  3. Display: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                create();
                break;
            case 2:
                deletion();
                break;
            case 3:
                display();
                break;
            default:
                exit(0);
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

    if (header->link != header) {
        newNode->link = header->link;
        header->link = newNode;
    } else {
        header->link = newNode;
        newNode->link = header;
    }
}

void deletion() {
    int position, key;
    struct node *ptr, *ptr1;  // Declare ptr1 here
    printf("Enter the position of deletion\n1. Beginning  2. Ending  3. At any position: ");
    scanf("%d", &position);

    if (header->link == header) {  // Check if the list is empty
        printf("\nCLL is empty, unable to perform deletion\n");
        return;
    }

    if (position == 1) {  // Deletion from the beginning
        ptr = header->link;
        header->link = ptr->link;
        printf("\nDeleted node is %d\n", ptr->data);
        free(ptr);
    } else if (position == 2) {  // Deletion from the end
        ptr = header;
        while (ptr->link != header) {
            ptr1 = ptr;
            ptr = ptr->link;
        }
        ptr1->link = header;  // Remove the last node
        printf("\nDeleted node is %d\n", ptr->data);
        free(ptr);
    } else if (position == 3) {  // Deletion at a specific position
        printf("\nEnter the data value: ");
        scanf("%d", &key);
        ptr = header->link;
        ptr1 = header;  // Initialize ptr1 to track the previous node

        while (ptr != header && ptr->data != key) {
            ptr1 = ptr;
            ptr = ptr->link;
        }

        if (ptr == header) {  // Node not found
            printf("\nNode with key was not found\n");
        } else {
            ptr1->link = ptr->link;  // Bypass the node to delete
            printf("\nDeleted node is %d\n", ptr->data);
            free(ptr);
        }
    } else {
        printf("Invalid position choice.\n");
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
