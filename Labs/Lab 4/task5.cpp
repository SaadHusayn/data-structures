#include <iostream>

using namespace std;

void combSort(float prices[], int n, float shrinkFactor) {
    int gap = n;
    bool swapped = true;

    while (gap > 1 || swapped) {
        gap = max(1, static_cast<int>(gap / shrinkFactor));
        swapped = false;

        for (int i = 0; i + gap < n; i++) {
            if (prices[i] > prices[i + gap]) {
                swap(prices[i], prices[i + gap]);
                swapped = true;
            }
        }
    }
}

int main() {
    float prices[] = {85.5, 45.6, 63.7, 29.9, 78.3, 94.2, 51.0, 82.1, 39.5};
    int n = sizeof(prices) / sizeof(prices[0]);
    float customShrinkFactor = 1.7;

    for (int i = 0; i < n; i++) {
        cout << prices[i] << " ";
    }

    cout<<endl;
    cout<<endl;

    combSort(prices, n, customShrinkFactor);

    for (int i = 0; i < n; i++) {
        cout << prices[i] << " ";
    }

    return 0;
}
