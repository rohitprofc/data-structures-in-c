#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
} *head = NULL;

void insertBeginning()
{
    int value;
    printf("\nEnter the value to be insert: ");
    scanf("%d", &value);
    struct Node *newNode;
    newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    if (head == NULL)
    {
        newNode->next = NULL;
        head = newNode;
    }
    else
    {
        newNode->next = head;
        head = newNode;
    }
    printf("\nOne node inserted");
}

void deleteBeginning()
{
    if (head == NULL)
        printf("\nList is Empty");
    else
    {
        struct Node *temp = head;
        if (head->next == NULL)
        {
            head = NULL;
            free(temp);
        }
        else
        {
            head = temp->next;
            free(temp);
            printf("\nOne node deleted");
        }
    }
}
void deleteEnd()
{
    if (head == NULL)
    {
        printf("\nList is Empty");
    }
    else
    {
        struct Node *temp1 = head, *temp2;
        if (head->next == NULL)
            head = NULL;
        else
        {
            while (temp1->next != NULL)
            {
                temp2 = temp1;
                temp1 = temp1->next;
            }
            temp2->next = NULL;
        }
        free(temp1);
        printf("\nOne node deleted");
    }
}
void deleteSpecific(int delValue)
{
    struct Node *temp1 = head, *temp2;
    while (temp1->data != delValue)
    {
        if (temp1->next == NULL)
        {
            printf("\nGiven node not found in the list");
        }
        temp2 = temp1;
        temp1 = temp1->next;
    }
    temp2->next = temp1->next;
    free(temp1);
    printf("\nOne node deleted");
}
void display()
{
    if (head == NULL)
    {
        printf("\nList is Empty\n");
    }
    else
    {
        struct Node *temp = head;
        printf("\nList elements are ");
        while (temp->next != NULL)
        {
            printf("%d --->", temp->data);
            temp = temp->next;
        }
        printf("%d --->NULL", temp->data);
    }
}
int main()
{
    int choice, data, loc1, loc2;
    // clrscr();
    while (1)
    {
    l1:
        printf("\nEnter your choice\n1. Insert\n2. Delete\n3. Display\n4. Exit:");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            insertBeginning();
            break;

        case 2:
            printf("Where you want to Delete: \n1. From Beginning\n2. From End\n3.Spesific\nEnter your choice: ");
            scanf("%d", &choice);
            switch (choice)
            {
            case 1:
                deleteBeginning();
                break;
            case 2:
                deleteEnd();
                break;
            case 3:
                printf("Enter the value which you wanto delete: ");
                scanf("%d", &loc2);
                deleteSpecific(loc2);
                break;
            default:
                printf("\nWrong Input!! Try again!!!\n\n");
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
    return 1;
}
/*
Output: -
Enter your choice
1. Insert
2. Delete
3. Display
4. Exit:1

Enter the value to be insert: 10

One node inserted
Enter your choice
1. Insert
2. Delete
3. Display
4. Exit:1

Enter the value to be insert: 20

One node inserted
Enter your choice
1. Insert
2. Delete
3. Display
4. Exit:1

Enter the value to be insert: 30

One node inserted
Enter your choice
1. Insert
2. Delete
3. Display
4. Exit:1

Enter the value to be insert: 40

One node inserted
Enter your choice
1. Insert
2. Delete
3. Display
4. Exit:1

Enter the value to be insert: 50

One node inserted
Enter your choice
1. Insert
2. Delete
3. Display
4. Exit:3

List elements are 50 --->40 --->30 --->20 --->10 --->NULL
Enter your choice
1. Insert
2. Delete
3. Display
4. Exit:2
Where you want to Delete: 
1. From Beginning
2. From End
3.Spesific
Enter your choice: 1

One node deleted
Enter your choice
1. Insert
2. Delete
3. Display
4. Exit:3

List elements are 40 --->30 --->20 --->10 --->NULL
Enter your choice
1. Insert
2. Delete
3. Display
4. Exit:2
Where you want to Delete: 
1. From Beginning
2. From End
3.Spesific
Enter your choice: 2

One node deleted
Enter your choice
1. Insert
2. Delete
3. Display
4. Exit:3

List elements are 40 --->30 --->20 --->NULL
Enter your choice
1. Insert
2. Delete
3. Display
4. Exit:2
Where you want to Delete: 
1. From Beginning
2. From End
3.Spesific
Enter your choice: 3
Enter the value which you wanto delete: 20

One node deleted
Enter your choice
1. Insert
2. Delete
3. Display
4. Exit:3

List elements are 40 --->30 --->NULL
Enter your choice
1. Insert
2. Delete
3. Display
4. Exit:4
*/