/**
 * @file student.h
 * @author your name (you@domain.com)
 * @brief ���ѧ���࣬��ѧ�����¶���ѧ����һϵ�в���
 * @version 0.1
 * @date 2022-03-17
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef STUDENT_H
#define STUDENT_H

#include "activity.h"
#include "utils.h"

class Activity;

class Student {

public:
    int id;
    int activityIDs[32];

    int getId() const;

    void setId(int id);

    void addActivity();
};

#endif