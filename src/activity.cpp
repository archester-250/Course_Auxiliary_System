#include "activity.h"
#include "hashMap.h"
#include <iostream>
#include <cstring>

using namespace std;

extern HashMap<int, Clock> clocks;
extern Student student;

bool time_conflict(Time time){
        return false;
}

const Time &Activity::getStartTime() const {
    return startTime;
}

void Activity::setStartTime(const Time &startTime) {
    if(!time_conflict(startTime))
    {
        Activity::startTime = startTime;
    }   
    else
        cout << "时间冲突，请重输入\n";
}

const Time &Activity::getEndTime() const {
    int time;
    return endTime;
}

void Activity::setEndTime(const Time &endTime) {
    if(!time_conflict(endTime))
    {
        Activity::endTime = endTime;
    }
    else
        cout << "时间冲突，请重输入\n";
}

const int *Activity::getStudentIDs() const {
    return studentIDs;
}

bool Activity::isClk() const {
    return clk;
}

void Activity::setClk(bool clk) {
    Activity::clk = clk;
}


const string &Activity::getDescription() const {
    return description;
}

void Activity::setDescription(const string &description) {
    Activity::description = description;
}

const string &Activity::getAddress() const {
    return address;
}

void Activity::setAddress(const string &address) {
    Activity::address = address;
}

string Activity::toString() {
    return "from " + startTime.toString() + " to " + endTime.toString() + ": "\
            "In " + address + ":" + description;
}


Activity::Activity() {}

string Activity::storeStr() {
    return to_string(startTime.timeStamp()) + " " + to_string(endTime.timeStamp()) + " " + address + " " + description;
}
