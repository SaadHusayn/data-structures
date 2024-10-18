#include<iostream>
using namespace std;

void mergeSort(int *arr, int s, int e){
    if(s>=e) return;

    auto mid = s + (e-s)/2;

    mergeSort(arr, s, mid);
    mergeSort(arr, mid+1, e);

    join(arr, s, e, )
}

int main(){
    int *arr = new int[5] { 3, 4, 1, 9, 1};

    mergeSort(arr, 0, 4);
}