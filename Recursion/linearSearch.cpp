#include<iostream>
using namespace std;

bool linearSearch(int arr[], int size, int target){
    if(size==0) return false;

    if(target == *arr) return true;
    else return linearSearch(arr+1, size-1, target);
}

int main(){
    int arr[] = { 1,2, 3};
    cout<<linearSearch(arr, 3, 1);
}