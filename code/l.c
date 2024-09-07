#include <stdio.h>
#include <stdlib.h>
void create();
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
        printf("\nEnter the choice of operation\n1.Creation  2.Display: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            create();
            break;
        case 2:
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
        new->data = dataElement;
        header->link = new;
    }
    else
    {
        header->link = new;
        new->link = header;
        new->data = dataElement;
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
1.Creation  2.Display: 1
Enter data value to insert: 10

Enter the choice of operation
1.Creation  2.Display: 1
Enter data value to insert: 20

Enter the choice of operation
1.Creation  2.Display: 1
Enter data value to insert: 30

Enter the choice of operation
1.Creation  2.Display: 1
Enter data value to insert: 40

Enter the choice of operation
1.Creation  2.Display: 2

Elements in the list are:
 40  30  20  10
Enter the choice of operation
1.Creation  2.Display: 3
*/
