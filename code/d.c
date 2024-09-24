// Binary Search Non - Recursion

#include <stdio.h>

int binary_nonrecur_search(int[], int, int, int);

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
    
    found = binary_nonrecur_search(a, key, 0, n - 1);
    
    if (found != -1)
        printf("Key value found at position %d\n", found);
    else
        printf("Key value not found\n");

    return 0;
}

int binary_nonrecur_search(int a[], int key, int low, int high) {
    while (low <= high) {
        int mid = low + (high - low) / 2;  // Prevents overflow
        
        if (key == a[mid]) {
            return mid;  // Return the index where the key is found
        } else if (key < a[mid]) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return -1;  // Return -1 if the key is not found
}
