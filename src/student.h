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
#include "course.h"

struct hwork//��ͥ��ҵ
{
    /* data */
    string road = NULL;//�ϴ�����ҵ����
    bool finish;
};

class Activity;
class course;

class Student {

private:
    int activityIDs[32];
    string name;
    course * courses;

public:
    Student(string name);

    ~Student(){delete courses;}

    string getName();

    void setName(string name);

    course * getCourses();

    void setCourses(course * courses);

    void addActivity();

    course searchCourse(course c[], int size, string name);

};

#endif