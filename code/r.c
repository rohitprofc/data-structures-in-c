// Stack using arrays

#include <stdio.h>
#include <stdlib.h>
#define size 5

int top = -1, s[size]; // Initialize top as -1 to indicate an empty stack
void push(int);
void pop();
void display();

void main() {
    int dataItem, choice;

    while (1) {
        printf("\nEnter your choice\n1.push  2.pop  3.display  4.exit: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter data item: ");
                scanf("%d", &dataItem);
                push(dataItem);
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice! Try again.\n");
        }
    }
}

void push(int dataItem) {
    if (top == size - 1) {
        printf("\nStack is full\n");
    } else {
        top += 1;
        s[top] = dataItem;
        printf("\n%d pushed to stack\n", dataItem);
    }
}

void pop() {
    if (top == -1) {
        printf("\nStack is empty\n");
    } else {
        printf("\nPopped item is %d\n", s[top]);
        top -= 1;
    }
}

void display() {
    if (top == -1) {
        printf("\nStack is empty\n");
    } else {
        printf("\nItems in stack are: ");
        for (int i = top; i >= 0; i--) {
            printf("%d ", s[i]);
        }
        printf("\n");
    }
}
