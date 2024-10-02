// Write a C++ function to find the length of a singly linked list using tail recursion?

#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node *next;

    public:
    Node(){data=0; next=0;}
    Node(int _data, Node* _next){data=_data; next=_next;}

};

int lengthOfSLL(Node *head){
    if(head==nullptr) return 0;
    if(head->next == nullptr) return 1;

    return 1 + lengthOfSLL(head->next);
}

int main(){
    Node *head = new Node{1, new Node{2, new Node{3, new Node{4, nullptr}}}};

    cout<<"The length of the SLL is "<<lengthOfSLL(head);
}