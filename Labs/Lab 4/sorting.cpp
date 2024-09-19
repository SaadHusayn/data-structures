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
        bool isSwapped = false;
        for(auto j=0;j<size-i-1;j++){
            if(arr[j+1]<arr[j]) {
                mySwap(arr[j], arr[j+1]);
                isSwapped = true;
            };
        }

        if(!isSwapped){
            break;
        }
    }
}

void selectionSort(int *arr, int size){
    for(auto i=0;i<size-1;i++){
        auto index = i;
        for(auto j=i+1;j<size;j++){
            if(arr[j]<arr[index]) index = j;
        }

        mySwap(arr[i], arr[index]);
    }
}

void insertionSort(int *arr, int size){
    for(int i=1;i<size;i++){
        for(auto j=i;j>0 && (arr[j]<arr[j-1]);j--) mySwap(arr[j], arr[j-1]);
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
    bubbleSort(arr, 6);
    printArr(arr, 6);

}