#include<iostream>
#include<vector>
using namespace std;

int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        int n;
        cin>>n;
        vector<long long> vec(n);
        for(auto i=0;i<n;i++){
            cin>>vec[i];
        }

        if(n==1){
            cout<<"Case "<<i+1<<": "<<vec[0]<<endl;
        }else{
            int k=0;
            int current_k=0;
            bool first=true;
            for(auto j=0;j<n;j++){
                if(first){
                    k=vec[j];
                    current_k = k-1;
                    first = false;
                }else{
                    int diff = vec[j] - vec[j-1];
                    if(diff>current_k){
                        if(k==diff)k++;
                        else k= diff;
                        current_k = k -1;
                    }else if(diff == current_k){
                        current_k--;
                    }
                }

            }

            cout<<"Case "<<i+1<<": "<<k<<endl;
        }

    }
}