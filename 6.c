// Bubble Sorting

#include <stdio.h>
void main()
{
    int a[100], i, j, n, el;
    printf("Enter no.of elements: ");
    scanf("%d", &n);
    printf("Enter elements into array: \n");
    for (i = 0; i < n; i++)
    {
        printf("Element - %d: ", i);
        scanf("%d", &a[i]);
    }
    /*
    printf("Elements after sorting:\n");
    for (i = 0; i < n; i++)
    {
        el = a[i];
        j = i - 1;
        while (j >= 0 && a[j > el])
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = el;
    }
    */
    for (i = 0; i < n; i++)
    {
        printf("Element - %d: %d\n", i, a[i]);
    }
}
/*
Output:-

*/