#include<iostream>
#include<vector>
#include<climits>
using namespace std;

void solve(){
    int n;
    cin>>n;

    int **a = new int*[n];
    for(int i=0;i<n;i++){
        a[i] = new int[n];
        for(int j=0;j<n;j++){
            cin>>a[i][j];
        }
    }

    int singleMax = INT_MIN;
    for(int i=0;i<n;i++){
        auto sum = 0 ;
        for(int j=0;j<n-i;j++){
            singleMax = max(singleMax, a[i+j][j]);
            sum += a[i+j][j];
        }
        singleMax = max(singleMax, sum);
    }

    for(int i=1;i<n;i++){
        auto sum = 0 ;
        for(int j=0;j<n-i;j++){
            singleMax = max(singleMax, a[i+j][j]);
            sum += a[i+j][j];
        }
        singleMax = max(singleMax, sum);
    }

    cout<<singleMax<<endl;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}