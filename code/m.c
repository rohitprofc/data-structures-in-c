#include <stdio.h>
#include <stdlib.h>
void insertion();
void display();
struct node
{
    int data;
    struct node *link;
} * ptr, *header, *new;
void main()
{
    int choice;
    header = (struct node *)malloc(sizeof(struct node));
    header->link = header;
    while (1)
    {
        printf("\nEnter the choice of operation\n1.Insertion  2.Transversal: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            insertion();
            break;
        case 2:
            display();
            break;
        default:
            exit(0);
        }
    }
}
void insertion()
{
    int dataElement, key, position;
    printf("Enter data value to insert: ");
    scanf("%d", &dataElement);
    new = (struct node *)malloc(sizeof(struct node));
    printf("\nEnter the position of insertion\n1.Beginning  2.Ending  3.At any position:");
    scanf("%d", &position);
    if (position == 1)
    {
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
    else if (position == 2)
    {
        ptr = header;
        while (ptr->link != header)
        {
            ptr = ptr->link;
        }
        ptr->link = new;
        new->link = header;
        new->data = dataElement;
    }
    else if (position == 3)
    {
        printf("\nEnter key value: ");
        scanf("%d", &key);
        ptr = header;
        while (ptr->link != header && ptr->data != key)
        {
            ptr = ptr->link;
        }
        if (ptr->link == header)
        {
            if (ptr->data == key)
            {
                new->link = ptr->link;
                ptr->link = new;
                new->data = dataElement;
            }
            else
            {
                printf("\nKey not available");
            }
        }
        else
        {
            new->link = ptr->link;
            ptr->link = new;
            new->data = dataElement;
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
1.Insertion  2.Transversal: 1
Enter data value to insert: 10

Enter the position of insertion
1.Beginning  2.Ending  3.At any position:1

Enter the choice of operation
1.Insertion  2.Transversal: 1
Enter data value to insert: 20

Enter the position of insertion
1.Beginning  2.Ending  3.At any position:2

Enter the choice of operation
1.Insertion  2.Transversal: 1
Enter data value to insert: 30

Enter the position of insertion
1.Beginning  2.Ending  3.At any position:3

Enter key value: 10

Enter the choice of operation
1.Insertion  2.Transversal: 1
Enter data value to insert: 40

Enter the position of insertion
1.Beginning  2.Ending  3.At any position:3

Enter key value: 20

Enter the choice of operation
1.Insertion  2.Transversal: 2

Elements in the list are:
 10  30  20  40
Enter the choice of operation
1.Insertion  2.Transversal: 4
*/
