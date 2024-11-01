#include <iostream>
#include <string>
#include <ctime>
#include <fstream>
using namespace std;
string getCurrentTime() {
    time_t now = time(0);
    return ctime(&now);
}

class Ticket {
public:
    int ticketID;
    string customerName;
    int priority; // 1 = High, 2 = Medium, 3 = Low
    string description;
    string creationTime;
    string closeTime;
    string status;
    Ticket(int id, string name, int pri, string desc)
        : ticketID(id), customerName(name), priority(pri), description(desc), status("Open") {
        creationTime = getCurrentTime();
    }
    void closeTicket() {
        closeTime = getCurrentTime();
        status = "Closed:";
    }
};
struct TicketNode {
    Ticket ticket;
    TicketNode* next;
    TicketNode(Ticket t) : ticket(t), next(nullptr) {}
};

class TicketList {
private:
    TicketNode* head;
public:
    TicketList() : head(nullptr) {}
    void addTicket(Ticket t) {
        TicketNode* newNode = new TicketNode(t);
        newNode->next = head;
        head = newNode;
        cout << "Ticket added:" << t.ticketID << endl;
    }
    void removeTicket(int ticketID) {
        TicketNode* temp = head;
        TicketNode* prev = nullptr;
        while (temp != nullptr && temp->ticket.ticketID != ticketID) {
            prev = temp;
            temp = temp->next;
        }
        if (temp == nullptr) {
            cout << "Ticket not found:\n";
            return;
        }
        if (prev == nullptr)
            head = temp->next;
        else
            prev->next = temp->next;
        delete temp;
        cout << "Ticket removed:" << ticketID << endl;
    }
    Ticket* searchTicket(int ticketID) {
        TicketNode* temp = head;
        while (temp != nullptr) {
            if (temp->ticket.ticketID == ticketID)
                return &temp->ticket;
            temp = temp->next;
        }
        return nullptr;
    }
    void displayTickets() {
        TicketNode* temp = head;
        while (temp != nullptr) {
            cout << "Ticket ID:" << temp->ticket.ticketID
                << ", Customer:" << temp->ticket.customerName
                << ", Priority:" << temp->ticket.priority
                << ", Status:" << temp->ticket.status << endl;
            temp = temp->next;
        }
    }
    void insertionSort() {
        if (head == nullptr) return;
        TicketNode* sorted = nullptr;
        TicketNode* current = head;
        while (current != nullptr) {
            TicketNode* next = current->next;
            if (sorted == nullptr || sorted->ticket.priority >= current->ticket.priority) {
                current->next = sorted;
                sorted = current;
            }
            else {
                TicketNode* temp = sorted;
                while (temp->next != nullptr && temp->next->ticket.priority < current->ticket.priority) {
                    temp = temp->next;
                }
                current->next = temp->next;
                temp->next = current;
            }
            current = next;
        }
        head = sorted;
    }
    void selectionSort() {
        if (head == nullptr) return;
        TicketNode* current = head;
        while (current != nullptr) {
            TicketNode* minNode = current;
            TicketNode* nextNode = current->next;
            while (nextNode != nullptr) {
                if (nextNode->ticket.priority < minNode->ticket.priority) {
                    minNode = nextNode;
                }
                nextNode = nextNode->next;
            }
            if (minNode != current) {
                swap(current->ticket, minNode->ticket);
            }
            current = current->next;
        }
    }
    void merge(TicketNode** headRef) {
        TicketNode* head = *headRef;
        TicketNode* a;
        TicketNode* b;
        if (head == nullptr || head->next == nullptr) {
            return;
        }
        split(head, &a, &b);
        merge(&a);
        merge(&b);

        *headRef = sortedMerge(a, b);
    }
    TicketNode* sortedMerge(TicketNode* a, TicketNode* b) {
        TicketNode* result = nullptr;
        if (a == nullptr) return b;
        if (b == nullptr) return a;
        if (a->ticket.priority <= b->ticket.priority) {
            result = a;
            result->next = sortedMerge(a->next, b);
        }
        else {
            result = b;
            result->next = sortedMerge(a, b->next);
        }
        return result;
    }
    void split(TicketNode* source, TicketNode** frontRef, TicketNode** backRef) {
        TicketNode* fast;
        TicketNode* slow;
        slow = source;
        fast = source->next;
        while (fast != nullptr) {
            fast = fast->next;
            if (fast != nullptr) {
                slow = slow->next;
                fast = fast->next;
            }
        }
        *frontRef = source;
        *backRef = slow->next;
        slow->next = nullptr;
    }
    void mergeSort() {
        merge(&head);
    }
    void quickSort(TicketNode** headRef) {
        TicketNode* head = *headRef;
        if (head == nullptr || head->next == nullptr) return;
        TicketNode* pivot = head;
        TicketNode* tail = head;
        while (tail->next != nullptr) tail = tail->next;
        TicketNode* left = nullptr;
        TicketNode* right = nullptr;
        TicketNode* current = head->next;
        while (current != nullptr) {
            if (current->ticket.priority < pivot->ticket.priority) {
                if (left == nullptr) {
                    left = current;
                }
                else {
                    TicketNode* tmp = left;
                    while (tmp->next != nullptr) tmp = tmp->next;
                    tmp->next = current;
                }
            }
            else {
                if (right == nullptr) {
                    right = current;
                }
                else {
                    TicketNode* tmp = right;
                    while (tmp->next != nullptr) tmp = tmp->next;
                    tmp->next = current;
                }
            }
            current = current->next;
        }
        if (left != nullptr) {
            quickSort(&left);
            *headRef = left;
            while (left->next != nullptr) left = left->next;
            left->next = pivot;
        }
        else {
            *headRef = pivot;
        }
        pivot->next = nullptr;
        quickSort(&right);
        if (right != nullptr) {
            pivot->next = right;
        }
    }
    void sortTickets(int algorithm) {
        switch (algorithm) {
        case 1:
            insertionSort();
            cout << "Sorted using Insertion Sort:\n";
            break;
        case 2:
            selectionSort();
            cout << "Sorted using Selection Sort:\n";
            break;
        case 3:
            mergeSort();
            cout << "Sorted using Merge Sort:\n";
            break;
        case 4:
            quickSort(&head);
            cout << "Sorted using Quick Sort:\n";
            break;
        default:
            cout << "Invalid algorithm choice:\n";
            break;
        }
    }
};

class Agent {
public:
    int agentID;
    string name;
    bool available;
    int* assignedTickets;
    int maxTickets;
    int ticketCount;
    Agent(int id, string n, int max) : agentID(id), name(n), available(true), maxTickets(max), ticketCount(0) {
        assignedTickets = new int[maxTickets];
    }
    ~Agent() {
        delete[] assignedTickets;
    }
    void assignTicket(int ticketID) {
        if (ticketCount < maxTickets) {
            assignedTickets[ticketCount++] = ticketID;
            if (ticketCount >= maxTickets) available = false;
            cout << "Ticket " << ticketID << " assigned to Agent " << name << endl;
        }
        else {
            cout << "Agent " << name << " is at full capacity\n";
        }
    }
    void displayAssignedTickets() {
        cout << "Agent " << name << " assigned tickets: ";
        for (int i = 0; i < ticketCount; ++i) {
            cout << assignedTickets[i] << " ";
        }
        cout << endl;
    }
    int getTicketCount() {
        return ticketCount;
    }
};

struct QueueNode {
    Ticket ticket;
    QueueNode* next;
    QueueNode(Ticket t) : ticket(t), next(nullptr) {}
};
class TicketQueue {
private:
    QueueNode* front;
    QueueNode* rear;
public:
    TicketQueue() : front(nullptr), rear(nullptr) {}
    void enqueue(Ticket t) {
        QueueNode* newNode = new QueueNode(t);
        if (rear) {
            rear->next = newNode;
        }
        else {
            front = newNode;
        }
        rear = newNode;
        cout << "Ticket queued: " << t.ticketID << endl;
    }
    Ticket dequeue() {
        if (front == nullptr) {
            cout << "Queue is empty\n";
            return Ticket(-1, "", 0, "");
        }
        QueueNode* temp = front;
        Ticket t = front->ticket;
        front = front->next;
        if (front == nullptr) rear = nullptr;
        delete temp;
        cout << "Ticket dequeued: " << t.ticketID << endl;
        return t;
    }
    bool isEmpty() {
        return front == nullptr;
    }
    void displayQueue() {
        QueueNode* temp = front;
        while (temp != nullptr) {
            cout << "Ticket ID: " << temp->ticket.ticketID << ", Customer: " << temp->ticket.customerName << endl;
            temp = temp->next;
        }
    }
};

struct StackNode {
    Ticket ticket;
    StackNode* next;
    StackNode(Ticket t) : ticket(t), next(nullptr) {}
};
class ResolutionStack {
private:
    StackNode* top;
public:
    ResolutionStack() : top(nullptr) {}
    void push(Ticket t) {
        StackNode* newNode = new StackNode(t);
        newNode->next = top;
        top = newNode;
        cout << "Ticket resolved: " << t.ticketID << endl;
    }
    Ticket pop() {
        if (top == nullptr) {
            cout << "Stack is empty\n";
            return Ticket(-1, "", 0, "");
        }
        StackNode* temp = top;
        Ticket t = top->ticket;
        top = top->next;
        delete temp;
        return t;
    }
    void displayRecentResolutions() {
        StackNode* temp = top;
        cout << "Recent Resolved Tickets:\n";
        while (temp != nullptr) {
            cout << "Ticket ID:" << temp->ticket.ticketID
                << ", Customer:" << temp->ticket.customerName
                << ", Status:" << temp->ticket.status << endl;
            temp = temp->next;
        }
    }
};

class Config {
public:
    int defaultSortAlgorithm;

    Config() {
        ifstream configFile("config.txt");
        if (configFile.is_open()) {
            configFile >> defaultSortAlgorithm;
            configFile.close();
        }
        else {
            defaultSortAlgorithm = 1; // Default to Insertion Sort
        }
    }
};
void testSystem() {
    TicketList ticketList;
    TicketQueue pendingQueue;
    ResolutionStack resolutionStack;
    Config config;
    int maxTickets;
    cout << "Enter maximum number of tickets an agent can handle:";
    cin >> maxTickets;
    Agent agent(1, "DSA", maxTickets);
    int choice;
    do {
        cout << "\n1. Add Ticket\n2. Remove Ticket\n3. Assign Ticket\n4. Close Ticket\n5. Display Tickets\n6. Sort Tickets by Default Algorithm\n7. Display Pending Queue\n8. Display Recent Resolutions\n9. Exit\nChoose an option:";
        cin >> choice;

        if (choice == 1) {
            int id, pri;
            string name, desc;
            cout << "Enter Ticket ID, Customer Name, Priority (1-High, 2-Med, 3-Low), and Description:";
            cin >> id >> name >> pri;
            cin.ignore();
            getline(cin, desc);
            Ticket newTicket(id, name, pri, desc);
            ticketList.addTicket(newTicket);
            pendingQueue.enqueue(newTicket);
        }
        else if (choice == 2) {
            int id;
            cout << "Enter Ticket ID to remove:";
            cin >> id;
            ticketList.removeTicket(id);
        }
        else if (choice == 3) {
            if (!pendingQueue.isEmpty()) {
                Ticket t = pendingQueue.dequeue();
                agent.assignTicket(t.ticketID);
            }
            else {
                cout << "No pending tickets:\n";
            }
        }
        else if (choice == 4) {
            int id;
            cout << "Enter Ticket ID to close:";
            cin >> id;
            Ticket* t = ticketList.searchTicket(id);
            if (t) {
                t->closeTicket();
                resolutionStack.push(*t);
                pendingQueue.dequeue();
            }
        }
        else if (choice == 5) {
            ticketList.displayTickets();
        }
        else if (choice == 6) {
            ticketList.sortTickets(config.defaultSortAlgorithm);
            ticketList.displayTickets();
        }
        else if (choice == 7) {
            pendingQueue.displayQueue();
        }
        else if (choice == 8) {
            resolutionStack.displayRecentResolutions();
        }
    } while (choice != 9);
}
int main() {
    testSystem();
    return 0;
}