#include<iostream>
#include<vector>
using namespace std;

// Write a program using the Brute Force Algorithm to search for overlapping occurrences of
// a pattern in a string. For example, in the text "ABABABA", the pattern "ABA" overlaps
// and should be detected at indices 0 and 2.

vector<int> overlappingOccurences(string text, string pattern){
    int n = text.length();
    int m = pattern.length();



    vector<int> indices;

    int prev = -1;

    for(int i=0;i<=n-m;i++){
        int j=0;
        for(;(j<m) && (text[i+j] == pattern[j]);j++) ;

        if(j==m){
            //pattern find at i
            if(prev != -1){
                int diff = i - prev;
                if(diff>=0 && diff<m) {
                    indices.push_back(prev);
                }
            }

            prev = i;
        }

    }

    return indices;
}   

int main(){
    string text ="ABABABA";
    string pattern = "ABA";

    vector<int> overlappingIndices = overlappingOccurences(text, pattern);

    cout<<"Overlapping occurences detected at the indices: ";
    for(auto i:overlappingIndices) cout<<i<<" ";
    cout<<endl;
}