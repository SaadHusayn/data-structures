#include<iostream>
using namespace std;

void mySwap(int &a, int &b){
    if(a==b) return;

    a = a^b;
    b = a^b;
    a = a^b;
}

void bubbleSort(int *arr, int size){
    for(auto i=0;i<size-1;i++){
        for(auto j=0;j<size-i-1;j++){
            if(arr[j] > arr[j+1]) mySwap(arr[j], arr[j+1]);
        }
    }
}

void selectionSort(int *arr, int size){
    for(auto i=0;i<size-1;i++){
        auto min_value = i;
        for(auto j=i+1;j<size;j++){
            if(arr[j] < arr[min_value]) min_value = j;
        }

        mySwap(arr[i], arr[min_value]);
    }
}

void insertionSort(int *arr, int size){
    for(auto i=0;i<size;i++){
        for(auto j=i;j>0 && (arr[j-1] < arr[j]); j--) mySwap(arr[j], arr[j-1]);
    }
}

void shellSort(int *arr, int size){
    int h=1;
    while(h < size/3) h = 3*h + 1;

    while(h >= 1){
        for(auto i=h;i<size;i++){
            for(auto j=i;j>=h && (arr[j] < arr[j-h]);j-=h){
                mySwap(arr[j], arr[j-h]);
            }
        }
        h = h/3;
    }
}

void printArr(int *arr, int size){
    for(auto i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main(){
    int arr[] = {2 , 6, 1, 9, 5, 3};
    printArr(arr, 6);
    shellSort(arr, 6);
    printArr(arr, 6);

}