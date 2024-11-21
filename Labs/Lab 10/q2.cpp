#include<iostream>
#include "MAX_HEAP.h"
#include "MIN_HEAP.h"

using namespace std;

// Function to maintain the max-heap property
void heapify(int arr[], int n, int i) {
    int largest = i;       // Initialize the largest as root
    int left = 2 * i + 1;  // Left child index
    int right = 2 * i + 2; // Right child index

    // Check if the left child is larger than the root
    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }

    // Check if the right child is larger than the largest so far
    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }

    // If the largest is not the root
    if (largest != i) {
        swap(arr[i], arr[largest]);

        // Recursively heapify the affected sub-tree
        heapify(arr, n, largest);
    }
}

// Function to perform heap sort
void heapSort(int arr[], int n) {
    // Build the max heap
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }

    // Extract elements one by one from the heap
    for (int i = n - 1; i > 0; i--) {
        // Move the current root to the end
        swap(arr[0], arr[i]);

        // Call heapify on the reduced heap
        heapify(arr, i, 0);
    }
}


int main(){
    MinHeap minh(20);

    int data[] = {35, 33, 42, 10, 14, 19, 27, 44, 26, 31};

    for(int i=0;i<10;i++){
        minh.insert(data[i]);
    }

    int deletedValue;
    minh.deleteMin(deletedValue);
    MaxHeap maxh(20);

    for(int i=0;i<minh.size;i++){
        maxh.insert(minh.heapArray[i]);
    }

    heapSort(maxh.heapArray, maxh.size);

    cout<<"Max heap after sorting: ";
    maxh.print();



}