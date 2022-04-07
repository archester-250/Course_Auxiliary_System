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



class Activity {
private:
    Time startTime;
    Time endTime;//���ֹʱ��
    char *address;
    int studentIDs[32];//�漰����ѧ��
    bool clk;//���ӱ�ʶ��Todo
    char description[128];//���������

public:
    // Get �� Set ����
    const Time &getStartTime() const;

    void setStartTime(const Time &startTime);

    const Time &getEndTime() const;

    void setEndTime(const Time &endTime);

    char *getAddress() const;

    void setAddress(char *address);

    const int *getStudentIDs() const;

    bool isClk() const;

    void setClk(bool clk);

    const char *getDescription() const;

    void setDescription(char* description);
    // ��ϵ�з���
    char* toString();

};


#endif