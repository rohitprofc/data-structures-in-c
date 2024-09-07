#include <stdio.h>
#include <stdlib.h>
#define size 5
int top = 0, s[5];
void push(int);
void pop();
void display();
void main()
{
    int dataItem, i, choice;
    while (1)
    {
        printf("\nEnter your choice\n1.push  2.pop  3.display: ");
        scanf("%d", &choice);
        switch (choice)
        {
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
        default:
            exit(0);
        }
    }
}
void push(int dataItem)
{
    if (top == size)
    {
        printf("\nStack is full");
    }
    else
    {
        top += 1;
        s[top] = dataItem;
    }
}
void pop()
{
    if (top < 1)
    {

        printf("\nStack is empty");
    }
    else
    {
        printf("\nPoped item is %d", s[top]);
        top -= 1;
    }
}
void display()
{
    int i;
    if (top < 1)
    {
        printf("\nStack is empty");
    }
    else
    {
        printf("\nItems in stack are: ");
        for (i = 1; i <= top; i++)
        {
            printf("%d   ", s[i]);
        }
    }
}
/*
Output: -
Enter your choice
1.push  2.pop  3.display: 1
Enter data item: 10

Enter your choice
1.push  2.pop  3.display: 1
Enter data item: 20

Enter your choice
1.push  2.pop  3.display: 1
Enter data item: 30

Enter your choice
1.push  2.pop  3.display: 1
Enter data item: 40

Enter your choice
1.push  2.pop  3.display: 1
Enter data item: 50

Enter your choice
1.push  2.pop  3.display: 1
Enter data item: 60

Stack is full
Enter your choice
1.push  2.pop  3.display: 3

Items in stack are: 10   20   30   40   50
Enter your choice
1.push  2.pop  3.display: 2

Poped item is 50
Enter your choice
1.push  2.pop  3.display: 2

Poped item is 40
Enter your choice
1.push  2.pop  3.display: 2

Poped item is 30
Enter your choice
1.push  2.pop  3.display: 2

Poped item is 20
Enter your choice
1.push  2.pop  3.display: 2

Poped item is 10
Enter your choice
1.push  2.pop  3.display: 2

Stack is empty
Enter your choice
1.push  2.pop  3.display: 3

Stack is empty
Enter your choice
1.push  2.pop  3.display: 4




*/