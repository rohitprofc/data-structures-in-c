// Insert a node into SLL

#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *link;
};

struct node *header = NULL;

void insertion();
void display();

int main() {
    int choice;

    while (1) {
        printf("\nEnter the choice of operation\n1. Insertion    2. Display    3. Exit: ");
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
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}

void insertion() {
    int dataElement, position, key;
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    struct node *ptr = header;
    
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        return;
    }

    printf("Enter data value to insert: ");
    scanf("%d", &dataElement);
    newNode->data = dataElement;
    newNode->link = NULL;

    printf("Enter position to insert\n1. Begin  2. End  3. After a specific element: ");
    scanf("%d", &position);

    if (position == 1) {  // Insert at the beginning
        newNode->link = header;
        header = newNode;
    } 
    else if (position == 2) {  // Insert at the end
        if (header == NULL) {  // Empty list case
            header = newNode;
        } else {
            while (ptr->link != NULL) {
                ptr = ptr->link;
            }
            ptr->link = newNode;
        }
    } 
    else if (position == 3) {  // Insert after a specific element
        printf("Enter key value after which to insert: ");
        scanf("%d", &key);
        
        while (ptr != NULL && ptr->data != key) {
            ptr = ptr->link;
        }

        if (ptr == NULL) {
            printf("Key value not found in the list\n");
        } else {
            newNode->link = ptr->link;
            ptr->link = newNode;
        }
    } 
    else {
        printf("Invalid position! Please try again.\n");
    }
}

void display() {
    struct node *ptr = header;

    if (ptr == NULL) {
        printf("The list is empty.\n");
        return;
    }

    printf("\nElements in the list are:\n");
    while (ptr != NULL) {
        printf("%d -> ", ptr->data);
        ptr = ptr->link;
    }
    printf("NULL\n");
}
