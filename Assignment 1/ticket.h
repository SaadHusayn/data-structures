#ifndef TICKET_H
#define TICKET_H

#include <iostream>
#include "Timestamp.h"

class Ticket {
    static int next_id;  // Static variable to keep track of the next available ID
    int ticket_id;
    std::string customer_name;
    int priority;  // 1 = High, 2 = Medium, 3 = Low
    std::string ticket_description;
    TimeStamp creation_time, close_time;
    bool isOpen;

public:
    // Default constructor
    Ticket() : ticket_id(next_id++), isOpen(true) {}

    // Parameterized constructor to initialize all attributes
    Ticket(const std::string &name, int prio, const std::string &description)
        : ticket_id(next_id++), customer_name(name), priority(prio), ticket_description(description), isOpen(true) {}

    // Getters
    int getTicketID() const { return ticket_id; }
    std::string getCustomerName() const { return customer_name; }
    int getPriority() const { return priority; }
    std::string getDescription() const { return ticket_description; }
    TimeStamp getCreationTime() const { return creation_time; }
    TimeStamp getCloseTime() const { return close_time; }
    bool getStatus() const { return isOpen; }

    // Setters
    void setPriority(int prio) { priority = prio; }
    void setDescription(const std::string &description) { ticket_description = description; }

    // Close the ticket and set close time
    void closeTicket() {
        isOpen = false;
        close_time.update();  // Set the close time to the current time
    }

    // Overload << operator for displaying ticket details
    friend std::ostream &operator<<(std::ostream &out, const Ticket &ticket) {
        out << "Ticket ID: " << ticket.ticket_id << "\n"
            << "Customer Name: " << ticket.customer_name << "\n"
            << "Priority: " << ticket.priority << "\n"
            << "Description: " << ticket.ticket_description << "\n"
            << "Creation Time: " << ticket.creation_time << "\n"
            << "Status: " << (ticket.isOpen ? "Open" : "Closed") << "\n";
        if (!ticket.isOpen) {
            out << "Close Time: " << ticket.close_time << "\n";
        }
        return out;
    }
};

// Initialize the static variable outside the class
int Ticket::next_id = 1;

#endif
