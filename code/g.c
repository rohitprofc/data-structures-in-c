// Insertion Sorting

#include <stdio.h>

void insertion_sort(int[], int);

int main() {
    int a[100], i, n;
    
    printf("Enter number of elements: ");
    scanf("%d", &n);
    
    printf("Enter elements into the array: \n");
    for (i = 0; i < n; i++) {
        printf("Element - %d: ", i);
        scanf("%d", &a[i]);
    }
    
    insertion_sort(a, n);
    
    printf("Elements after sorting:\n");
    for (i = 0; i < n; i++) {
        printf("Element - %d: %d\n", i, a[i]);
    }

    return 0;
}

void insertion_sort(int a[], int n) {
    int i, j, unsort_ele;
    
    for (i = 1; i < n; i++) {
        unsort_ele = a[i];
        j = i - 1;

        // Move elements that are greater than unsort_ele to one position ahead
        while (j >= 0 && a[j] > unsort_ele) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = unsort_ele;
    }
}
