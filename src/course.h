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
#include <iostream>

class course
{
private:
    /* data */
    char * name;
    int time;
    char * address;
    char ** documents;
    char * current;
    char ** finished;
    char ** unfinished;
    int extime;
    char * exaddress;//-ex前缀：考试相关信息
public:
    course(){};
    course(         char * name,
                    int time,
                    char * address, 
                    char ** documents,
                    char * current,
                    char ** finished,
                    char ** unfinished,
                    int extime,
                    char * exaddress);
    ~course();
    char * getName();
    void setName(char * name);
    int getTime();
    void setTime(int time);
    char * getAddress();
    void setAddress(char * address);
    char ** getDocuments();
    void setDocuments(char ** documents);
    char * getCurrent();
    void setCurrent(char * current);
    char ** getFinished();
    void setFinished(char ** finished);
    char ** getUnfinished();
    void setUnfinished(char ** unfinished);
    int getExtime();
    void setExtime(int extime);
    char * getExaddress();
    void setExaddress(char * exaddress);
    void operator=(course& c);
};


#endif