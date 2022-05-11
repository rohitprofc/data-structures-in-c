// Binary Search with Recursion

#include <stdio.h>
int recur_search(int[], int, int, int);
void main()
{
    int a[100], i, found = 0, n, mid, key, low, high;
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
    found = recur_search(a, key, 0, n-1);
    if (found == 1)
    {
        printf("Search is successful\n");
    }
    else
        printf("Key value not found\n");
}
int recur_search(int a[], int key, int low, int high)
{
    int mid = (low + high)/2;
    if (low <= mid)
    {
        if (key == a[mid])
        {
            printf("Key value found at position %d\n", mid);
            return 1;
        }
        else if (key < a[mid])
        {
            recur_search(a, key, low, mid - 1);
        }
        else
        {
            recur_search(a, key, mid + 1, high);
        }
    }
}
/*
Output 1:-
Enter no.of elements in an array: 5
Enter elements into array:
Element - 0: 10
Element - 1: 30
Element - 2: 50
Element - 3: 70
Element - 4: 90
Enter key value: 30
Key value found at position 1
Search is successful
*/
/*
Output 2:-
Enter no.of elements in an array: 5
Enter elements into array:
Element - 0: 10
Element - 1: 30
Element - 2: 50
Element - 3: 70
Element - 4: 90
Enter key value: 80
Key value not found
*/