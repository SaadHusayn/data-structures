#include <iostream>
using namespace std;

// Function to heapify a subtree rooted at index `i`
// `n` is the size of the heap
void heapify(int arr[], int n, int i) {
    int largest = i;       // Initialize largest as root
    int left = 2 * i + 1;  // Left child index
    int right = 2 * i + 2; // Right child index

    // Check if left child exists and is greater than root
    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }

    // Check if right child exists and is greater than the largest so far
    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }

    // If the largest is not root
    if (largest != i) {
        swap(arr[i], arr[largest]); // Swap root and the largest element

        // Recursively heapify the affected sub-tree
        heapify(arr, n, largest);
    }
}

// Function to build a max heap
void buildHeap(int arr[], int n) {
    // Start from the last non-leaf node and heapify each node
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }
}

// Function to perform heap sort
void heapSort(int arr[], int n) {
    // Step 1: Build a max heap
    buildHeap(arr, n);

    // Step 2: Extract elements one by one
    for (int i = n - 1; i > 0; i--) {
        // Move the current root to the end
        swap(arr[0], arr[i]);

        // Reduce the heap size and heapify the root
        heapify(arr, i, 0);
    }
}

// Function to print the array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Driver code
int main() {
    int N = 5;
    int arr[] = {4, 1, 3, 9, 7};

    cout << "Original array: ";
    printArray(arr, N);

    heapSort(arr, N);

    cout << "Sorted array: ";
    printArray(arr, N);

    return 0;
}
