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

struct hwork//家庭作业
{
    /* data */
    string road = NULL;//上传的作业名称
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

    void showMenu();//显示学生操作菜单

    int showCourseMenu();//显示课程操作菜单

    int showActivityMenu();//显示活动操作菜单

};

#endif