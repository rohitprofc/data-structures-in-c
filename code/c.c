// Linear Search with Recursion

#include <stdio.h>

int linear_recur_search(int[], int, int, int);

int main() {
    int a[100], n, key, i, found = 0;
    
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    
    printf("Enter elements into the array:\n");
    for (i = 0; i < n; i++) {
        printf("Element - %d: ", i);
        scanf("%d", &a[i]);
    }
    
    printf("Enter key value: ");
    scanf("%d", &key);
    
    found = linear_recur_search(a, n, key, 0);
    
    if (found != -1)
        printf("Key value found at position %d\n", found);
    else
        printf("Key value not found\n");

    return 0;
}

int linear_recur_search(int a[], int n, int key, int i) {
    if (i >= n) {
        return -1;  // Base case: If index exceeds size, return -1 (not found)
    }
    
    if (key == a[i]) {
        return i;  // Return the index if the key is found
    }
    
    return linear_recur_search(a, n, key, i + 1);  // Recursive case: Search the next index
}
