#include<iostream>
#include "SLL.h"
using namespace std;

int main(){
    Node *n = new Node(20);
    SLL *List = new SLL(n);

    List->head->next = new Node(1);
    List->head->next->next = new Node(2);
    List->head->next->next->next = new Node(5);
    List->head->next->next->next->next = new Node(10);


    List->printList();

    List->append(25);

    List->printList();
}