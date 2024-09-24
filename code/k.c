// Delete a node from SLL

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
} *head = NULL;

void insertBeginning() {
    int value;
    printf("\nEnter the value to insert: ");
    scanf("%d", &value);
    
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory allocation failed\n");
        return;
    }
    newNode->data = value;
    newNode->next = head;
    head = newNode;
    printf("\nOne node inserted");
}

void deleteBeginning() {
    if (head == NULL) {
        printf("\nList is Empty");
        return;
    }

    struct Node *temp = head;
    head = head->next;
    free(temp);
    printf("\nOne node deleted");
}

void deleteEnd() {
    if (head == NULL) {
        printf("\nList is Empty");
        return;
    }

    struct Node *temp1 = head, *temp2 = NULL;
    while (temp1->next != NULL) {
        temp2 = temp1;
        temp1 = temp1->next;
    }

    if (temp2 == NULL) { // Only one node in the list
        head = NULL;
    } else {
        temp2->next = NULL;
    }
    free(temp1);
    printf("\nOne node deleted");
}

void deleteSpecific(int delValue) {
    if (head == NULL) {
        printf("\nList is Empty");
        return;
    }

    struct Node *current = head, *previous = NULL;

    // Check if the node to be deleted is the head
    if (current->data == delValue) {
        head = current->next;
        free(current);
        printf("\nOne node deleted");
        return;
    }

    while (current != NULL && current->data != delValue) {
        previous = current;
        current = current->next;
    }

    if (current == NULL) {
        printf("\nGiven node not found in the list");
        return;
    }

    previous->next = current->next;
    free(current);
    printf("\nOne node deleted");
}

void display() {
    if (head == NULL) {
        printf("\nList is Empty\n");
        return;
    }

    struct Node *temp = head;
    printf("\nList elements are: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    int choice, loc;
    
    while (1) {
        printf("\nEnter your choice\n1. Insert\n2. Delete\n3. Display\n4. Exit: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                insertBeginning();
                break;
            case 2:
                printf("Where do you want to delete: \n1. From Beginning\n2. From End\n3. Specific\nEnter your choice: ");
                scanf("%d", &choice);
                switch (choice) {
                    case 1:
                        deleteBeginning();
                        break;
                    case 2:
                        deleteEnd();
                        break;
                    case 3:
                        printf("Enter the value you want to delete: ");
                        scanf("%d", &loc);
                        deleteSpecific(loc);
                        break;
                    default:
                        printf("\nWrong Input!! Try again!!!\n");
                }
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("\nWrong input\n");
        }
    }
    return 0;
}
