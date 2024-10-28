#include<bits/stdc++.h>
using namespace std;

int solve(){
    int n;
    cin>>n;
    vector<vector<int>> v(n, vector<int>(2));

    for(int i=0;i<n;i++){
        cin>>v[i][0]>>v[i][1];
    }

    int wbound = v[0][0];
    int hbound = v[0][1];

    int current_parameter = 2*(wbound + hbound);

    for(int i=1;i<n;i++){
        int hdiff = 0;
        int wdiff = 0;

        if(v[i][0] > wbound){
            wdiff = v[i][0] - wbound;
            wbound = v[i][0];
        }

        if(v[i][1] > hbound){
            hdiff = v[i][1] - hbound;
            hbound = v[i][1];
        }

        current_parameter += 2*wdiff + 2*hdiff;
    }

    return current_parameter;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        cout<<solve()<<endl;
    }
}