/**
 * @file course.h
 * @author your name (you@domain.com)
 * @brief 课程管理功能，包括增删查改信息、上传更新压缩资料等功能
 * @version 0.1
 * @date 2022-03-17
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef COURSE_H
#define COURSE_H

#include <stdio.h>
#include <string>
#include <iostream>
#include <fstream>

using namespace std;


class course
{
private:
    /* data */
    string name = NULL;
    int time;
    string address;
    string * documents;//课程资料
    string current;
    string * homeWork;
    string QQGroup;
    int extime;
    string exaddress;//-ex前缀：考试相关信息
public:
    course();
    course(         string name,
                    int time,
                    string address,
                    string * documents,
                    string current,
                    string * homeWork,
                    string QQGroup,
                    int extime,
                    string exaddress);
    ~course(){};
    string getName();
    void setName(string name);
    int getTime();
    void setTime(int time);
    string getAddress();
    void setAddress(string address);
    string * getDocuments();
    void setDocuments(string * documents);
    string getCurrent();
    void setCurrent(string current);
    string * getHomeWork();
    void setHomeWork(string * homeWork);
    int getExtime();
    void setExtime(int extime);
    string getExaddress();
    void setExaddress(string exaddress);
    void operator=(course& c);
    
    string uploadHomework(string road, string stuName);
};


#endif