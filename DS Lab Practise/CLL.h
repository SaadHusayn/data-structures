#ifndef CLL_H

#define CLL_H

#include <iostream>

class Node
{
public:
    int val;
    Node *next;

    Node() { next = nullptr; }
    Node(int _val) : val(_val) { next = nullptr; }
};

class CLL
{
public:
    Node *head;
    Node *tail;

    CLL()
    {
        head = nullptr;
        tail = nullptr;
    }

    void insertAtEnd(int _val)
    {
        Node *n = new Node(_val);

        if (head == nullptr)
        {
            head = n;
            tail = n;
            tail->next = head;
        }
        else
        {
            tail->next = n;
            tail = tail->next;
            tail->next = head;
        }
    }

    void insertAtFront(int _val)
    {
        Node *n = new Node(_val);

        if (head == nullptr)
        {
            head = n;
            tail = n;
            tail->next = head;
        }
        else
        {
            tail->next = n;
            n->next = head;
            head = n;
        }
    }

    void display()
    {
        if(head == nullptr) return;
        if (head == tail) // only one node exist in the list
        {
            std::cout << head->val << std::endl;
        }
        else
        {
            for (auto i = head; i != tail; i = i->next)
            {
                std::cout << i->val << " ";
            }
            std::cout << tail->val<< std::endl;
        }
    }
};

#endif