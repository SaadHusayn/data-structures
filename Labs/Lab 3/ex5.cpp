#include <iostream>
#include "CDLL.h"

void concatenate(CircularDoublyLinkedList& L, CircularDoublyLinkedList& M) {
    if (!L.head) {
        L.head = M.head;
        L.tail = M.tail;
        return;
    }
    if (!M.head) return;

    L.tail->next = M.head;
    M.head->prev = L.tail;
    M.tail->next = L.head;
    L.head->prev = M.tail;
    L.tail = M.tail;
}


int main() {
    CircularDoublyLinkedList L;
    L.insertEnd(1);
    L.insertEnd(2);
    L.insertEnd(3);
    L.printList();

    CircularDoublyLinkedList M;
    M.insertEnd(4);
    M.insertEnd(5);
    M.insertEnd(6);
    M.printList();

    concatenate(L, M);
    L.printList();

    return 0;
}

