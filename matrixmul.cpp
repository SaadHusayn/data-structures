#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n;
    cin>>n;

    vector<vector<int>> a(n, vector<int>(n));
    vector<vector<int>> b(n, vector<int>(n));

    for(int i=0;i<n;i++) for(int j=0;j<n;j++) cin>>a[i][j];
    for(int i=0;i<n;i++) for(int j=0;j<n;j++) cin>>b[i][j];

    vector<vector<int>> ans(n, vector<int>(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            int sum = 0;
            for(int k =0; k<n;k++){
                sum+=(a[i][k]*b[k][j]);
            }
            ans[i][j] = sum;
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }

    

}