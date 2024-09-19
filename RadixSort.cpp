#include<iostream>
#include<vector>
#include<cmath>
#include<ctime>
#include<climits>

using namespace std;

int GetIndividualDigit(size_t index, int num) {
    return num / (int)pow(10, index - 1) % 10; 
}

void RadixSortLSD(int* a, size_t n) {
    int max = INT_MIN;
    for(size_t i = 0; i < n; i++) {
        if (a[i] > max)
            max = a[i];
    }

    size_t max_digits = 0;
    while (max != 0) {
        max /= 10;
        max_digits++;
    }

    vector<vector<int>> bucket(10);
    for(size_t i = 1; i <= max_digits; i++) {
        for(size_t j = 0; j < n; j++) {
            int digit = GetIndividualDigit(i, a[j]);
            bucket[digit].push_back(a[j]);
        }

        size_t index = 0;
        for(size_t j = 0; j < 10; j++) {
            for(size_t k = 0; k < bucket[j].size(); k++) 
                a[index++] = bucket[j][k];
        
            bucket[j].clear(); 
        }
    }
}

void RadixSortRecursiveStep(int* a, size_t n, size_t digitIndex) {
    if (digitIndex < 1)
        return;

    vector<vector<int>> bucket(10);
    for(size_t i = 0; i < n; i++) {
        int digit = GetIndividualDigit(digitIndex, a[i]);
        bucket[digit].push_back(a[i]);
    }

    size_t index = 0;
    for(size_t i = 0; i < 10; i++) {
        if (bucket[i].size() > 1)
            RadixSortRecursiveStep(&bucket[i][0], bucket[i].size(), digitIndex - 1);
        
        for(size_t j = 0; j < bucket[i].size(); j++) 
            a[index++] = bucket[i][j];
        
        bucket[i].clear();
    }
}

void RadixSortMSD(int* a, size_t n) {
    int max = INT_MIN;
    for(size_t i = 0; i < n; i++) {
        if (a[i] > max)
            max = a[i];
    }

    size_t max_digits = 0;
    while (max != 0) {
        max /= 10;
        max_digits++;
    }

    RadixSortRecursiveStep(a, n, max_digits);
}

int main(void) {
    srand(static_cast<unsigned int>(time(0))); 

    const size_t size = 5;
    int a[size];

    for (size_t i = 0; i < size; i++) 
        a[i] = rand() % 5000 + 1;
    

    cout << endl << "Unsorted Array: ["; 
    for (size_t i = 0; i < size; i++) 
        cout << a[i] << ", ";
    cout << "\b\b]" << endl;    

    RadixSortLSD(a, size);

    cout << endl << "Sorted Array: ["; 
    for (size_t i = 0; i < size; i++) 
        cout << a[i] << ", ";
    cout << "\b\b]" << endl;

    return 0;
}