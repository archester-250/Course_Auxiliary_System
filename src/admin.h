/**
 * @file admin.h
 * @author your name (you@domain.com)
 * @brief 完成管理员类，在该类下定义管理员的一系列操作
 * @version 0.1
 * @date 2022-03-17
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef ADMIN_H_
#define ADMIN_H_

#include "student.h"
#include "input.h"
#include "prepocess.h"



class admin
{
private:
    string name;
    int course_size;
    course * courses;
    Student * students;
    int student_size;
    /* data */
public:
    admin();
    admin(string name);
    ~admin();
    int getCourse_size();
    void setCourse_size(int course_size);
    course * getCourses();
    void setCourses(course * courses);
    void addCourse();
    void addHomework(string Course_name, string Homework);//todo
    string uploadDocument(string road, string name);
    void showMenu();
};


#endif