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

#include "utils.h"
#include "activity.h"
#include "course.h"
#include "hashMap.h"

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
    string name;
    course * courses;
    HashMap<int, Activity>* activities = new HashMap<int, Activity>(32);
    HashMap<int, Clock>* clocks = new HashMap<int, Clock>(32);
    int course_size;

public:
    Student();
    Student(string name);

    HashMap<int, Activity> *getActivities() const;

    HashMap<int, Clock> *getClocks() const;

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

    course searchCourse(course c[], int size, string name);//�����γ̹���

    void showMenu();//��ʾѧ�������˵�

    void showTodayCourse();//��ʾ����Ŀγ�

    void courseTable();

    void saveStuInfo();//�����������ļ�

    int showCourseMenu();//��ʾ�γ̲����˵�

    int showActivityMenu();//��ʾ������˵�

    void InitStudent();
};

#endif