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
    int ch;
    header = NULL;
    while (1)
    {
        printf("\nEnter the choice of operation\n1.Creation\n2.Transversal\n3.Terminate the program\n");
        scanf("%d", &ch);
        switch (ch)
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
1.Creation
2.Transversal
3.Terminate the program
1
Enter data value to insert: 10

Enter the choice of operation
1.Creation
2.Transversal
3.Terminate the program
1
Enter data value to insert: 20

Enter the choice of operation
1.Creation
2.Transversal
3.Terminate the program
1
Enter data value to insert: 30

Enter the choice of operation
1.Creation
2.Transversal
3.Terminate the program
1
Enter data value to insert: 40

Enter the choice of operation
1.Creation
2.Transversal
3.Terminate the program
1
Enter data value to insert: 50

Enter the choice of operation
1.Creation
2.Transversal
3.Terminate the program
2

Elements in the list are:
 10  20  30  40  50 
Enter the choice of operation
1.Creation
2.Transversal
3.Terminate the program
3
*/