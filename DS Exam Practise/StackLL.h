#ifndef STACK_H
#define STACK_H

template<typename T>
class Node {
public:
    T data;
    Node* prev;
    Node* next;

    Node(T value) : data(value), prev(nullptr), next(nullptr) {}
};

template<typename T>
class Stack {
private:
    Node<T>* head;
    int stackSize;

public:
    Stack() : head(nullptr), stackSize(0) {}

    ~Stack() {
        while (!isEmpty()) {
            pop();
        }
    }

    void push(T value) {
        Node<T>* newNode = new Node<T>(value);
        newNode->next = head;
        if (head != nullptr) {
            head->prev = newNode;
        }
        head = newNode;
        stackSize++;
    }

    T pop() {
        if (isEmpty()) {
            exit(1);
        }

        Node<T>* temp = head;
        T poppedValue = temp->data;
        head = head->next;
        if (head != nullptr) {
            head->prev = nullptr;
        }
        delete temp;
        stackSize--;
        return poppedValue;
    }

    T peek() {
        if (isEmpty()) {
            exit(1);
        }
        return head->data;
    }

    bool isEmpty() const {
        return head == nullptr;
    }

    int size() const {
        return stackSize;
    }
};

#endif