#ifndef TIMESTAMP_H
#define TIMESTAMP_H

#include<ctime>
#include<iostream>

class TimeStamp{
    time_t timestamp;
    struct tm datetime;

    public:
    TimeStamp(){
        timestamp = time(0);
        datetime = *localtime(&timestamp);
    }

    void update(){
        timestamp = time(0);
        datetime = *localtime(&timestamp);
    }

    bool operator<(const TimeStamp &other) const {
        return timestamp < other.timestamp; // Compare timestamps
    }


    friend std::ostream& operator<<(std::ostream& out, const TimeStamp& obj);


};

std::ostream& operator<<(std::ostream& out, const TimeStamp& obj){
    out<<ctime(&(obj.timestamp));
}

#endif