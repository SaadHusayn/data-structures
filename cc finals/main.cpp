#include<bits/stdc++.h>
using namespace std;

#define int long long int

signed main(){
    int t;
    cin>>t;
    while(t--){
        int a, b, c, d;
        cin>>a>>c>>b>>d;

        int mini = min(a, c);
        int ans = 0;
        int diff, diff2;
        if(a == mini){
            if(b>d) ans = 1;
        }else{
            if(d>b) ans = 1;
        }

        if(ans) cout<<"No"<<endl;
        else cout<<"Yes"<<endl;
    }
}