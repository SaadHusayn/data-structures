#ifndef TICKET_RESOLUTION_LOG_H
#define TICKET_RESOLUTION_LOG_H

#include "Ticket.h"
#include "Stack.h"
#include "Queue.h"
#include <iostream>

class TicketResolutionLog {
    Stack<Ticket> resolutionLog;  // Stack to keep track of closed tickets
    Queue<Ticket> pendingQueue;   // Queue to handle pending tickets

public:
    // Add ticket to pending queue
    void enqueueTicket(const Ticket &ticket) {
        pendingQueue.enqueue(ticket);
    }

    // Assign ticket (remove from pending queue)
    Ticket dequeueTicket() {
        return pendingQueue.dequeue();
    }

    // Add resolved ticket to the resolution log stack
    void pushResolutionLog(const Ticket &ticket) {
        resolutionLog.push(ticket);
    }

    // View pending tickets in FIFO order
    void viewPendingQueue() {
        std::cout << "Pending Tickets (FIFO Order):" << std::endl;
        if (pendingQueue.isEmpty()) {
            std::cout << "No pending tickets.\n";
            return;
        }

        // Display pending tickets
        Queue<Ticket> tempQueue;  // Temporary queue to hold elements during display
        while (!pendingQueue.isEmpty()) {
            Ticket ticket = pendingQueue.dequeue();
            std::cout << "Ticket ID: " << ticket.getTicketID()
                      << ", Customer: " << ticket.getCustomerName()
                      << ", Priority: " << ticket.getPriority() << std::endl;
            tempQueue.enqueue(ticket);  // Save ticket back to temp queue
        }

        // Restore elements back to the original queue
        while (!tempQueue.isEmpty()) {
            pendingQueue.enqueue(tempQueue.dequeue());
        }
    }

    // View recent ticket resolution logs in LIFO order
    void viewResolutionLog() {
        std::cout << "Recent Ticket Resolutions (LIFO Order):" << std::endl;
        if (resolutionLog.isEmpty()) {
            std::cout << "No ticket resolutions available.\n";
            return;
        }

        // Display resolved tickets
        Stack<Ticket> tempStack;  // Temporary stack to hold elements during display
        while (!resolutionLog.isEmpty()) {
            Ticket ticket = resolutionLog.pop();
            std::cout << "Ticket ID: " << ticket.getTicketID()
                      << ", Closed at: " << ticket.getCloseTime() << std::endl;
            tempStack.push(ticket);  // Save ticket back to temp stack
        }

        // Restore elements back to the original stack
        while (!tempStack.isEmpty()) {
            resolutionLog.push(tempStack.pop());
        }
    }
};

#endif
