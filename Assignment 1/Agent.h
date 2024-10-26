#ifndef AGENT_H
#define AGENT_H

#include <iostream>

class Agent {
    static int next_id;  // Static variable to generate unique agent IDs
    int agent_id;
    std::string name;
    int *assignedTickets;  // Dynamic array to hold ticket IDs
    int ticketCount;       // Number of tickets currently assigned
    int capacity;          // Current capacity of the dynamic array
    bool isAvailable;

    void resize(int newCapacity) {
        int *newArray = new int[newCapacity];
        for (int i = 0; i < ticketCount; ++i) {
            newArray[i] = assignedTickets[i];
        }
        delete[] assignedTickets;
        assignedTickets = newArray;
        capacity = newCapacity;
    }

public:
    // Default constructor
    Agent() : agent_id(next_id++), assignedTickets(nullptr), ticketCount(0), capacity(0), isAvailable(true) {}

    // Parameterized constructor
    Agent(const std::string &agent_name)
        : agent_id(next_id++), name(agent_name), assignedTickets(new int[2]), ticketCount(0), capacity(2), isAvailable(true) {}

    // Destructor to free dynamic memory
    ~Agent() {
        delete[] assignedTickets;
    }

    // Getters
    int getAgentID() const { return agent_id; }
    std::string getName() const { return name; }
    bool getAvailability() const { return isAvailable; }
    int getTicketCount() const { return ticketCount; }

    // Assign a ticket to this agent
    void assignTicket(int ticket_id) {
        if (!isAvailable) return;

        if (ticketCount == capacity) {
            resize(capacity * 2);  // Double the capacity if array is full
        }

        assignedTickets[ticketCount++] = ticket_id;

        if (ticketCount >= 5) {
            isAvailable = false;  // Mark as unavailable if max capacity reached
        }
    }

    // Mark agent as available
    void markAvailable() {
        isAvailable = true;
    }

    // Close a ticket and remove it from assigned tickets
    void closeTicket(int ticket_id) {
        for (int i = 0; i < ticketCount; ++i) {
            if (assignedTickets[i] == ticket_id) {
                // Shift elements to remove the ticket ID
                for (int j = i; j < ticketCount - 1; ++j) {
                    assignedTickets[j] = assignedTickets[j + 1];
                }
                ticketCount--;

                if (ticketCount <= capacity / 4 && capacity > 2) {
                    resize(capacity / 2);  // Shrink capacity if usage is low
                }
                
                if (ticketCount < 5) {
                    isAvailable = true;  // Set as available if below capacity
                }
                return;
            }
        }
    }

    // Overloaded << operator for displaying agent details
    friend std::ostream &operator<<(std::ostream &out, const Agent &agent) {
        out << "Agent ID: " << agent.agent_id << "\n"
            << "Name: " << agent.name << "\n"
            << "Status: " << (agent.isAvailable ? "Available" : "Unavailable") << "\n"
            << "Assigned Tickets: ";
        for (int i = 0; i < agent.ticketCount; ++i) {
            out << agent.assignedTickets[i] << " ";
        }
        out << "\n";
        return out;
    }
};

// Initialize the static variable for unique agent IDs
int Agent::next_id = 1;

#endif
