#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
#include <stdexcept>

// Queue class definition
template <typename T>
class Queue {
private:
    struct Node {
        T data;
        Node* next;

        // Constructor to initialize a node
        Node(T value) : data(value), next(nullptr) {}
    };

    Node* front; // Pointer to the front of the queue
    Node* rear;  // Pointer to the rear of the queue
    int size;    // Number of elements in the queue

public:
    // Constructor
    Queue() : front(nullptr), rear(nullptr), size(0) {}

    // Destructor
    ~Queue() {
        clear();
    }

    // Function to check if the queue is empty
    bool isEmpty() const {
        return size == 0;
    }

    // Function to get the size of the queue
    int getSize() const {
        return size;
    }

    // Function to add an element to the rear of the queue (enqueue)
    void enqueue(T value) {
        Node* newNode = new Node(value);
        if (isEmpty()) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
        size++;
    }

    // Function to remove an element from the front of the queue (dequeue)
    T dequeue() {
        if (isEmpty()) {
            throw std::underflow_error("Queue is empty. Cannot dequeue.");
        }

        Node* temp = front;
        T value = front->data;
        front = front->next;
        delete temp;
        size--;

        if (isEmpty()) {
            rear = nullptr;
        }

        return value;
    }

    // Function to get the front element without removing it (peek)
    T peek() const {
        if (isEmpty()) {
            throw std::underflow_error("Queue is empty. Cannot peek.");
        }
        return front->data;
    }

    // Function to display all elements in the queue
    void display() const {
        if (isEmpty()) {
            std::cout << "Queue is empty.\n";
            return;
        }

        Node* current = front;
        while (current != nullptr) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << "\n";
    }

    // Function to clear the queue
    void clear() {
        while (!isEmpty()) {
            dequeue();
        }
    }
};

#endif // QUEUE_H