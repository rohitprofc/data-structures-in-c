// Linear Search Non - Recursion

#include <stdio.h>
int nonrecur_search(int[], int, int, int);
void main()
{
    int a[100], i, found = 0, n, key;
    printf("Enter no.of elements in an array: ");
    scanf("%d", &n);
    printf("Enter elements into array:\n");
    for (i = 0; i < n; i++)
    {
        printf("Element - %d: ", i+1);
        scanf("%d", &a[i]);
    }
    printf("Enter key value: ");
    scanf("%d", &key);
    found = nonrecur_search(a, 0, key, n);
    if (found == 1)
    {
        printf("Search Successful\n");
    }
    else
    {
        printf("Key value not found\n");
    }
}
int nonrecur_search(int a[], int i, int key, int n)
{
    for (i = 0; i < n; i++)
    {
        if (key == a[i])
        {
            printf("Key value found at position %d\n", i);
            return 1;
        }
    }
}
/*
Output 1:-
Enter no.of elements in an array: 3
Enter elements into array:
Element - 1: 10
Element - 2: 40
Element - 3: 30
Enter key value: 40
Key value found at position 1
Search Successful
*/
/*
Output 2:-
Enter no.of elements in an array: 3
Enter elements into array:
Element - 1: 10
Element - 2: 40
Element - 3: 30
Enter key value: 50
Key value not found
*/
