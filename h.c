// Selection Sorting

#include <stdio.h>
void selection_sort(int[], int);
void main()
{
    int a[100], i, j, n, min, temp;
    printf("Enter no.of elements: ");
    scanf("%d", &n);
    printf("Enter elements into array:\n");
    for (i = 0; i < n; i++)
    {
        printf("Element - %d: ", i);
        scanf("%d", &a[i]);
    }
    printf("Elements after sorting:\n");
    selection_sort(a, n);
    for (i = 0; i < n; i++)
    {
        printf("Element - %d: %d\n", i, a[i]);
    }
}
void selection_sort(int a[], int n)
{
    int i, j, min, temp;
    for (i = 0; i < n; i++)
    {
        min = i;
        for (j = i + 1; j < n; j++)
        {
            if (a[j] < a[min])
            {
                min = j;
            }
        }
        if (min != i)
        {
            temp = a[i];
            a[i] = a[min];
            a[min] = temp;
        }
    }
}
/*
Output:-
Enter no.of elements: 5
Enter elements into array:
Element - 0: 60
Element - 1: 90
Element - 2: 10
Element - 3: 70
Element - 4: 30
Elements after sorting:
Element - 0: 10
Element - 1: 30
Element - 2: 60
Element - 3: 70
Element - 4: 90
*/