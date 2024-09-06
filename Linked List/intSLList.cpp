#include<iostream>
#include "intSLList.h"
#include <algorithm>



IntSLList::~IntSLList() {
    for(IntSLLNode *p; !isEmpty();){
        p = head->next;
        delete p;
        head = p;
    }
}

void IntSLList::addToHead(int _data){
    head = new IntSLLNode(_data, head);
    if (tail == 0) tail = head;
}

void IntSLList::addToTail(int _data){
    if(tail != 0){ //if list is not empty
        tail->next = new IntSLLNode(_data);;
        tail = tail->next;
    }
    else head = tail = new IntSLLNode(_data);
}

int IntSLList::deleteFromHead(){
    int data = head->data;
    IntSLLNode *tmp = head;
    if(head == tail) head = tail = 0; //if only node in the list;
    else head=head->next;
    delete tmp;
    return data;
}

int IntSLList::deleteFromTail(){
    int data=tail->data;
    if(head != tail){//list contains more than one nodes
        IntSLLNode *tmp=head; //find predecessor of tail;
        for(; tmp->next != tail; tmp=tmp->next);
        delete tail;
        tail = tmp; //the predecessor of tail becomes tail
        tail->next = 0;
    }
    else{
        delete head;
        head = tail = 0;
    }
    return data;
}

void IntSLList::deleteNode(int _data){
    // if(head->data == _data){//head is to be deleted
    //     deleteFromHead();
    // }
    // else if(tail->data == _data){//tail is to be deleted
    //     deleteFromTail();
    // }
    // else{//middle node is to be deleted
    //     IntSLLNode *prev = head;
    //     IntSLLNode *tmp = head->next;
    //     for(;tmp->next != 0 && tmp->data != _data;prev=tmp, tmp=tmp->next);
    //     if(tmp->data == _data){//node found
    //         prev->next = tmp->next;
    //         delete tmp;
    //     }
    // }

    if(head != 0){//list is not empty
        if(head == tail && head->data==_data){//if list has only node
            delete head;
            head = tail = 0;
        }
        else if(head->data == _data){//if list has more than one nodes and head is the required node
            IntSLLNode *tmp = head;
            head = head->next;
            delete tmp;
        }
        else{//list has more than one nodes and head node is not the required node
            
        }
    }
}