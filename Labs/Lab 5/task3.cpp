// Create a C++ program to search for a value in a singly linked list, using non-tail
// recursion?
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

bool search(Node *head, int num){
    if(head == nullptr) return false;

    bool answer = search(head->next, num);
    if(answer == true) return true;
    else{
        if(head->data == num) return true;
        return false;
    }
}

int main(){
    Node *head = new Node{1, new Node{2, new Node{3, new Node{4, nullptr}}}};

    if(search(head, 3)){
        cout<<"3 exist in this SLL";
    }else{
        cout<<"3 doesnt exist in this SLL";
    }
}