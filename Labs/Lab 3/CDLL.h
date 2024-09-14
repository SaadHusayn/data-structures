#ifndef CDLL_H
#define CDLL_H

#include<iostream>

class Node {
public:
    int data;
    Node* next;
    Node* prev;
    Node(int val) : data(val), next(nullptr), prev(nullptr) {}
};

class CircularDoublyLinkedList {

public:
    Node* head;
    Node* tail;

    CircularDoublyLinkedList() : head(nullptr), tail(nullptr) {}

    void insertEnd(int val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = newNode;
            tail = newNode;
            head->next = head;
            head->prev = head;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            newNode->next = head;
            head->prev = newNode;
            tail = newNode;
        }
    }

    void insertBegin(int val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = newNode;
            tail = newNode;
            head->next = head;
            head->prev = head;
        } else {
            newNode->next = head;
            newNode->prev = tail;
            head->prev = newNode;
            tail->next = newNode;
            head = newNode;
        }
    }

    void insertAtPosition(int val, int pos) {
        if (pos <= 0) {
            insertBegin(val);
            return;
        }
        Node* newNode = new Node(val);
        Node* temp = head;
        for (int i = 0; i < pos - 1 && temp->next != head; i++) {
            temp = temp->next;
        }
        newNode->next = temp->next;
        newNode->prev = temp;
        temp->next->prev = newNode;
        temp->next = newNode;
        if (temp == tail) {
            tail = newNode;
        }
    }

    void deleteNode(int val) {
        if (!head) return;
        Node* curr = head;
        do {
            if (curr->data == val) {
                if (curr == head && curr == tail) {
                    delete curr;
                    head = nullptr;
                    tail = nullptr;
                    return;
                }
                curr->prev->next = curr->next;
                curr->next->prev = curr->prev;
                if (curr == head) head = curr->next;
                if (curr == tail) tail = curr->prev;
                delete curr;
                return;
            }
            curr = curr->next;
        } while (curr != head);
    }

    void printList() {
        if (!head) return;
        Node* temp = head;
        do {
            std::cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
        std::cout << std::endl;
    }
};

#endif
