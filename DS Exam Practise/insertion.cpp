#include<iostream>
using namespace std;


int main(){
    int arr[] = {6, 9, 7, 3, 4, 2};

    int n = 6;

    for(int i=1;i<n;i++){
        for(int j=i;j>0 && (arr[j] < arr[j-1]);j--) swap(arr[j], arr[j-1]);
    }

    for(int i=0;i<n;i++) cout<<arr[i]<<" ";
}