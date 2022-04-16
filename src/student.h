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
#include "course.h"

class Activity;
class course;

class Student {

private:
    int activityIDs[32];
    string name;

public:
    string getName();

    void setName(string name);

    void addActivity();

    void addCourse(course * c[], int & size, course newc);

    char * searchCourse(course * c[], int size, string name);
};

#endif