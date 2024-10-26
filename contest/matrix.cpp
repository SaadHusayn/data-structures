#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int countBeautifulSegments(const vector<int>& a) {
    unordered_map<int, int> prefixSumIndex;
    int currentPrefixSum = 0;
    int count = 0;
    int lastSegmentEnd = -1;

    // Initialize the prefix sum map with the base case
    prefixSumIndex[0] = -1; // This handles the case where a segment starts from index 0

    for (int i = 0; i < a.size(); ++i) {
        currentPrefixSum += a[i];

        // Check if we have seen this prefix sum before
        if (prefixSumIndex.find(currentPrefixSum) != prefixSumIndex.end()) {
            // Get the last index where this prefix sum occurred
            int lastIndex = prefixSumIndex[currentPrefixSum];

            // If the last index is greater than the end of the last beautiful segment
            if (lastIndex >= lastSegmentEnd) {
                count++; // Found a new beautiful segment
                lastSegmentEnd = i; // Update the end of the last segment
            }
        }

        // Update the latest index for this prefix sum
        prefixSumIndex[currentPrefixSum] = i;
    }

    return count;
}

int main() {
    int t;
    cin >> t; // Read the number of test cases
    while (t--) {
        int n;
        cin >> n; // Read the size of the array
        vector<int> a(n);

        // Read the array elements
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        // Calculate and print the number of non-overlapping beautiful segments
        cout << countBeautifulSegments(a) << endl;
    }
    return 0;
}
