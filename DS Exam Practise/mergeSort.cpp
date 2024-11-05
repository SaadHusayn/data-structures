#include<iostream>
using namespace std;
void printArray(int arr[], int s, int e){
    cout<<endl;
    for(int i=s;i<=e;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

}
void merge(int arr[], int s, int e){
    auto mid = s + (e-s)/2;
    auto n1 = mid - s + 1;
    auto n2 = e - mid;

    int *L = new int[n1];
    int *R = new int[n2];

    for(int i=0;i<n1;i++){
        L[i] = arr[s+i];
    }
    for(int i=0;i<n2;i++){
        R[i] =  arr[mid+1+i];
    }

    int i=0;
    int j=0;
    int k=s;
    while(i<n1 && j<n2){
        if(L[i]<R[j]) arr[k++] = L[i++];
        else arr[k++] = R[j++];
    }

    while(i<n1) {arr[k++] = L[i++];}

    while(j<n2) {arr[k++] = R[j++];}

}

void mergeSort(int arr[], int s, int e){
    if(s >= e) return ;

    auto mid = s + (e-s)/2;

    mergeSort(arr, s, mid);
    mergeSort(arr, mid+1, e);

    merge(arr, s, e);
    printArray(arr, s, e);
}



int main(){
    int arr[9] = {3, 1, 2, 4, 1, 5, 2, 6, 4};

    mergeSort(arr, 0, 8);

    printArray(arr, 0, 8);
}