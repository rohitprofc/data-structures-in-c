#include <stdio.h>
#include <stdlib.h>
void insert();
void search();
void del();
void display();
int ar[100], size;
int main()
{
    int i, ch;
    printf("\nEnter size of hash table: ");
    scanf("%d", &size);
    for (i = 0; i < size; i++)
    {
        ar[i] = -1;
    }
    while (1)
    {
        printf("\nEnter your choice \n1.Insert\n2.Deletion\n3.Search\n4.Display\n5.Search\n6.Exit: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            insert();
            break;
        case 2:
            del();
            break;
        case 3:
            search();
            break;
        case 4:
            display();
            break;
        default:
            exit(0);
        }
    }
    return 0;
}
void insert()
{
    int value, key;
    printf("\nEnter the value to insert: ");
    scanf("%d", &value);
    key = value % size;
    if (ar[key] == -1)
    {
        ar[key] = value;
        printf("\n%d is inserted in the location %d: ", value, key);
    }
    else
    {
        printf("\n%d not placed due to collision: ", value);
    }
}
void del()
{
    int value, key;
    printf("\nEnter the value to delete: ");
    scanf("%d", &value);
    key = value % size;
    if (ar[key] == value)
    {
        ar[key] = -1;
        printf("\n%d is deleted", value);
    }
    else
    {
        printf("\n%d element not found: ", value);
    }
}
void search()
{
    int value, key;
    printf("\nEnter the search value: ");
    scanf("%d", &value);
    key = value % size;
    if (ar[key] == value)
    {
        printf("\n%d is found at location %d", value, key);
    }
    else
    {
        printf("\n%d is not found: ", value);
    }
}
void display()
{
    int i;
    for (i = 0; i < size; i++)
    {
        printf("\na[%d]: %d", i, ar[i]);
    }
}
/*
Output: -
Enter size of hash table: 5

Enter your choice
1.Insert
2.Deletion
3.Search
4.Display
5.Search
6.Exit: 1

Enter the value to insert: 10

10 is inserted in the location 0:
Enter your choice
1.Insert
2.Deletion
3.Search
4.Display
5.Search
6.Exit: 1

Enter the value to insert: 11

11 is inserted in the location 1:
Enter your choice
1.Insert
2.Deletion
3.Search
4.Display
5.Search
6.Exit: 1

Enter the value to insert: 12

12 is inserted in the location 2:
Enter your choice
1.Insert
2.Deletion
3.Search
4.Display
5.Search
6.Exit: 1

Enter the value to insert: 13

13 is inserted in the location 3:
Enter your choice
1.Insert
2.Deletion
3.Search
4.Display
5.Search
6.Exit: 1

Enter the value to insert: 14

14 is inserted in the location 4:
Enter your choice
1.Insert
2.Deletion
3.Search
4.Display
5.Search
6.Exit: 4

a[0]: 10
a[1]: 11
a[2]: 12
a[3]: 13
a[4]: 14
Enter your choice
1.Insert
2.Deletion
3.Search
4.Display
5.Search
6.Exit: 2

Enter the value to delete: 14

14 is deleted
Enter your choice
1.Insert
2.Deletion
3.Search
4.Display
5.Search
6.Exit: 3

Enter the search value: 11

11 is found at location 1
Enter your choice
1.Insert
2.Deletion
3.Search
4.Display
5.Search
6.Exit: 4

a[0]: 10
a[1]: 11
a[2]: 12
a[3]: 13
a[4]: -1
Enter your choice
1.Insert
2.Deletion
3.Search
4.Display
5.Search
6.Exit: 6
*/