#include<iostream>
using namespace std;

#define ll long long 

int main(){

    int t=1;
    cin >> t;

    for(int i =0 ; i < t; i++) {
        int a, b, c, d;
        cin>>a>>b>>c>>d;
        int ans = 0;
        if(a != b){
            ans ++;
            if(c!=d) ans++;
        }else if(a != c){
            ans ++;
            if(b != d) ans++;
        }else if(a != d){
            ans ++;
            if(b != c) ans++;
        }

        cout<<ans<<endl;
    }
}
