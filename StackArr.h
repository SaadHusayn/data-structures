#ifndef STACK_H
#define STACK_H

#include<iostream>
using namespace std;

class Stack{
    public:
    int top;
    int capacity;
    int *arr;

    Stack(int _capacity){
        top = -1;
        capacity = _capacity;
        arr = new int[capacity];
    }

    ~Stack(){
        delete arr;
    }

    void push(int x){
        if(!isFull()){
            arr[++top] = x;
        }else{
            //aik nayi banao
            int *newArr = new int[2*capacity];
            for(int i=0;i<=top;i++){
                //purana element tu daalo yar
                newArr[i] = arr[i];
            }

            //purani delete kro memory sa
            delete arr;

            arr = newArr;
            arr[++top] = x;
        }
    }

    int pop(){
        if(!isEmpty()){
            return arr[top--];
        }
        else{
            cout<<"Stack is empty"<<endl;
            exit(1);
        }
    }

    bool isEmpty(){
        return (top==-1);
    }

    bool isFull(){
        return (top==(capacity-1));
    }

    void printStack(){
        cout<<endl;
        for(auto i=top;i>=0;i--){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
};

#endif