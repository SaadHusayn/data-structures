#include<iostream>
using namespace std;

int arraySum(int arr[],int size){
    if(size==0) return 0;
    if(size==1) return *arr;
    
    return *arr + arraySum(arr+1, size-1);
}

int main(){
 int arr[] = {1, 3, 6};
 cout<<arraySum(arr, 3);
}