#ifndef MIN_HEAP_H
#define MIN_HEAP_H

#include <iostream>
using namespace std;

class MinHeap {
public:
    int* heapArray;   // Pointer to the array representing the heap
    int capacity;     // Maximum capacity of the heap
    int size;         // Current number of elements in the heap

    // Helper function to maintain the heap property after insertion
    void heapifyUp(int index) {
        while (index > 0) {
            int parent = (index - 1) / 2;

            if (heapArray[index] < heapArray[parent]) {
                swap(heapArray[index], heapArray[parent]);
                index = parent;
            } else {
                break;
            }
        }
    }

    // Helper function to maintain the heap property after deletion
    void heapifyDown(int index) {
        while (index < size) {
            int leftChild = 2 * index + 1;
            int rightChild = 2 * index + 2;
            int smallest = index;

            if (leftChild < size && heapArray[leftChild] < heapArray[smallest]) {
                smallest = leftChild;
            }

            if (rightChild < size && heapArray[rightChild] < heapArray[smallest]) {
                smallest = rightChild;
            }

            if (smallest != index) {
                swap(heapArray[index], heapArray[smallest]);
                index = smallest;
            } else {
                break;
            }
        }
    }

    // Constructor to initialize the heap with a given capacity
    MinHeap(int maxCapacity) {
        capacity = maxCapacity;
        size = 0;
        heapArray = new int[capacity];
    }

    // Destructor to clean up allocated memory
    ~MinHeap() {
        delete[] heapArray;
    }

    // Inserts a new value into the heap
    bool insert(int value) {
        if (size >= capacity) {
            cerr << "Heap is full. Cannot insert new element." << endl;
            return false;
        }

        heapArray[size] = value;
        heapifyUp(size);
        size++;
        return true;
    }

    // Deletes the minimum value (root) from the heap
    bool deleteMin(int& deletedValue) {
        if (size <= 0) {
            cerr << "Heap is empty. Cannot delete element." << endl;
            return false;
        }

        deletedValue = heapArray[0];
        heapArray[0] = heapArray[size - 1];
        size--;
        heapifyDown(0);
        return true;
    }

    // Searches for a value in the heap
    bool search(int value) const {
        for (int i = 0; i < size; i++) {
            if (heapArray[i] == value) {
                return true;
            }
        }
        return false;
    }

    // Prints the heap elements
    void print() const {
        for (int i = 0; i < size; i++) {
            cout << heapArray[i] << " ";
        }
        cout << endl;
    }
};

#endif // MIN_HEAP_H
