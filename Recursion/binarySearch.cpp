#include<iostream>
using namespace std;

int binarySearch(int arr[], int start, int end, int target){
    if(start>end) return -1;

    int mid = (start + end)/2;

    if(target == arr[mid]) return mid;
    
    else if(target > arr[mid]) return binarySearch(arr, mid+1, end, target);

    else return binarySearch(arr, start, mid-1, target);
}

int main(){

    int arr[] = {1, 2,3 , 5, 99, 101};
    cout<<binarySearch(arr, 0, 5, 99);

}