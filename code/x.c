// Heap sort


#include <stdio.h>

void heapify(int a[], int n, int i)
{
    int largest = i;       // Initialize largest as root
    int left = 2 * i + 1;  // Left child
    int right = 2 * i + 2; // Right child

    // If the left child is larger than the root
    if (left < n && a[left] > a[largest])
        largest = left;

    // If the right child is larger than the current largest
    if (right < n && a[right] > a[largest])
        largest = right;

    // If the largest is not root, swap and heapify the affected subtree
    if (largest != i)
    {
        int temp = a[i];
        a[i] = a[largest];
        a[largest] = temp;

        // Recursively heapify the affected subtree
        heapify(a, n, largest);
    }
}

void heapSort(int a[], int n)
{
    // Build a max heap (rearrange the array)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(a, n, i);

    // One by one extract elements from the heap
    for (int i = n - 1; i > 0; i--)
    {
        // Move current root to end (since it's the largest)
        int temp = a[0];
        a[0] = a[i];
        a[i] = temp;

        // Call heapify on the reduced heap
        heapify(a, i, 0);
    }
}

void printArr(int arr[], int n)
{
    for (int i = 0; i < n; ++i)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main()
{
    int a[100], n;

    // Input size of the array
    printf("Enter size of the heap: ");
    scanf("%d", &n);

    // Input elements
    printf("Enter elements into the heap:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    // Print array before sorting
    printf("Before sorting, array elements are: \n");
    printArr(a, n);

    // Perform heap sort
    heapSort(a, n);

    // Print array after sorting
    printf("After sorting, array elements are: \n");
    printArr(a, n);

    return 0;
}
