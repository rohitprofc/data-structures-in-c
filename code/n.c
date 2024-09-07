#include <stdio.h>
#include <stdlib.h>
void create();
void deletion();
void display();
struct node
{
    int data;
    struct node *link;
} * ptr, *ptr1, *header, *new;
void main()
{
    int choice;
    header = (struct node *)malloc(sizeof(struct node));
    header->link = header;
    while (1)
    {
        printf("\nEnter the choice of operation\n1.Create  2.Deletion  3.Display: ");
        scanf("%d", &choice);
        switch (choice)
        {
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
void create()
{
    int dataElement;
    printf("Enter data value to insert: ");
    scanf("%d", &dataElement);
    new = (struct node *)malloc(sizeof(struct node));
    if (header->link != header)
    {
        new->link = header->link;
        header->link = new;
        new->data = dataElement;
    }
    else
    {
        header->link = new;
        new->link = header;
        new->data = dataElement;
    }
}
void deletion()
{
    int dataElement, position, key;
    printf("Enter the position of deletion\n1.Beginning  2.Ending  3.At any position: ");
    scanf("%d", &position);
    if (position == 1)
    {
        ptr = header;
        if (ptr->link == header)
        {
            printf("\nCLL is empty");
        }
        else
        {
            ptr = header->link;
            header->link = ptr->link;
            printf("\nNode deleted is %d", ptr->data);
            free(ptr);
        }
    }
    else if (position == 2)
    {
        ptr = header;
        if (ptr->link == header)
        {
            printf("\nCLL is empty,Unable to perform deletion\n");
        }
        else
        {
            while (ptr->link != header)
            {
                ptr1 = ptr;
                ptr = ptr->link;
            }
            ptr1->link = header;
            printf("\nDeleted node is %d", ptr->data);
            free(ptr);
        }
    }
    else if (position == 3)
    {
        ptr = header;
        if (ptr->link == header)
        {
            printf("\nCLL is empty,Unable to perform deletion\n");
        }
        else
        {
            printf("\nEnter the data value: ");
            scanf("%d", &key);
            while (ptr->data != key && ptr->link != header)
            {
                ptr1 = ptr;
                ptr = ptr->link;
            }
            if (ptr->link == header)
            {
                printf("\nNode with key was not found");
            }
            else
            {
                ptr1->link = ptr->link;
                printf("\nDeleted node is %d", ptr->data);
                free(ptr);
            }
        }
    }
}
void display()
{
    printf("\nElements in the list are:\n");
    ptr = header;
    while (ptr->link != header)
    {
        ptr = ptr->link;
        printf(" %d ", ptr->data);
    }
}
/*
Output: -

Enter the choice of operation    
1.Create  2.Deletion  3.Display: 1
Enter data value to insert: 10

Enter the choice of operation
1.Create  2.Deletion  3.Display: 1
Enter data value to insert: 20

Enter the choice of operation
1.Create  2.Deletion  3.Display: 1
Enter data value to insert: 30

Enter the choice of operation
1.Create  2.Deletion  3.Display: 1
Enter data value to insert: 40

Enter the choice of operation
1.Create  2.Deletion  3.Display: 1
Enter data value to insert: 50

Enter the choice of operation
1.Create  2.Deletion  3.Display: 1
Enter data value to insert: 60

Enter the choice of operation
1.Create  2.Deletion  3.Display: 2
Enter the position of deletion
1.Beginning  2.Ending  3.At any position: 1

Node deleted is 60
Enter the choice of operation
1.Create  2.Deletion  3.Display: 2
Enter the position of deletion
1.Beginning  2.Ending  3.At any position: 2

Deleted node is 10
Enter the choice of operation
1.Create  2.Deletion  3.Display: 2
Enter the position of deletion
1.Beginning  2.Ending  3.At any position: 3

Enter the data value: 30

Deleted node is 30
Enter the choice of operation
1.Create  2.Deletion  3.Display: 3

Elements in the list are:
 50  40  20
Enter the choice of operation
1.Create  2.Deletion  3.Display: 4
*/