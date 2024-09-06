#ifndef CLL_H

#define CLL_H

class Node{
    public:
    int val;
    Node *next;

    Node(){next=nullptr;}
    Node(int _val):val(_val){next=nullptr;}
};

class CLL{
    public:
    Node *head;
    Node *tail;

    CLL(){head = nullptr; tail = nullptr;}

    void insertAtEnd(int _val){
        Node *n = new Node(_val);

        if(head == nullptr){
            head = n;
            tail = n;
            tail->next = head;
        }

        tail->next = n;
        tail = tail->next;
        tail->next = head;
    }

    void insertAtFront(int _val){
        Node *n = new Node(_val);
        tail->next = n;
        n->next = head;
        head = n;
    }
};

#endif