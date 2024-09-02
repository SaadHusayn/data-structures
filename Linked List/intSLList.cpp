#include<iostream>
#include "intSLList.h"

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