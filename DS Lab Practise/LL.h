#ifndef LL_H
#define LL_H

class Node{
    public:

    int data;
    Node *next;

    Node(int _data=0, Node *_next=nullptr){
        data=_data;
        next=_next;
    }

};

#endif