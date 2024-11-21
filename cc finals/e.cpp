#include<bits/stdc++.h>
using namespace std;

#define int long long int


signed main(){
    string s;
    cin>>s;
    int lastA = -1;
    for(int i=0;i<s.size();i++){
        if(s[i] == 'a') lastA = i;
    }

    if(lastA == -1) {
        cout<<":(";
        return 0;
    }

    string s1;
    string s2;
    for(int i=0;i<=lastA;i++){
        if(s[i] != 'a') s1.push_back(s[i]);
    }
    for(int i=lastA+1;i<s.size();i++){
        s2.push_back(s[i]);
    }

    if(s1.size() > s2.size()){
        cout<<":(";
        return 0;
    }

    if(s1.size() == s2.size()){
        if(s1 == s2){
            for(int i=0;i<s.size()-s2.size();i++){
                cout<<s[i];
            }
            return 0;
        }else{
            cout<<":(";
            return 0;
        }
    }

    while((s2.size()!=0 ) && (s1.size() != s2.size())){
        char ch = s2[0];
        if(s2.size() >=2)  s2 = s2.substr(1);
        else s2 = "";
        s1.push_back(ch);
    }


    if(s1 == s2){
            for(int i=0;i<s.size()-s2.size();i++){
                cout<<s[i];
            };
            return 0;
    }else{
            cout<<":(";
            return 0;
    }
    

}