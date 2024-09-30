#include<iostream>
using namespace std;

void sort(int arr[4][4], int N){
    for(int i=0;i<N;i++){


        for(int j=0;j<N;j++){ 

            for(int k = j; k>0 && (arr[i][k]< arr[i][k-1]);k--) swap(arr[i][k], arr[i][k-1]);

        }


    }
}

int main(){
    int arr[4][4];

    for(auto i=0;i<4;i++){
        for(auto j=0;j<4;j++){
            cin>>arr[i][j];
        }
    }

    cout<<endl;

    for(auto i=0;i<4;i++){
        for(auto j=0;j<4;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }

    sort(arr, 4);

    cout<<endl;

    for(auto i=0;i<4;i++){
        for(auto j=0;j<4;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
}