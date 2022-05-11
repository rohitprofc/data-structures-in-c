// Linear Search Non - Recursion

#include <stdio.h>
void main()
{
    int a[100], i, found = 0, n, key;
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
    for (i = 0; i < n; i++)
    {
        if (key == a[i])
        {
            found = 1;
            printf("Key value found at position %d\n", i);
            printf("Search is successful\n");
            break;
        }
    }
    if (found == 0)
    {
        printf("Key value not found\n");
    }
}
/*
Output 1:-
Enter no.of elements in an array: 3
Enter elements into array:
Element - 0: 10
Element - 1: 40
Element - 2: 30
Enter key value: 40
Key value found at position 1
Search is successful
*/
/*
Output 2:-
Enter no.of elements in an array: 3
Enter elements into array:
Element - 0: 10
Element - 1: 40
Element - 2: 30
Enter key value: 50
Key value not found
*/
