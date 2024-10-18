#include<iostream>
using namespace std;

int binarySearch(int *arr, int s, int e, int target){
    if(s>e) return -1;

    auto mid = s + (e-s)/2;

    if(arr[mid] == target) return mid;

    if(arr[mid] > target) return binarySearch(arr, s, mid-1, target);

    return binarySearch(arr, mid+1, e, target);
}

int main(){
    int *arr = new int[5]{1, 2, 4, 5, 6};

    cout<<binarySearch(arr, 0, 4, 4);
}