#ifndef MAX_HEAP_H
#define MAX_HEAP_H

#include<iostream>

class MAX_HEAP{
    public:
    int *arr;
    int size;
    int capacity;

    MAX_HEAP(int cap=20){
        capacity = cap;
        arr = new int[cap];
        size = 0;
    }

    void swap(int &a, int &b){ 
        a = a+b; 
        b = a-b; 
        a = a-b; 
    }

    void swim(int k){
    while(k>1 && (arr[k/2] < arr[k])){
        swap(arr[k], arr[k/2]);
        k/=2;
    }
    }   

    void sink(int k){
        while(2*k <= size){//means k has child
            //finding the largest child
            int j=2*k;//left child
            if(j<N && (arr[j+1] > arr[j])) j++;//take right child if it exists and is greater than the left one
            if(arr[k] >= arr[j]) break;//no need to sink
            swap(arr[k], arr[j]);
            k = j;
        }
    }

};



#endif