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
    Node(int _val, Node *_next):val(_val), next(_next){}
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

    CLL(Node *n){
        head = n;
        tail = n;
    }

    void insertAtEnd(Node *n)
    {

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

    void insertAtFront(Node *n)
    {

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

    void insertAtPos(int pos, Node *n){
        if(pos == 1){
            insertAtFront(n);
        }else{
            

            //traverse just before the inserting position
            auto curr = head;
            int currPos = 1;
            for(;currPos!=(pos-1)  && curr->next!=head;curr=curr->next, currPos++);

            //if position is out of the size of linkedlist then we cannot insert
            if(currPos != (pos-1)) return;

            //now insert the new node at the given position
            n->next = curr->next;
            curr->next = n;
        }
    }

    void deleteNode(Node *n){
        //if its the only node of linked list
        if(head==n && tail==n){
            delete n;
            head = 0;
            tail = 0;
            return;
        }

        //if its head
        if(head == n){
            head = head->next;
            delete n;
            return;
        }

        auto prev = head;
        auto curr = head->next;

        while(curr->next!=head){
            if(curr==n){
                curr = curr->next;
                prev->next = curr;
                delete n;
                return;
            }else{
                prev = curr;
                curr = curr->next;
            }
        }

        //if the tail has to be deleted
        if(curr == n){
            prev->next = head;
            tail = prev;
            delete n;
            return;
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