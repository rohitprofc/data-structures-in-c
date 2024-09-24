// Selection Sorting

#include <stdio.h>

void selection_sort(int[], int);

int main() {
    int a[100], i, n;
    
    printf("Enter number of elements: ");
    scanf("%d", &n);
    
    printf("Enter elements into the array:\n");
    for (i = 0; i < n; i++) {
        printf("Element - %d: ", i);
        scanf("%d", &a[i]);
    }
    
    selection_sort(a, n);
    
    printf("Elements after sorting:\n");
    for (i = 0; i < n; i++) {
        printf("Element - %d: %d\n", i, a[i]);
    }

    return 0;
}

void selection_sort(int a[], int n) {
    int i, j, min_index, temp;
    
    for (i = 0; i < n - 1; i++) {  // `n-1` because the last element will already be sorted
        min_index = i;  // Assume the first unsorted element is the smallest
        
        for (j = i + 1; j < n; j++) {
            if (a[j] < a[min_index]) {
                min_index = j;  // Update min_index if a smaller element is found
            }
        }
        
        // Swap the found minimum element with the first unsorted element
        if (min_index != i) {
            temp = a[i];
            a[i] = a[min_index];
            a[min_index] = temp;
        }
    }
}
