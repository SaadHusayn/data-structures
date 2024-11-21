#include<iostream>
#include "MAX_HEAP.h"
#include "MIN_HEAP.h"

using namespace std;

int main(){
    MaxHeap maxh(20);
    MinHeap minh(20);

    int data[] = {7, 1, 6, 2, 5, 9, 10, 2};

    for(int i=0;i<8;i++){
        maxh.insert(data[i]);
        minh.insert(data[i]);
    }

    cout<<"Max Heap is: ";
    maxh.print();

    cout<<"Min Heap is: ";
    minh.print();

    cout<<"Inserting 99 in both, now \n";

    maxh.insert(99);
    minh.insert(99);

    cout<<"Max Heap is: ";
    maxh.print();

    cout<<"Min Heap is: ";
    minh.print();

}