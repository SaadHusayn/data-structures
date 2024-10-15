#ifndef TICKET_H
#define TICKET_H

#include<iostream>
#include"timestamp.h"

class Ticket{
    int ticket_id;
    std::string customer_name;
    int priority;
    std::string ticket_description;
    TimeStamp creation_time, close_time;
    bool isOpen;

    public:
    Ticket(){
        
    }


};

#endif