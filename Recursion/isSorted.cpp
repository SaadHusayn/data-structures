#include<iostream>
using namespace std;

bool isSorted(int arr[],int size){
    if(size<2) return true;

    if(arr[1] < arr[0]) return false;
    else return isSorted(arr+1, size-1);
}

int main(){
 int arr[] = {1, 3, 6};
 cout<<isSorted(arr, 3);
}