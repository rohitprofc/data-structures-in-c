// Bubble Sorting

#include <stdio.h>
void bubble_sort(int[], int);
void main()
{
    int a[100], i, j, n, key;
    printf("Enter no.of elements: ");
    scanf("%d", &n);
    printf("Enter elements into array: \n");
    for (i = 0; i < n; i++)
    {
        printf("Element - %d: ", i);
        scanf("%d", &a[i]);
    }
    printf("Elements after sorting:\n");
    bubble_sort(a, n);
    for (i = 0; i < n; i++)
    {
        printf("Element - %d: %d\n", i, a[i]);
    }
}
void bubble_sort(int a[], int n)
{
    int i, j, temp;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n - 1 - i; j++)
        {
            if (a[j] > a[j + 1])
            {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}
/*
Output:-
Enter no.of elements: 5
Enter elements into array:
Element - 0: 90
Element - 1: 10
Element - 2: 80
Element - 3: 20
Element - 4: 70
Elements after sorting:
Element - 0: 10
Element - 1: 20
Element - 2: 70
Element - 3: 80
Element - 4: 90
*/