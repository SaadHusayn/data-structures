#ifndef STACKLL_H
#define STACKLL_H

#include<iostream>
using namespace std;

class Node{
    public:
    int val;
    Node *next;

    Node(){val=0; next=0;}
    Node(int _val){val=_val; next=0;}
    Node(int _val, Node *_next){
        val = _val;
        next = _next;
    }
};

class Stack{
    public:
    Node *top;

    Stack(){ top = 0;}

    void push(int _val){
        if(isEmpty()){
            top = new Node(_val);
        }else{
            auto tmp = new Node(_val);
            tmp->next = top;
            top = tmp;
        }
    }

    int pop(){
        if(isEmpty()){
            cerr<<"Stack is empty";
            exit(1);
        }else{
            auto tmp = top;
            top = top->next;
            auto toReturn = tmp->val;
            delete tmp;
            return toReturn;
        }
    }

    bool isEmpty(){return top==0;}

    void printStack(){
        for(auto i=top;i!=nullptr;i=i->next){
            cout<<i->val<<endl;
        }
        cout<<endl;
    }
};

#endif