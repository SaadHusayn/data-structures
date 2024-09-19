#include <iostream>
#include <algorithm>

using namespace std;

int binarySearchPosition(int arr[], int size, int value) {
    int low = 0, high = size - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == value)
            return mid;
        else if (arr[mid] < value)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

int findInsertionPoint(int arr[], int size, int value) {
    int low = 0, high = size - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] < value)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return low;
}

void insertAtPosition(int arr[], int& size, int value) {
    int pos = findInsertionPoint(arr, size, value);
    for (int i = size; i > pos; i--) {
        arr[i] = arr[i - 1];
    }
    arr[pos] = value;
    size++;
}

int main() {
    int arr[100] = {101, 203, 307, 456, 567, 678, 789};
    int size = 7;
    int rollNumber = 705;
    int lastTwoDigits = rollNumber % 100;

    int pos = binarySearchPosition(arr, size, lastTwoDigits);
    if (pos == -1) {
        insertAtPosition(arr, size, lastTwoDigits);
    }

    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}
