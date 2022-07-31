#include <stdio.h>
#include <stdlib.h>
void insertion();
void display();
struct node
{
    int data;
    struct node *link;
};
struct node *ptr, *header, *new;
void main()
{
    int choice;
    header = NULL;
    header = (struct node *)malloc(sizeof(struct node));
    while (1)
    {
        printf("\nEnter the choice of operation\n1.Insertion    2.Display: ");
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
    new = (struct node *)malloc(sizeof(struct node));
    printf("Enter data value to insert: ");
    scanf("%d", &dataElement);
    printf("Enter position to insert\n1.Begin  2.End  3.At any position: ");
    scanf("%d", &position);
    ptr = header;
    if (position == 1)
    {
        new->link = header->link;
        new->data = dataElement;
        header->link = new;
    }
    else if (position == 2)
    {
        while (ptr->link != NULL)
        {
            ptr = ptr->link;
        }
        new->link = ptr->link;
        new->data = dataElement;
        ptr->link = new;
    }
    else if (position == 3)
    {
        printf("Enter key value: ");
        scanf("%d", &key);
        ptr = header;
        while (ptr->link != NULL && ptr->data != key)
        {
            ptr = ptr->link;
        }
        if (ptr->link == NULL)
        {
            if (ptr->data == key)
            {
                new->link = ptr->link;
                ptr->link = new;
                new->data = dataElement;
            }
            else
            {
                printf("\nKey not availble");
            }
        }
        else
        {
            new->link = ptr->link;
            new->data = dataElement;
            ptr->link = new;
        }
    }
}
void display()
{
    printf("\nElements in the list are:\n");
    ptr = header->link;
    while (ptr != NULL)
    {
        printf(" %d ", ptr->data);
        ptr = ptr->link;
    }
}
/*
Output: -
Enter the choice of operation
1.Insertion    2.Display: 1
Enter data value to insert: 10
Enter position to insert
1.Begin  2.End  3.At any position: 1

Enter the choice of operation
1.Insertion    2.Display: 1
Enter data value to insert: 20
Enter position to insert
1.Begin  2.End  3.At any position: 2

Enter the choice of operation
1.Insertion    2.Display: 1
Enter data value to insert: 30
Enter position to insert
1.Begin  2.End  3.At any position: 3
Enter key value: 10

Enter the choice of operation
1.Insertion    2.Display: 1
Enter data value to insert: 40
Enter position to insert
1.Begin  2.End  3.At any position: 3
Enter key value: 30

Enter the choice of operation
1.Insertion    2.Display: 1
Enter data value to insert: 50
Enter position to insert
1.Begin  2.End  3.At any position: 3
Enter key value: 20

Enter the choice of operation
1.Insertion    2.Display: 2

Elements in the list are:
 10  30  40  20  50
Enter the choice of operation
1.Insertion    2.Display: 3
*/