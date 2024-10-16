#include<iostream>
using namespace std;

string get_n_chars(int n){
    string s;
    for(int i=0;i<n;i++){
        s.append(1, 'A'+i);
    }

    return s;
}

string getSubString(string s, char ch){
    string res;
    for(int i=0;i<s.length();i++){
        if(s[i]!=ch) res.append(1, s[i]);
    }
    return res;
}

void Permutations(string s,  string current=""){
    if(s.length() == 0){
        cout<<current<<" ";
        return;
    }

    for(auto i=0;i<s.length();i++){
        auto substring = getSubString(s, s[i]);
        Permutations(substring, current + s[i]);
    }
    
}

int main(){

    // cout<<get_n_chars(3);
    Permutations(get_n_chars(9));
}