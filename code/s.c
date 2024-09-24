// Queue using linked list

#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *front = NULL;
struct node *rear = NULL;

void enqueue() {
    int dataItem;
    printf("Enter data item: ");
    scanf("%d", &dataItem);

    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = dataItem;
    newnode->next = NULL;

    if (front == NULL && rear == NULL) {
        front = rear = newnode;
    } else {
        rear->next = newnode;
        rear = newnode;
    }

    printf("%d enqueued successfully!\n", dataItem);
}

void dequeue() {
    if (front == NULL) {
        printf("\nQueue is empty\n");
    } else {
        struct node *temp = front;
        printf("Dequeued item: %d\n", front->data);
        front = front->next;
        free(temp);

        if (front == NULL) {
            rear = NULL;
        }
    }
}

void display() {
    if (front == NULL) {
        printf("\nQueue is empty\n");
    } else {
        struct node *temp = front;
        printf("\nItems in the queue: ");
        while (temp != NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

void main() {
    int ch;
    while (1) {
        printf("\nEnter your choice\n1.Enqueue  2.Dequeue  3.Display  4.Exit: ");
        scanf("%d", &ch);
        switch (ch) {
        case 1:
            enqueue();
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid choice! Please try again.\n");
        }
    }
}
