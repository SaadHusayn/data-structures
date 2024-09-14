#include<iostream>
#include"SLL.h"
using namespace std;



void reverseListRecursion(Node *&head, Node *curr, Node *prev){
    if(curr==nullptr){
        head = prev;
        return;
    };

    auto forward = curr->next;
    reverseListRecursion(head, forward, curr);
    curr->next = prev;
    
}


Node* reverseList(Node *head){ 
     if((head == nullptr) || (head->next == nullptr))return head;
        
        auto chotaHead = reverseList(head->next);
        
        head->next->next = head;
        head->next = nullptr;
        
        return chotaHead;
}

int main(){
    Node *n = new Node{1, new Node{2, new Node{3, new Node{4, nullptr}}}};
    SLL::printNode(n);
    n = reverseList(n);
    SLL::printNode(n);

}