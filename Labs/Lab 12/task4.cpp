#include <iostream>
#include <vector>
using namespace std;

// Function to convert a character to lowercase
char toLowerChar(char c) {
    if (c >= 'A' && c <= 'Z') {
        return c + ('a' - 'A');
    }
    return c;
}

// Function to convert a string to lowercase
string toLowerCase(const string &str) {
    string lowerStr = str;
    for (char c : str) {
        lowerStr += toLowerChar(c);
    }
    return lowerStr;
}

// Function to build the Longest Prefix Suffix (LPS) array
vector<int> computeLPS(string pattern) {
    int m = pattern.length();
    vector<int> lps(m, 0); // Initialize LPS array with 0
    int length = 0; // Length of the previous longest prefix suffix
    int i = 1;

    while (i < m) {
        if (pattern[i] == pattern[length]) {
            length++;
            lps[i] = length; // Store the length of the current prefix suffix
            i++;
        } else {
            if (length != 0) {
                length = lps[length - 1]; // Fallback to the previous prefix suffix
            } else {
                lps[i] = 0; // No match found
                i++;
            }
        }
    }
    return lps;
}

// KMP algorithm to find all occurrences of the pattern in the text (case-insensitive)
vector<int> KMPSearch(string text, string pattern) {
    // Convert both text and pattern to lowercase for case-insensitivity
    text = toLowerCase(text);
    pattern = toLowerCase(pattern);

    int n = text.length();
    int m = pattern.length();
    vector<int> lps = computeLPS(pattern); // Preprocess the pattern
    vector<int> indices; // To store the starting indices of matches

    int i = 0; // Index for text
    int j = 0; // Index for pattern

    while (i < n) {
        if (text[i] == pattern[j]) {
            i++;
            j++;
        }

        if (j == m) { // Full match of the pattern
            indices.push_back(i - j); // Store the starting index
            j = lps[j - 1]; // Continue searching for more matches
        } else if (i < n && text[i] != pattern[j]) {
            if (j != 0) {
                j = lps[j - 1]; // Use LPS array to avoid unnecessary comparisons
            } else {
                i++; // Move to the next character in text
            }
        }
    }

    return indices;
}

int main() {
    string text = "data Structures";
    string pattern = "data";

    vector<int> occurrences = KMPSearch(text, pattern);

    cout << "Pattern found at indices: ";
    for (int idx : occurrences) {
        cout << idx << " ";
    }
    cout << endl;

    return 0;
}
