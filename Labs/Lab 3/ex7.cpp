#include <iostream>
#include "CDLL.h"

void extractAndAppend(CircularDoublyLinkedList& list) {
    if (!list.head || !list.head->next) return;

    Node* current = list.head->next;
    Node* extractedHead = nullptr;
    Node* extractedTail = nullptr;

    while (current) {
        Node* nextNode = current->next;
        if (current->prev) current->prev->next = current->next;
        if (current->next) current->next->prev = current->prev;

        current->next = extractedHead;
        if (extractedHead) extractedHead->prev = current;
        extractedHead = current;

        if (!extractedTail) extractedTail = current;
        current = nextNode ? nextNode->next : nullptr;
    }

    if (extractedHead) {
        list.tail->next = extractedHead;
        extractedHead->prev = list.tail;
        list.tail = extractedTail;
        list.tail->next = list.head;
        list.head->prev = list.tail;
    }
}

int main() {
    CircularDoublyLinkedList list;
    int n, value;
    
    std::cout << "Enter the number of elements in the list: ";
    std::cin >> n;
    std::cout << "Enter the elements of the list: ";
    
    for (int i = 0; i < n; ++i) {
        std::cin >> value;
        list.insertEnd(value);
    }

    std::cout << "Initial Linked List: ";
    list.printList();

    extractAndAppend(list);

    std::cout << "Modified Linked List: ";
    list.printList();

    return 0;
}
