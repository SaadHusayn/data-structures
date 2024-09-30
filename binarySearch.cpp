#include<iostream>
using namespace std;

int binarySearch(int arr[], int size, int target){
    int start = 0;
    int end = size - 1;
    int mid=0;
    while(start<=end){
        mid = start + (end-start)/2;

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

int interpolationSearch(int arr[], int size, int target){
    int low  = 0;
    int high = size - 1;
    int pos=0;
    while(low<=high && target>=arr[low]  && target<=arr[high]){
        pos = low + (target - arr[low])*(high - low)/(arr[high] - arr[low]);

        if(target==arr[pos]) return pos;

        if(arr[pos]>target){
            high = pos - 1;
        }
        if(arr[pos]<target){
            low = pos + 1;
        }
    }

    return -1;
}

int main(){
    int arr[] = {1, 2, 3, 5, 6, 9};
    cout<<interpolationSearch(arr, 6, 3);
}