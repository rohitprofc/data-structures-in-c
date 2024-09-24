// Insert a node into DLL

#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *llink;
    struct node *rlink;
} *header, *newNode, *ptr;

void insert();
void display();

int main() {
    int choice;

    // Initialize header node
    header = (struct node *)malloc(sizeof(struct node));
    header->rlink = NULL;
    header->llink = NULL;

    while (1) {
        printf("\nEnter choice: 1.insert, 2.display, 3.exit\n");
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            insert();
            break;
        case 2:
            display();
            break;
        case 3:
            exit(0);
        default:
            printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}

void insert() {
    int x, pos, key;
    printf("Enter position 1.Beginning, 2.End, 3.After a specific key: ");
    scanf("%d", &pos);
    printf("Enter data to insert: ");
    scanf("%d", &x);

    newNode = (struct node *)malloc(sizeof(struct node));
    if (!newNode) {
        printf("Memory allocation failed\n");
        return;
    }
    newNode->data = x;
    newNode->rlink = NULL;
    newNode->llink = NULL;

    if (pos == 1) {
        // Insert at the beginning
        ptr = header->rlink;
        newNode->rlink = ptr;
        if (ptr != NULL) {
            ptr->llink = newNode;
        }
        header->rlink = newNode;
        newNode->llink = header;
    } 
    else if (pos == 2) {
        // Insert at the end
        ptr = header;
        while (ptr->rlink != NULL) {
            ptr = ptr->rlink;
        }
        ptr->rlink = newNode;
        newNode->llink = ptr;
    } 
    else if (pos == 3) {
        // Insert after a specific key
        printf("Enter key after which to insert: ");
        scanf("%d", &key);
        ptr = header->rlink;
        while (ptr != NULL && ptr->data != key) {
            ptr = ptr->rlink;
        }
        if (ptr == NULL) {
            printf("Key not found!\n");
        } 
        else {
            newNode->rlink = ptr->rlink;
            newNode->llink = ptr;
            if (ptr->rlink != NULL) {
                ptr->rlink->llink = newNode;
            }
            ptr->rlink = newNode;
        }
    } 
    else {
        printf("Invalid position\n");
    }
}

void display() {
    if (header->rlink == NULL) {
        printf("The list is empty\n");
        return;
    }

    printf("Elements in the list: ");
    ptr = header->rlink;
    while (ptr != NULL) {
        printf("%d ", ptr->data);
        ptr = ptr->rlink;
    }
    printf("\n");
}
