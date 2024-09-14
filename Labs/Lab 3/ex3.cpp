#include<iostream>
#include"CLL.h"

using namespace std;

int main(){
    Node *first = new Node{1, nullptr};
    Node *second = new Node{2, nullptr};
    Node *third = new Node{3, nullptr};

    CLL List(second);
    List.insertAtFront(first);
    List.insertAtEnd(second);
    List.insertAtEnd(third);
    List.deleteNode(second);
    List.display();
}