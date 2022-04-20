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
#include <cstring>
#include <iostream>
#include <fstream>
#include "utils.h"

struct course_time
{
    int week;//周几
    int starthour;//开始时间
    int endhour;//结束时间
};

struct hw_con
{
    bool finish;
    string road = "null";
};

using namespace std;


class course
{
private:
    /* data */
    string name;
    course_time * time;
    int t_size;
    string address;
    string * documents;//课程资料
    int doc_size;
    string current;
    string * homeWork;
    int hw_size;
    string QQGroup;
    Time extime;
    string exaddress;//-ex前缀：考试相关信息
    hw_con * finish_con;
    int finish_size;
public:
    course();
    course(         string name,
                    course_time * time,
                    int t_size,
                    string address,
                    string * documents,
                    int doc_count,
                    string current,
                    string * homeWork,
                    int hw_size,
                    string QQGroup,
                    Time extime,
                    string exaddress);
    ~course(){
        if(time != NULL)
        {
            delete [] time;
            time = NULL;
            t_size = 0;
        }
        if(documents != NULL)
        {
            delete [] documents;
            documents = NULL;
            doc_size = 0;
        }
        if(homeWork != NULL)
        {
            delete [] homeWork;
            homeWork = NULL;
            hw_size = 0;
        }
        if(finish_con != NULL)
        {
            delete [] finish_con;
            finish_con = NULL;
            finish_size = 0;
        }
    }
    string getName();
    void setName(string name);
    course_time * getTime();
    void setTime(course_time * time, int size);
    int getTimeSize();
    void setTimeSize(int size);
    string getAddress();
    void setAddress(string address);
    string * getDocuments();
    void setDocuments(string * documents, int size);
    int getDocumentsSize();
    void setDocumentsSize(int size);
    string getCurrent();
    void setCurrent(string current);
    string * getHomeWork();
    void setHomeWork(string * homeWork, int size);
    int getHomeWorkSize();
    void setHomeWorkSize(int size);
    Time getExtime();
    void setExtime(Time extime);
    string getExaddress();
    void setExaddress(string exaddress);
    string getQQGroup();
    void setQQGroup(string QQGroup);
    hw_con * getFinish();
    void setFinish(hw_con * finish_con, int size);
    int getFinishSize();
    void setFinishSize(int size);
    void operator=(course& c);
    
    string uploadHomework(string road, string stuName, int no);
};


#endif