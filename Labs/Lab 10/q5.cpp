#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

class Heap {
public:
    int arr[100];     
    int size;

    Heap() {
        arr[0] = -1;
        size = 0;
    }

    void insert(int val) {
        size += 1;
        int index = size;
        arr[index] = val;
        
        while (index > 1) {
            int parent = index / 2;
            if (arr[index] > arr[parent]) {
                swap(arr[index], arr[parent]);
                index = parent;
            } else {
                return;
            }
        }
    }

    void print() {
        for (int i = 1; i <= size; i++) {
            cout << arr[i] <<" ";
        }
        cout << endl;
    }

    void heapify(int i, int n) {
        int largest = i;
        int left = 2 * i;
        int right = 2 * i + 1;

        if (left <= n && arr[left] < arr[largest]) {
            largest = left;
        }
        if (right <= n && arr[right] < arr[largest]) {
            largest = right;
        }

        if (largest != i) {
            swap(arr[i], arr[largest]);
            heapify(largest, n);
        }
    }

    void heapSort() {
        // Build the max heap
        for (int i = size / 2; i > 0; i--) {
            heapify(i, size);
        }

        // Extract elements from the heap
        for (int i = size; i > 1; i--) {
            swap(arr[1], arr[i]);
            heapify(1, i - 1);
        }
    }
};

int main() {
    Heap h;

    h.insert(1);
    h.insert(2);
    h.insert(3);
    h.insert(5);
    h.insert(4);
    h.insert(9);


    h.heapSort();

    h.print();

    return 0;
}