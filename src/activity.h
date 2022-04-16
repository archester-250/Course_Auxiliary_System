/**
 * @file activity.h
 * @author your name (you@domain.com)
 * @brief ��ɿ��������ܣ������趨���ӡ���ɾ��������Ϣ������Ƿ���ʱ���ص���
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
    Time endTime;//���ֹʱ��
    string address;
    int member;
    int studentIDs[32];//�漰����ѧ��
    bool clk = false;//���ӱ�ʶ��Todo
    string description;//���������
public:
    // Get �� Set ����
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