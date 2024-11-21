#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

class Heap {
public:
    int priority[100]; 
    int task[100];     
    int size;

    Heap() {
        priority[0] = -1; 
        task[0] = -1;
        size = 0;
    }

    void insert(int t, int p) {
        size += 1;
        int index = size;
        task[index] = t;
        priority[index] = p;

        while (index > 1) {
            int parent = index / 2;
            if (priority[index] > priority[parent]) {
                swap(priority[index], priority[parent]);
                swap(task[index], task[parent]);
                index = parent;
            } else {
                return;
            }
        }
    }

    void print() {
        for (int i = 1; i <= size; i++) {
            cout << "Task" << task[i] << " (Priority: " << priority[i] << ")" << endl;
        }
        cout << endl;
    }

    void heapify(int i, int n) {
        int largest = i;
        int left = 2 * i;
        int right = 2 * i + 1;

        if (left <= n && priority[left] < priority[largest]) {
            largest = left;
        }
        if (right <= n && priority[right] < priority[largest]) {
            largest = right;
        }

        if (largest != i) {
            swap(priority[i], priority[largest]);
            swap(task[i], task[largest]);
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
            swap(priority[1], priority[i]);
            swap(task[1], task[i]);
            heapify(1, i - 1);
        }
    }
};

int main() {
    srand(time(0));
    int n;
    cout << "Enter number of tasks: ";
    cin >> n;

    Heap h;

    for (int i = 0; i < n; i++) {
        int pri = rand() % 10 + 1; 
        h.insert(i + 1, pri);     
    }


    h.heapSort();

    h.print();

    return 0;
}