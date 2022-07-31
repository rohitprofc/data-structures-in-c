#include <stdio.h>
#include <stdlib.h>
void creation();
void transversal();
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
    while (1)
    {
        printf("\nEnter the choice of operation\n1.Creation    2.Transversal: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            creation();
            break;
        case 2:
            transversal();
            break;

        default:
            exit(0);
        }
    }
}
void creation()
{
    int dataElement;
    new = (struct node *)malloc(sizeof(struct node));
    printf("Enter data value to insert: ");
    scanf("%d", &dataElement);
    if (header == NULL)
    {
        new->data = dataElement;
        new->link = NULL;
        header = new;
    }
    else
    {
        ptr = header;
        while (ptr->link != NULL)
        {
            ptr = ptr->link;
        }
        ptr->link = new;
        new->data = dataElement;
        new->link = NULL;
    }
}
void transversal()
{
    printf("\nElements in the list are:\n");
    ptr = header;
    while (ptr != NULL)
    {
        printf(" %d ", ptr->data);
        ptr = ptr->link;
    }
}
/*
Output:-
Enter the choice of operation
1.Creation    2.Transversal: 1
Enter data value to insert: 10

Enter the choice of operation
1.Creation    2.Transversal: 5
PS C:\Users\Rohit Chess\Desktop\Data-Structures-in-C> cd "c:\Users\Rohit Chess\Desktop\Data-Structures-in-C\" ; if ($?) { gcc i.c -o i } ; if ($?) { .\i }

Enter the choice of operation
1.Creation    2.Transversal: 1
Enter data value to insert: 51

Enter the choice of operation
1.Creation    2.Transversal: 1
Enter data value to insert: 53

Enter the choice of operation
1.Creation    2.Transversal: 1
Enter data value to insert: 57

Enter the choice of operation
1.Creation    2.Transversal: 2

Elements in the list are:
 51  53  57
Enter the choice of operation
1.Creation    2.Transversal: 4
*/