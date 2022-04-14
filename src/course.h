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
using namespace std;
struct hwork//家庭作业
{
    /* data */
    string homework;
    bool finish;
};

using namespace std;

class course
{
private:
    /* data */
    string stuName;
    string name;
    int time;
    string address;
    string * documents;
    string current;
    hwork * homeWork;
    string QQGroup;
    int extime;
    string exaddress;//-ex前缀：考试相关信息
public:
    course(){};
    course(         string stuName,
                    string name,
                    int time,
                    string address,
                    string * documents,
                    string current,
                    hwork * homeWork,
                    string QQGroup,
                    int extime,
                    string exaddress);
    ~course();
    string getStuName();
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
    hwork * getHomeWork();
    void setHomeWork(hwork * homeWork);
    int getExtime();
    void setExtime(int extime);
    string getExaddress();
    void setExaddress(string exaddress);
    void operator=(course& c);
    
    void uploadFile(string road);
};


#endif