#include<iostream>
using namespace std;

class Heap{
    public:
    int size;
    int capacity;
    int *arr;
    
    Heap(int _capacity){
        capacity = _capacity;
        arr = new int[capacity+1];
        size = 0;
    }

    Heap(int a[], int n){
        int arr = new int[n+1];
        for(int i=1;i<=n;i++){
            arr[i] = a[i-1]; 
        }
        int size = n;
        int capacity = n;
        for(int k=size/2;k>=1;k--){
            sink(k,size);
        }

    }

    void swim(int k){
        while(k>1 && (arr[k] > arr[k/2])){
            swap(arr[k], arr[k/2]);
            k/=2;
        }
    }

    void sink(int k, int N){
        while(2*k <= N){
            int j = 2*k;
            if(j<N && (arr[j+1] > arr[j])) j++;
            if(arr[k] > arr[j]) break;
            swap(arr[k], arr[j]);
            k = j;
        }
    }


    void insertElement(int data){
        if(size<=capacity){
            arr[++size] = data;
            swim(size);
        }
    }

    void deleteElement(int data){
        if(size>0){
            for(int i=1;i<=size;i++){
                if(arr[i] == data){
                    swap(arr[i], arr[size]);
                    cout<<arr[size]<<" is deleted"<<endl;
                    size--;
                    sink(i, size);
                    break;
                }
            }
        }
    }

    void printHeap(){
        cout<<endl;
        for(int i=1;i<=size;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }


};



void HeapSort(int arr[], int n){
    Heap h1(arr, n);

    
}



int main(){
    Heap h1(7);
    h1.printHeap();

    for(int i=1;i<=7;i++){
        h1.insertElement(i);
    }
    h1.printHeap();


    h1.deleteElement(7);

    h1.printHeap();
}