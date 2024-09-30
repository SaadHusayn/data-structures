#ifndef SLL_H
#define SLL_H

#include <iostream>
using namespace std;

class Node
{
public:
    int val;
    Node *next;

    Node(int _val,Node* _next):val(_val), next(_next){}
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

    void deleteNode(Node *node)
    {
        if (head == nullptr || node == nullptr)
            return;

        if (head == node)
        {
            head = head->next;
            delete node;
            return;
        }

        Node *prev = head;
        while (prev->next != nullptr && prev->next != node)
        {
            prev = prev->next;
        }

        if (prev->next == nullptr)
            return;

        prev->next = node->next;
        delete node;
    }
void updateNode(int valToFind, int newValToReplace)
{
    Node *curr = head;
    while (curr != nullptr)
    {
        if (curr->val == valToFind)
        {
            curr->val = newValToReplace;
            return;
        }
        curr = curr->next;
    }
}

static void printNode(Node *n){
    if(n==nullptr){
        cout<<endl;
        return;
    }

    cout<<n->val<<" ";
    printNode(n->next);
}

};

#endif