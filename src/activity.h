/**
 * @file activity.h
 * @author your name (you@domain.com)
 * @brief 完成课外活动管理功能，包括设定闹钟、增删查改相关信息、检测是否有时间重叠等
 * @version 0.1
 * @date 2022-03-17
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef ACTIVITY_H
#define ACTIVITY_H

#include "student.h"
#include <iostream>
#include "utils.h"
#include <string>

class Time;

class Activity {
private:
    Time startTime;
    Time endTime;//活动起止时间
    string address;
    int member;
    int studentIDs[32];//涉及到的学生
    bool clk = false;//闹钟标识，Todo
    string description;//活动内容描述
public:
    // Get 和 Set 方法
    const Time &getStartTime() const;

    void setStartTime(const Time &startTime);

    const Time &getEndTime() const;

    void setEndTime(const Time &endTime);

    const string &getAddress() const;

    void setAddress(const string &address);

    const int *getStudentIDs() const;

    bool isClk() const;

    void setClk(bool clk);

    const string &getDescription() const;

    void setDescription(const string &description);

    string toString();

};


#endif