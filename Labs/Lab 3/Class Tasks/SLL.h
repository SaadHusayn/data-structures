#ifndef SLL_H
#define SLL_H

#include <iostream>
using namespace std;

class Node
{
public:
    int val;
    Node *next;

    Node() { next = nullptr; }
    Node(int _val) : val(_val) { next = nullptr; }
};

class SLL
{
    public:
    Node *head;


    SLL() { head = nullptr; }
    SLL(Node *n) { head = n; }
    

    void printList()
    {
        cout << endl;
        for (auto i = head; i != nullptr; i = i->next)
        {
            cout << i->val << " ";
        }
        cout << endl;
    }

    void append(int _val)
    {
        Node *newNode = new Node(_val);
        // if list is empty then newNode will be our first node of the list
        if (head == nullptr)
            head = newNode;
        else
        {
            // else traverse till end and then append
            Node *curr = head;
            for (; curr->next != nullptr; curr = curr->next)
                ;
            curr->next = newNode;
        }
    }

    void addAtFront(int _val){
        Node *n = new Node(_val);

        if(head == nullptr) head = n;
        else{
            n->next = head;
            head = n;
        }
    }

    void addAfterNode(Node * prev, int _val){
        Node *newNode = new Node(_val);
        newNode->next = prev->next;
        prev->next = newNode;
    }
};

#endif