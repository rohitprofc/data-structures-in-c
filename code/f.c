// Bubble Sorting

#include <stdio.h>

void bubble_sort(int[], int);

int main() {
    int a[100], i, n;
    
    printf("Enter number of elements: ");
    scanf("%d", &n);
    
    printf("Enter elements into the array: \n");
    for (i = 0; i < n; i++) {
        printf("Element - %d: ", i);
        scanf("%d", &a[i]);
    }
    
    bubble_sort(a, n);
    
    printf("Elements after sorting:\n");
    for (i = 0; i < n; i++) {
        printf("Element - %d: %d\n", i, a[i]);
    }

    return 0;
}

void bubble_sort(int a[], int n) {
    int i, j, temp;
    int swapped;  // Flag to check if any swaps were made
    
    for (i = 0; i < n - 1; i++) {
        swapped = 0;  // Reset swapped flag at the beginning of each iteration
        
        for (j = 0; j < n - 1 - i; j++) {
            if (a[j] > a[j + 1]) {
                // Swap the elements
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
                swapped = 1;  // Set swapped flag to true when a swap is made
            }
        }
        
        // If no elements were swapped, the array is already sorted
        if (swapped == 0) {
            break;
        }
    }
}
