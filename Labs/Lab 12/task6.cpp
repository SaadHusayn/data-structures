#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;

bool isPalindrome(const string &str) {
    int l = 0, r = str.size() - 1;
    while (l < r) {
        if (str[l++] != str[r--])
            return false;
    }
    return true;
}

void findPalindromes(const string &text) {
    unordered_set<string> palindromes;
    int n = text.size();
    for (int i = 0; i < n; ++i) {
        for (int len = 1; len <= n - i; ++len) {
            string sub = text.substr(i, len);
            if (isPalindrome(sub))
                palindromes.insert(sub);
        }
    }
    for (const string &pal : palindromes)
        cout << pal << endl;
}

int main() {
    string text = "ABCBAB";
    findPalindromes(text);
    return 0;
}
