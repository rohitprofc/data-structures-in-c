// Binary Search with Recursion

#include <stdio.h>

int binary_recur_search(int[], int, int, int);

int main() {
    int a[100], i, found = 0, n, key;
    
    printf("Enter number of elements in the array: ");
    scanf("%d", &n);
    
    printf("Enter sorted elements into the array:\n");
    for (i = 0; i < n; i++) {
        printf("Element - %d: ", i);
        scanf("%d", &a[i]);
    }
    
    printf("Enter key value: ");
    scanf("%d", &key);
    
    found = binary_recur_search(a, key, 0, n - 1);
    
    if (found != -1)
        printf("Key value found at position %d\n", found);
    else
        printf("Key value not found\n");

    return 0;
}

int binary_recur_search(int a[], int key, int low, int high) {
    if (low > high) {
        return -1;  // Base case: key not found
    }
    
    int mid = low + (high - low) / 2;  // Prevent overflow
    
    if (key == a[mid]) {
        return mid;  // Key found, return the index
    } else if (key < a[mid]) {
        return binary_recur_search(a, key, low, mid - 1);  // Search left half
    } else {
        return binary_recur_search(a, key, mid + 1, high);  // Search right half
    }
}
