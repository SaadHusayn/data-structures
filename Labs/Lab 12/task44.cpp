#include <iostream>
#include <string>
#include <vector>
#include <cctype>
using namespace std;

void computeLPSArray(const string &pattern, vector<int> &lps) {
    int m = pattern.size(), length = 0, i = 1;
    lps[0] = 0;
    while (i < m) {
        if (tolower(pattern[i]) == tolower(pattern[length])) {
            ++length;
            lps[i++] = length;
        } else if (length) {
            length = lps[length - 1];
        } else {
            lps[i++] = 0;
        }
    }
}

void KMPSearch(const string &text, const string &pattern) {
    int n = text.size(), m = pattern.size();
    vector<int> lps(m);
    computeLPSArray(pattern, lps);
    int i = 0, j = 0;
    while (i < n) {
        if (tolower(text[i]) == tolower(pattern[j])) {
            ++i, ++j;
        }
        if (j == m) {
            cout << "Pattern found at index " << i - j << endl;
            j = lps[j - 1];
        } else if (i < n && tolower(text[i]) != tolower(pattern[j])) {
            if (j)
                j = lps[j - 1];
            else
                ++i;
        }
    }
}

int main() {
    string text = "Data Structures", pattern = "data";
    KMPSearch(text, pattern);
    return 0;
}
