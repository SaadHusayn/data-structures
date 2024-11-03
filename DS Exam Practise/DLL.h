#ifndef DLL_H

#define DLL_H

#include<iostream>

class Node{
    public:
    int val;
    Node *next;
    Node *prev;

    Node(){next = nullptr; prev=nullptr;}
    Node(int _val):val(_val){next = nullptr;prev=nullptr;}


};

class DLL{
    public:
    Node *head;

    DLL(){
        head = nullptr;
    }

    DLL(Node *n):head(n){}

    void appendNode(int _val){
        Node *n = new Node(_val);
        if(head == nullptr){
            head = n;
        }
        else{
            Node *curr = head;
            for(;curr->next != nullptr;curr=curr->next);
            curr->next = n;
            n->prev = curr;
        }
    }

    void prependNode(int _val){
        Node *n = new Node(_val);
        if(head == nullptr){
            head = n;
        }
        else{
            head->prev  = n;
            n->next = head;
            head =  n;
        }
    }

    void insertAt(int _val, int idx){
        if(head == nullptr && idx == 0) head = new Node(_val);

        if(idx == 0) prependNode(_val);
        else{
            Node *curr = head;

            for(auto i=0;i<idx && curr!=nullptr;i++, curr=curr->next);

            //if the position is last or ahead of last then we will append the node to the last of the list
            if(curr == nullptr) appendNode(_val);
            else{
                //place the new node to that position behind the actual positioned node
                Node *n = new Node(_val);
                n->next = curr;
                n->prev = curr->prev;
                curr->prev->next = n;
                curr->prev = n;

            }

        }

    }

    void deleteNode(int _val){
        if(head == nullptr) return;

        //check if it is the first node
        if(head->val == _val){
            auto tmp = head;
            head = head->next;
            delete tmp ;
        }

        //else find it 
        auto curr = head;
        for(; curr!= nullptr && curr->val!=_val;curr=curr->next){
        }

        if(curr == nullptr) return;

        if(curr->val == _val){
            //if its the last node of the list
            if(curr->next == nullptr){
                curr->prev->next = nullptr;
                delete curr;
            }else{
                curr->prev->next = curr->next;
                curr->next->prev = curr->prev;
                delete curr;
            }
        }


    }

    void display(Node *n){
        if(n == nullptr){
            std::cout<<std::endl;
            return;
        }

        std::cout<<n->val<<" ";
        display(n->next);
    }


    
};

#endif