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
    int course_size;

public:
    Student(string name);

    ~Student()
    {
        for(int i = 0; i < course_size; i++)
        {
            courses[i].~course();
        }
        delete[] courses;
    }

    string getName();

    void setName(string name);

    int getCourseSize();

    course * getCourses();

    void setCourses(course * courses, int c_count);

    void addActivity();

    course searchCourse(course c[], int size, string name);

    void showMenu();//��ʾѧ�������˵�

    int showCourseMenu();//��ʾ�γ̲����˵�

    int showActivityMenu();//��ʾ������˵�

};

#endif