// Hash table

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
        ar[i] = -1; // Initialize the hash table
    }
    while (1)
    {
        printf("\nEnter your choice \n1.Insert\n2.Deletion\n3.Search\n4.Display\n5.Exit: ");
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
    int value, key, i;
    printf("\nEnter the value to insert: ");
    scanf("%d", &value);
    key = value % size;

    // Use linear probing for collision resolution
    for (i = 0; i < size; i++)
    {
        int newKey = (key + i) % size; // New key with probing
        if (ar[newKey] == -1) // Empty slot found
        {
            ar[newKey] = value;
            printf("\n%d is inserted at location %d: ", value, newKey);
            return;
        }
    }
    printf("\nHash table is full, %d could not be inserted.\n", value);
}

void del()
{
    int value, key, i;
    printf("\nEnter the value to delete: ");
    scanf("%d", &value);
    key = value % size;

    // Use linear probing to find the value
    for (i = 0; i < size; i++)
    {
        int newKey = (key + i) % size; // New key with probing
        if (ar[newKey] == value) // Element found
        {
            ar[newKey] = -1;
            printf("\n%d is deleted", value);
            return;
        }
        if (ar[newKey] == -1) // Empty slot encountered, break if not found
        {
            break;
        }
    }
    printf("\n%d element not found: ", value);
}

void search()
{
    int value, key, i;
    printf("\nEnter the search value: ");
    scanf("%d", &value);
    key = value % size;

    // Use linear probing to search for the value
    for (i = 0; i < size; i++)
    {
        int newKey = (key + i) % size; // New key with probing
        if (ar[newKey] == value) // Element found
        {
            printf("\n%d is found at location %d", value, newKey);
            return;
        }
        if (ar[newKey] == -1) // Empty slot encountered, break if not found
        {
            break;
        }
    }
    printf("\n%d is not found: ", value);
}

void display()
{
    int i;
    for (i = 0; i < size; i++)
    {
        printf("\na[%d]: %d", i, ar[i]);
    }
}
