#include <iostream>
#include <cmath>

using namespace std;

void bubbleSort(float arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

bool isUniformlyDistributed(float arr[], int n) {
    float diff = arr[1] - arr[0];
    for (int i = 2; i < n; i++) {
        if (arr[i] - arr[i - 1] != diff) {
            return false;
        }
    }
    return true;
}

int interpolationSearch(float arr[], int n, float target) {
    int low = 0, high = n - 1;

    while (low <= high && target >= arr[low] && target <= arr[high]) {
        if (low == high) {
            if (arr[low] == target) return low;
            return -1;
        }

        int pos = low + ((target - arr[low]) * (high - low)) / (arr[high] - arr[low]);

        if (arr[pos] == target)
            return pos;
        if (arr[pos] < target)
            low = pos + 1;
        else
            high = pos - 1;
    }
    return -1;
}

int main() {
    int n;
    cout << "Enter the number of account balances: ";
    cin >> n;

    float arr[100];
    cout << "Enter the account balances: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    bubbleSort(arr, n);

    if (!isUniformlyDistributed(arr, n)) {
        cout << "Error: Data is not uniformly distributed after sorting." << endl;
        return 1;
    }

    float target;
    cout << "Enter the target balance to search: ";
    cin >> target;

    int result = interpolationSearch(arr, n, target);

    if (result != -1)
        cout << "Account balance found at index: " << result << endl;
    else
        cout << "Account balance not found." << endl;

    return 0;
}
