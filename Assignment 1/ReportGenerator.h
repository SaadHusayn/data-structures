#ifndef REPORT_GENERATOR_H
#define REPORT_GENERATOR_H

#include <iostream>
#include <string>
#include "Ticket.h"               // Include your Ticket class
#include "Agent.h"                // Include your Agent class
#include "TicketResolutionLog.h"  // Include your ticket resolution log class
#include "Queue.h"                // Include your Queue class
#include "Stack.h"                // Include your Stack class
#include "Configuration.h"        // Include configuration header

class ReportGenerator {
    TicketResolutionLog *log;  
    Configuration config; // Configuration instance

public:
    ReportGenerator(TicketResolutionLog *log_ref, const std::string &configFile)
        : log(log_ref), config(configFile) {}

    void listOpenTickets(Ticket tickets[], int ticketCount) {
        // Search for open tickets
        Ticket *openTickets = new Ticket[ticketCount];
        int openCount = 0;

        for (int i = 0; i < ticketCount; i++) {
            if (tickets[i].getStatus()) {
                openTickets[openCount++] = tickets[i];
            }
        }

        // Sort open tickets based on configuration
        if (openCount < config.getThreshold()) {
            bubbleSort(openTickets, openCount);
        } else {
            if (config.getSortingAlgorithm() == "merge") {
                mergeSort(openTickets, openCount);
            } else {
                quickSort(openTickets, openCount);
            }
        }

        // Display open tickets
        std::cout << "List of Open Tickets:\n";
        for (int i = 0; i < openCount; i++) {
            std::cout << "Ticket ID: " << openTickets[i].getTicketID() 
                      << ", Customer Name: " << openTickets[i].getCustomerName()
                      << ", Priority: " << openTickets[i].getPriority()
                      << ", Creation Time: " << openTickets[i].getCreationTime()
                      << ", Status: " << (openTickets[i].getStatus() ? "Open" : "Closed") 
                      << std::endl;
        }

        delete[] openTickets;
    }

    void displayAgentTicketLoad(Agent agents[], int agentCount) {
        // Sort agents based on the number of assigned tickets
        // For simplicity, assume that Agent has a method to get assigned tickets count
        // Sort logic can be implemented here

        // Display agent ticket load
        std::cout << "Agent Ticket Load:\n";
        for (int i = 0; i < agentCount; i++) {
            std::cout << "Agent ID: " << agents[i].getAgentID() 
                      << ", Name: " << agents[i].getName() 
                      << ", Assigned Tickets: " << agents[i].getTicketCount() 
                      << std::endl;
        }
    }

    void showTicketResolutionHistory() {
        // Display the most recent ticket resolutions using the resolution log (stack)
        std::cout << "Ticket Resolution History:\n";

        // Assuming the log has a method to get recent resolutions
        Ticket resolvedTicket;
        while (!log->isEmpty()) {
            resolvedTicket = log->pop(); // Assuming pop returns the resolved ticket
            std::cout << "Resolved Ticket ID: " << resolvedTicket.getTicketID() 
                      << ", Close Time: " << resolvedTicket.close_time << std::endl;
        }
    }

private:
    void bubbleSort(Ticket arr[], int size) {
        for (int i = 0; i < size - 1; i++) {
            for (int j = 0; j < size - i - 1; j++) {
                if (arr[j].priority > arr[j + 1].priority) {
                    std::swap(arr[j], arr[j + 1]);
                }
            }
        }
    }

    void mergeSort(Ticket arr[], int size) {
        // Implement merge sort
    }

    void quickSort(Ticket arr[], int size) {
        // Implement quick sort
    }
};

#endif
