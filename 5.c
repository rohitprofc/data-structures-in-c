// Insertion Sorting

#include <stdio.h>
void main()
{
    int a[100], i, j, n, unsort_ele;
    printf("Enter no.of elements: ");
    scanf("%d", &n);
    printf("Enter elements into array :\n");
    for (i = 0; i < n; i++)
    {
        printf("Element - %d: ", i);
        scanf("%d", &a[i]);
    }
    printf("Elements after sorting:\n");
    for (i = 1; i < n; i++)
    {
        unsort_ele = a[i];
        j = i - 1;
        while (j >= 0 && a[j] > unsort_ele)
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = unsort_ele;
    }
    for (i = 0; i < n; i++)
    {
        printf("Element - %d: %d\n", i, a[i]);
    }
}
/*
Output:-
Enter no.of elements: 5
Enter elements into array :
Element - 0: 63
Element - 1: 55
Element - 2: 45
Element - 3: 51
Element - 4: 57
Elements after sorting:
Element - 0: 45
Element - 1: 51
Element - 2: 55
Element - 3: 57
Element - 4: 63
*/
