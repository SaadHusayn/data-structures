#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* previous;

    Node() {
        data = 0;
        next = NULL;
        previous = NULL;
    }

    Node(int d) {
        data = d;
        next = NULL;
        previous = NULL;
    }
};

class DoublyLinkedList {
public:
    Node* head;

    DoublyLinkedList() {
        head = NULL;
    }

    DoublyLinkedList(Node* n) {
        head = n;
    }

    void appendNode(Node* n) {
        if (head == NULL) {
            head = n;
            cout << "Node appended as head node." << endl;
        } else {
            Node* temp = head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = n;
            n->previous = temp;
            cout << "Node appended." << endl;
        }
    }

    void prependNode(Node* n) {
        if (head == NULL) {
            head = n;
            cout << "Node prepended as head node." << endl;
        } else {
            n->next = head;
            head->previous = n;
            head = n;
            cout << "Node prepended." << endl;
        }
    }

    void insertNodeAfter(Node* prevNode, Node* n) {
        if (prevNode == NULL) {
            cout << "The given previous node cannot be NULL." << endl;
            return;
        }

        n->next = prevNode->next;
        prevNode->next = n;
        n->previous = prevNode;

        if (n->next != NULL) {
            n->next->previous = n;
        }

        cout << "Node inserted." << endl;
    }

    void deleteNode(Node* n) {
        if (head == NULL || n == NULL) {
            cout << "The node cannot be deleted." << endl;
            return;
        }

        if (head == n) {
            head = n->next;
        }

        if (n->next != NULL) {
            n->next->previous = n->previous;
        }

        if (n->previous != NULL) {
            n->previous->next = n->next;
        }

        delete n;
        cout << "Node deleted." << endl;
    }

    void printList() {
        if (head == NULL) {
            cout << "The list is empty." << endl;
        } else {
            Node* temp = head;
            while (temp != NULL) {
                cout << temp->data << " <=> ";
                temp = temp->next;
            }
            cout << "NULL" << endl;
        }
    }
};

int main() {
    DoublyLinkedList dll;
    Node* node1 = new Node(10);
    Node* node2 = new Node(20);
    Node* node3 = new Node(30);
    Node* node4 = new Node(40);

    dll.appendNode(node1);
    dll.appendNode(node2);
    dll.printList();

    dll.prependNode(node3);
    dll.printList();

    dll.insertNodeAfter(node2, node4);
    dll.printList();

    dll.deleteNode(node3);
    dll.printList();

    return 0;
}
