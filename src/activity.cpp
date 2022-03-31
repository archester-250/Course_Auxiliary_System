#include "activity.h"
#include <iostream>
using namespace std;

bool time_conflict(Time time){
    //TODO
    return true;
}

const Time &Activity::getStartTime() const {
    return startTime;
}

void Activity::setStartTime(const Time &startTime) {
    if(!time_conflict(startTime))
    {
        Activity::startTime = startTime;
        clog << "[INFO]设置时间开始活动\n";
    }   
    else
        cout << "时间冲突，请重输入\n";
}

const Time &Activity::getEndTime() const {
    return endTime;
}

void Activity::setEndTime(const Time &endTime) {
    if(!time_conflict(endTime))
    {
        Activity::endTime = endTime;
        clog << "[INFO]设置时间结束活动\n";
    }
    else
        cout << "时间冲突，请重输入\n";
}

char *Activity::getAddress() const {
    return address;
}

void Activity::setAddress(char *address) {
    Activity::address = address;
}

const Student *Activity::getStudents() const {
    return students;
}

bool Activity::isClk() const {
    return clk;
}

void Activity::setClk(bool clk) {
    Activity::clk = clk;
}

const char *Activity::getDescription() const {
    return description;
}
