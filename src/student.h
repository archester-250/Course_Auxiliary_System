/**
 * @file student.h
 * @author your name (you@domain.com)
 * @brief 完成学生类，在学生类下定义学生的一系列操作
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