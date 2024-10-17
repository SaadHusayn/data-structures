#ifndef DCLL_H
#define DCLL_H

#include <iostream>

// Node structure for a doubly circular linked list
template <typename T>
struct Node {
    T data;
    Node* next;
    Node* prev;

    // Constructor to initialize a node
    Node(T value) : data(value), next(nullptr), prev(nullptr) {}
};

// DCLL class definition
template <typename T>
class DCLL {
private:
    Node<T>* head;

public:
    // Constructor
    DCLL() : head(nullptr) {}

    // Destructor
    ~DCLL() {
        clear();
    }

    // Function to check if the list is empty
    bool isEmpty() const {
        return head == nullptr;
    }

    // Function to insert a node at the end of the list
    void insertAtEnd(T value) {
        Node<T>* newNode = new Node<T>(value);
        if (isEmpty()) {
            head = newNode;
            head->next = head;
            head->prev = head;
        } else {
            Node<T>* tail = head->prev;
            tail->next = newNode;
            newNode->prev = tail;
            newNode->next = head;
            head->prev = newNode;
        }
    }

    // Function to insert a node at the beginning of the list
    void insertAtBeginning(T value) {
        insertAtEnd(value);
        head = head->prev;
    }

    // Function to delete a node with a given value
    void deleteNode(T value) {
        if (isEmpty()) {
            std::cout << "List is empty. Cannot delete.\n";
            return;
        }

        Node<T>* current = head;
        do {
            if (current->data == value) {
                if (current == head && current->next == head) {
                    // Only one node in the list
                    delete current;
                    head = nullptr;
                    return;
                } else if (current == head) {
                    // Deleting the head node
                    Node<T>* tail = head->prev;
                    head = head->next;
                    tail->next = head;
                    head->prev = tail;
                } else {
                    // Deleting a middle or last node
                    current->prev->next = current->next;
                    current->next->prev = current->prev;
                }

                delete current;
                return;
            }
            current = current->next;
        } while (current != head);

        std::cout << "Node with value " << value << " not found.\n";
    }

    // Function to display the list
    void display() const {
        if (isEmpty()) {
            std::cout << "List is empty.\n";
            return;
        }

        Node<T>* current = head;
        do {
            std::cout << current->data << " ";
            current = current->next;
        } while (current != head);
        std::cout << "\n";
    }

    // Function to clear the list
    void clear() {
        if (isEmpty()) {
            return;
        }

        Node<T>* current = head;
        do {
            Node<T>* nextNode = current->next;
            delete current;
            current = nextNode;
        } while (current != head);

        head = nullptr;
    }
};

#endif // DCLL_H
