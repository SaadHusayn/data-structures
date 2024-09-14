#include<iostream>
using namespace std;

int binarySearch(int arr[], int size, int target){
    int start = 0;
    int end = size - 1;
    int mid=0;
    while(start<=end){
        mid = (start + end)/2;

        if(target==arr[mid]) return mid;

        if(arr[mid]>target){
            end = mid - 1;
        }
        if(arr[mid]<target){
            start = mid + 1;
        }
    }

    return -1;
}

int main(){
    int arr[] = {1, 2, 3, 5, 6, 9};
    cout<<binarySearch(arr, 5, 322);
}