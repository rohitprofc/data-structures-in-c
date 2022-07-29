#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *front = 0;
struct node *rear = 0;
struct node *newnode = 0;

void enqueue()
{
    int dataItem;
    scanf("%d", &dataItem);
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = dataItem;
    newnode->next = 0;
    if (front == 0 && rear == 0)
    {
        front = rear = newnode;
    }
    else
    {
        rear->next = newnode;
        rear = newnode;
    }
}
void dequeue()
{
    struct node *temp;
    if (front == 0 && rear == 0)
    {
        printf("\nQueue is empty");
    }
    else
    {
        temp = front;
        printf("%d", front->data);
        front = front->next;
        free(temp);
    }
    if (front == 0)
    {
        rear = 0;
    }
}
void display()
{
    struct node *temp;
    if (front == 0 && rear == 0)
    {
        printf("\nQueue is empty");
    }
    else
    {
        temp = front;
        while (temp != 0)
        {
            printf("%d  ", temp->data);
            temp = temp->next;
        }
    }
}
void main()
{
    int ch;
    while (1)
    {
        printf("\nEnter your choice\n1.Enqueue  2.Dequeue  3.Display: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            enqueue();
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
        default:
            exit(0);
        }
    }
}
/*
Output: -

Enter your choice
1.Enqueue  2.Dequeue  3.Display: 1
10

Enter your choice
1.Enqueue  2.Dequeue  3.Display: 1
20

Enter your choice
1.Enqueue  2.Dequeue  3.Display: 1
30

Enter your choice
1.Enqueue  2.Dequeue  3.Display: 3
10  20  30
Enter your choice
1.Enqueue  2.Dequeue  3.Display: 2
10
Enter your choice
1.Enqueue  2.Dequeue  3.Display: 2
20
Enter your choice
1.Enqueue  2.Dequeue  3.Display: 2
30
Enter your choice
1.Enqueue  2.Dequeue  3.Display: 3

Queue is empty
Enter your choice
1.Enqueue  2.Dequeue  3.Display: 6
*/