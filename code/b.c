// Linear Search Non - Recursion

#include <stdio.h>

int linear_nonrecur_search(int[], int, int);

int main() {
    int a[100], i, n, key, found;
    
    printf("Enter number of elements in the array: ");
    scanf("%d", &n);
    
    printf("Enter elements into the array:\n");
    for (i = 0; i < n; i++) {
        printf("Element - %d: ", i + 1);
        scanf("%d", &a[i]);
    }
    
    printf("Enter key value: ");
    scanf("%d", &key);
    
    found = linear_nonrecur_search(a, key, n);
    
    if (found != -1)
        printf("Key value found at position %d\n", found);
    else
        printf("Key value not found\n");

    return 0;
}

int linear_nonrecur_search(int a[], int key, int n) {
    for (int i = 0; i < n; i++) {
        if (key == a[i]) {
            return i;  // Return the index where the key is found
        }
    }
    return -1;  // Return -1 if the key is not found
}
