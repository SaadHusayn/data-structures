#include <iostream>
#include <cmath>
using namespace std;

int minOperationsToNonIncreasing(int arr[], int n) {
    int operations = 0;

    for (int i = n - 2; i >= 0; i--) {
        if (arr[i] < arr[i + 1]) {
            operations += abs(arr[i] - arr[i + 1]);
            arr[i] = arr[i + 1]; 
        }
    }

    return operations;
}

int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    int* arr = new int[n];
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int result = minOperationsToNonIncreasing(arr, n);
    cout << "Minimum number of operations required: " << result << endl;

    return 0;
}