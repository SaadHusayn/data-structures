#include <iostream>
#include "CDLL.h"

int main() {
    CircularDoublyLinkedList list;
    list.insertEnd(1);
    list.insertEnd(2);
    list.insertEnd(3);
    list.printList();

    list.insertBegin(0);
    list.printList();

    list.insertAtPosition(5, 2);
    list.printList();

    list.deleteNode(2);
    list.printList();

    return 0;
}
