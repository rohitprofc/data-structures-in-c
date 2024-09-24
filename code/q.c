// Delete a node from DLL

#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *llink;
    struct node *rlink;
} *header, *ptr, *temp;

void delete();
void display();

int main() {
    int choice;

    // Initialize the header node
    header = (struct node *)malloc(sizeof(struct node));
    header->rlink = NULL;
    header->llink = NULL;

    while (1) {
        printf("\nEnter choice: 1.delete, 2.display, 3.exit\n");
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            delete();
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

void delete() {
    int pos, key;
    printf("Enter position 1.Beginning, 2.End, 3.Specific value: ");
    scanf("%d", &pos);

    if (header->rlink == NULL) {
        printf("The list is empty, nothing to delete.\n");
        return;
    }

    if (pos == 1) {
        // Delete at the beginning
        ptr = header->rlink;
        header->rlink = ptr->rlink;
        if (ptr->rlink != NULL) {
            ptr->rlink->llink = header;
        }
        printf("Deleted node is %d\n", ptr->data);
        free(ptr);
    } 
    else if (pos == 2) {
        // Delete at the end
        ptr = header->rlink;
        if (ptr == NULL) {
            printf("The list is empty.\n");
            return;
        }
        while (ptr->rlink != NULL) {
            ptr = ptr->rlink;
        }
        if (ptr->llink != NULL) {
            ptr->llink->rlink = NULL;
        } else {
            header->rlink = NULL;  // If it's the only node
        }
        printf("Deleted node is %d\n", ptr->data);
        free(ptr);
    } 
    else if (pos == 3) {
        // Delete a specific value
        printf("Enter the value to delete: ");
        scanf("%d", &key);
        ptr = header->rlink;
        while (ptr != NULL && ptr->data != key) {
            ptr = ptr->rlink;
        }
        if (ptr == NULL) {
            printf("Node with value %d not found.\n", key);
        } else {
            if (ptr->llink != NULL) {
                ptr->llink->rlink = ptr->rlink;
            }
            if (ptr->rlink != NULL) {
                ptr->rlink->llink = ptr->llink;
            }
            printf("Deleted node is %d\n", ptr->data);
            free(ptr);
        }
    } 
    else {
        printf("Invalid position!\n");
    }
}

void display() {
    if (header->rlink == NULL) {
        printf("The list is empty.\n");
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
