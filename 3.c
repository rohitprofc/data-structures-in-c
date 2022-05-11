// Binary Search Non - Recursion

#include <stdio.h>
void main()
{
    int a[100], i, found = 0, n, key, mid, low = 0, high;
    printf("Enter no.of elements in an array: ");
    scanf("%d", &n);
    printf("Enter elements into array:\n");
    for (i = 0; i < n; i++)
    {
        printf("Element - %d: ", i);
        scanf("%d", &a[i]);
    }
    printf("Enter key value: ");
    scanf("%d", &key);
    high = n - 1;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (key == a[mid])
        {
            found = 1;
            break;
        }
        else if (key < a[mid])
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    if (found == 1)
    {
        printf("Key value found at position %d\n", mid);
        printf("Search is successful\n");
    }
    else
    {
        printf("Key value not found\n");
    }
}
/*
Output 1:-
Enter no.of elements in an array: 5
Enter elements into array:
Element - 0: 10
Element - 1: 20
Element - 2: 30
Element - 3: 80
Element - 4: 90
Enter key value: 80
Key value found at position 3
Search is successful
*/
/*
Output 2:-
Enter no.of elements in an array: 5
Enter elements into array:
Element - 0: 10
Element - 1: 20
Element - 2: 30
Element - 3: 80
Element - 4: 90
Enter key value: 50
Key value not found
*/