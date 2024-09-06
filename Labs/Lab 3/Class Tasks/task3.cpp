#include<iostream>
#include "SLL.h"
using namespace std;

int main(){
    Node *n = new Node(20);
    SLL *List = new SLL(n);

    List->head->next = new Node(10);
    List->head->next->next = new Node(15);
    List->head->next->next->next = new Node(17);


    List->printList();

    List->addAtFront(5);

    List->printList();
}