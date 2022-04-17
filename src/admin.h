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

#include "course.h"
#include "student.h"

#define SYS_TIME_BIAS_TIMES 3000
//时间倍率，现在是3秒一小时

class admin
{
private:
    /* data */
public:
    admin();
    ~admin();
    void addCourse(course * c[], int & size);
    void addHomework(string Course_name, string Homework);//todo
    string uploadDocument(string road, string name);
};

admin::admin(/* args */)
{
}

admin::~admin()
{
}


#endif