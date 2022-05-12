// Bubble Sorting

#include <stdio.h>
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
    for (i = 0; i < n; i++)
    {
        key = a[i];
        j = i - 1;
        while (j >= 0 && a[j] > key)
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
    }
    for (i = 0; i < n; i++)
    {
        printf("Element - %d: %d\n", i, a[i]);
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