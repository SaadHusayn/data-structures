#include<bits/stdc++.h>
using namespace std;

#define int long long int


signed main(){
    int n, m;
    cin>>n>>m;
    int l, r;
    int a, b;
    for(int i=0;i<m;i++){
        cin>>a>>b;
        if(i==0) {
            l = a;
            r = b;
        }else{
            l = max(l, a);
            r = min(r, b);
        }
    }

    if (l>r) {cout <<0<<endl; return 0;}
    int ans=0;

    for(int i=1; i<=n; i++){
        // cout<<n<<i<<endl;
        if (l<=i && i<=r) ans++;
    }
    cout << ans << endl;

}