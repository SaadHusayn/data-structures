#include<iostream>
#include"SLL.h"
using namespace std;

int main(){
    Node *first = new Node(4);
    Node *second = new Node(1);
    Node *third = new Node(5);
    Node *fourth = new Node(7);
    Node *fifth = new Node(2);

    SLL *List = new SLL(first);
    List->head->next = second;
    List->head->next->next = third;
    List->head->next->next->next = fourth;
    List->head->next->next->next->next = fifth;

    List->printList();

    List->addAfterNode(second, 3);

    List->printList();
}