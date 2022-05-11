// Linear Search with Recursion

#include <stdio.h>
int recur_search(int[], int, int, int);
void main()
{
    int a[100], n, key, i, found = 0;
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
    found = recur_search(a, n, key, 0);
    if (found == 1)
    {
        printf("Search is successful\n");
    }
    else
    {
        printf("Key value not found\n");
    }
}
int recur_search(int a[], int n, int key, int i)
{
    if (i < n)
    {
        if (key == a[i])
        {
            printf("Key value found at position %d\n", i);
            return 1;
        }
        else
        {
            i++;
            recur_search(a, n, key, i);
        }
    }
}
/*
Output 1:-
Enter no.of elements in an array: 3
Enter elements into array:
Element - 0: 20
Element - 1: 50
Element - 2: 80
Enter key value: 50
Key value found at position 1
Search is successful
*/
/* 
Output 2:-
Enter no.of elements in an array: 3
Enter elements into array:
Element - 0: 20
Element - 1: 50
Element - 2: 80
Enter key value: 40
Key value not found
*/