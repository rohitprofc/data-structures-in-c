// Binary Search Non - Recursion

#include <stdio.h>
int binary_nonrecur_search(int[], int, int, int);
void main()
{
    int a[100], i, found = 0, n, key, mid, low = 0, high;
    printf("Enter no.of elements in an array: ");
    scanf("%d", &n);
    printf("Enter elements into array: ");
    for (i = 0; i < n; i++)
    {
        printf("Element - %d: ", i);
        scanf("%d", &a[i]);
    }
    printf("Enter key value: ");
    scanf("%d", &key);
    found = nonrecur_search(a, key, 0, n - 1);
    if (found == 1)
    {
        printf("Search is successful\n");
    }
    else
    {
        printf("Key value not found\n");
    }
}
int binary_nonrecur_search(int a[], int key, int low, int high)
{
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (key == a[mid])
        {
            printf("Key value found at position %d\n", mid);
            return 1;
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
