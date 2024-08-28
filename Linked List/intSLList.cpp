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