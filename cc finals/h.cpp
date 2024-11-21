#include<bits/stdc++.h>
using namespace std;

#define int long long int

signed main(){
   string n;
   cin >> n;

   int ans = 1; int sum=0;
   for(int i=0; i<n.size(); i++){
        int digit = n[i] - '0';
        sum += digit;
   }

   if (sum%9!=0) ans=0;

   if (ans) cout << "Yes\n";
   else cout << "No\n";
}