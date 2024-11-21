#include<bits/stdc++.h>
using namespace std;

#define int long long int

signed main(){
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    sort(v.begin(), v.end());
    double ans = v[0];
    for(int i=1;i<n;i++){
        ans = (v[i] + ans)/2.0;
    }

    cout<<setprecision(10) << ans <<endl;
}