#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

void preprocess(const vector<string> &patterns, vector<unordered_map<char, int>> &badCharTables) {
    for (int k = 0; k < patterns.size(); ++k) {
        string pattern = patterns[k];
        unordered_map<char, int> &badChar = badCharTables[k];
        int m = pattern.size();
        for (int i = 0; i < m; ++i)
            badChar[pattern[i]] = i;
    }
}

void BoyerMooreSearch(const string &text, const vector<string> &patterns) {
    vector<unordered_map<char, int>> badCharTables(patterns.size());
    preprocess(patterns, badCharTables);

    for (int k = 0; k < patterns.size(); ++k) {
        string pattern = patterns[k];
        unordered_map<char, int> &badChar = badCharTables[k];
        int n = text.size(), m = pattern.size();
        int shift = 0;

        while (shift <= n - m) {
            int j = m - 1;
            while (j >= 0 && pattern[j] == text[shift + j])
                --j;

            if (j < 0) {
                cout << "Pattern " << pattern << " found at index " << shift << endl;
                shift += (shift + m < n) ? m - badChar[text[shift + m]] : 1;
            } else {
                shift += max(1, j - badChar[text[shift + j]]);
            }
        }
    }
}

int main() {
    string text = "ABCDEFG";
    vector<string> patterns = {"ABC", "EFG"};
    BoyerMooreSearch(text, patterns);
    return 0;
}
