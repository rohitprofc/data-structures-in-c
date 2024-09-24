// Create a DLL

#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *llink;
    struct node *rlink;
} *header, *neww, *ptr, *ptr1, *ptr2;

void create();
void insert();
void delet();
void display();

int main() {
    int ch;

    // Initialize header node and set its links to NULL
    header = (struct node *)malloc(sizeof(struct node));
    if (!header) {
        printf("Memory allocation failed\n");
        return 1;
    }
    header->rlink = NULL;
    header->llink = NULL;

    while (1) {
        printf("\nEnter choice: 1.create, 2.insert, 3.delete, 4.display, 5.exit\n");
        scanf("%d", &ch);
        switch (ch) {
        case 1:
            create();
            break;
        case 2:
            insert();
            break;
        case 3:
            delet();
            break;
        case 4:
            display();
            break;
        case 5:
            exit(0);
        default:
            printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}

void create() {
    int x;
    printf("Enter data to insert: ");
    scanf("%d", &x);
    neww = (struct node *)malloc(sizeof(struct node));
    if (!neww) {
        printf("Memory allocation failed\n");
        return;
    }
    neww->data = x;
    neww->rlink = NULL;
    neww->llink = NULL;

    if (header->rlink == NULL) {
        header->rlink = neww;
        neww->llink = header;
    } else {
        ptr = header;
        while (ptr->rlink != NULL) {
            ptr = ptr->rlink;
        }
        ptr->rlink = neww;
        neww->llink = ptr;
    }
}

void insert() {
    int x, pos, key;
    printf("Enter position 1.Begin, 2.End, 3.Any: ");
    scanf("%d", &pos);
    printf("Enter data to insert: ");
    scanf("%d", &x);
    neww = (struct node *)malloc(sizeof(struct node));
    if (!neww) {
        printf("Unable to insert\n");
        return;
    }
    neww->data = x;
    neww->rlink = NULL;
    neww->llink = NULL;

    if (pos == 1) {
        ptr = header->rlink;
        neww->rlink = ptr;
        if (ptr != NULL) {
            ptr->llink = neww;
        }
        header->rlink = neww;
        neww->llink = header;
    } else if (pos == 2) {
        ptr = header;
        while (ptr->rlink != NULL) {
            ptr = ptr->rlink;
        }
        ptr->rlink = neww;
        neww->llink = ptr;
    } else if (pos == 3) {
        printf("Enter key: ");
        scanf("%d", &key);
        ptr = header->rlink;
        while (ptr != NULL && ptr->data != key) {
            ptr = ptr->rlink;
        }
        if (ptr == NULL) {
            printf("Key value not found\n");
        } else {
            ptr1 = ptr->rlink;
            neww->rlink = ptr1;
            neww->llink = ptr;
            ptr->rlink = neww;
            if (ptr1 != NULL) {
                ptr1->llink = neww;
            }
        }
    } else {
        printf("Invalid position\n");
    }
}

void delet() {
    int num, pos;
    printf("Enter position 1.Begin, 2.End, 3.Any: ");
    scanf("%d", &pos);

    if (header->rlink == NULL) {
        printf("List is empty\n");
        return;
    }

    if (pos == 1) {
        ptr = header->rlink;
        header->rlink = ptr->rlink;
        if (ptr->rlink != NULL) {
            ptr->rlink->llink = header;
        }
        printf("Deleted node is %d\n", ptr->data);
        free(ptr);
    } else if (pos == 2) {
        ptr = header;
        while (ptr->rlink != NULL) {
            ptr1 = ptr;
            ptr = ptr->rlink;
        }
        ptr1->rlink = NULL;
        printf("Deleted node is %d\n", ptr->data);
        free(ptr);
    } else if (pos == 3) {
        printf("Enter data to delete: ");
        scanf("%d", &num);
        ptr = header->rlink;
        while (ptr != NULL && ptr->data != num) {
            ptr = ptr->rlink;
        }
        if (ptr == NULL) {
            printf("Node with the given data not found\n");
        } else {
            ptr1 = ptr->llink;
            ptr2 = ptr->rlink;
            ptr1->rlink = ptr2;
            if (ptr2 != NULL) {
                ptr2->llink = ptr1;
            }
            printf("Deleted node is %d\n", ptr->data);
            free(ptr);
        }
    } else {
        printf("Invalid position\n");
    }
}

void display() {
    if (header->rlink == NULL) {
        printf("The list is empty\n");
        return;
    }
    printf("Elements in the list are: ");
    ptr = header->rlink;
    while (ptr != NULL) {
        printf("%d ", ptr->data);
        ptr = ptr->rlink;
    }
    printf("\n");
}
