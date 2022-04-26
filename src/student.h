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

#include "utils.h"
#include "activity.h"
#include "course.h"
#include "hashMap.h"

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

    course searchCourse(course c[], int size, string name);//搜索课程功能

    void showMenu();//显示学生操作菜单

    void showTodayCourse();//显示今天的课程

    void courseTable();

    void saveStuInfo();//保存数据至文件

    int showCourseMenu();//显示课程操作菜单

    int showActivityMenu();//显示活动操作菜单

    void InitStudent();
};

#endif