#ifndef STACK_H
#define STACK_H

#include<iostream>
using namespace std;

template<typename T>
class Stack{
    public:
    T *arr;
    int capacity;
    int top;

    Stack(){
        arr = new T[10];
        capacity = 10;
        top = -1;
    }
    Stack(int _capacity){
        arr = new int[_capacity];
        capacity = _capacity;
        top = -1;
    }

    void push(T _val){
        if(isFull()){
            auto tmp = new int[2*capacity];
            for(int i=0;i<capacity;i++){
                tmp[i] = arr[i];
            }

            delete []arr;
            arr = tmp;
            capacity*=2;
        }

        arr[++top] = _val;
    }

    T pop(){
        if(isEmpty()){
            exit(1);
        }

        return arr[top--];
    }

    T peek(){
        if(isEmpty()){
            exit(1);
        }

        return arr[top];
    }


    bool isEmpty(){
        return top==-1;
    }
    
    bool isFull(){
        return top==capacity-1;
    }

    int size(){
        return top+1;
    }
    

};

#endif