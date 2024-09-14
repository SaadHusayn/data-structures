#include <iostream>
#include "CDLL.h"

void swapNodes(CircularDoublyLinkedList& list, int index1, int index2) {
    if (index1 == index2) return;

    Node* first = list.head;
    Node* second = list.head;
    Node* temp;

    for (int i = 0; i < index1 && first->next != list.head; i++) {
        first = first->next;
    }

    for (int i = 0; i < index2 && second->next != list.head; i++) {
        second = second->next;
    }

    if (!first || !second) return;

    if (first->prev) first->prev->next = second;
    if (second->prev) second->prev->next = first;

    if (first->next) first->next->prev = second;
    if (second->next) second->next->prev = first;

    temp = first->prev;
    first->prev = second->prev;
    second->prev = temp;

    temp = first->next;
    first->next = second->next;
    second->next = temp;

    if (list.head == first) list.head = second;
    else if (list.head == second) list.head = first;

    if (list.tail == first) list.tail = second;
    else if (list.tail == second) list.tail = first;
}

int main() {
    CircularDoublyLinkedList list;
    list.insertEnd(1);
    list.insertEnd(7);
    list.insertEnd(4);
    list.insertEnd(2);
    list.insertEnd(6);
    list.insertEnd(4);
    list.insertEnd(5);
    list.insertEnd(3);
    list.insertEnd(9);
    list.insertEnd(8);

    std::cout << "Initial Linked List: ";
    list.printList();

    swapNodes(list, 3, 7);

    std::cout << "After Swapping: ";
    list.printList();

    return 0;
}
