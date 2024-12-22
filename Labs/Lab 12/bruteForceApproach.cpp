#include<iostream>

using namespace std;

void bruteForceSearch(string text, string pattern){
    int n = text.length();
    int m = pattern.length();

    for(int i=0;i<=n-m;i++){
        int j = 0;
        for(;j<m && (text[i+j] == pattern[j]);j++) ;
        cout<<j<<endl;
        if(j==m){
            cout<<"Pattern found at index: "<<i<<endl;
        }
    }
}

int main(){
    string text = "AFFAN";
    string pattern = "FFAN";

    // cin>>text>>pattern;

    bruteForceSearch(text, pattern);

}

