#include "course.h"

course::course(
    string name,
    int time, 
    string address, 
    string * documents,
    string current,
    string * homeWork,
    string QQGroup,
    int extime,
    string exaddress)
{
    this->name = name;
    this->time = time;
    this->address = address;
    this->current = current;
    this->documents = documents;
    this->exaddress = exaddress;
    this->extime = extime;
    this->homeWork = homeWork;
    this->QQGroup = QQGroup;
}

course::course()
{
    name = "";
    time = 0;
    address = "";
    documents = NULL;
    current = "";
    homeWork = NULL;
    QQGroup = "";
    extime = 0;
    exaddress = "";
}

void course::operator=(course& c)
{
    address = c.getAddress();
    name = c.getName();
    time = c.getTime();
    documents = c.getDocuments();
    current = c.getCurrent();
    homeWork = c.getHomeWork();
    extime = c.getExtime();
    exaddress = c.getExaddress();
    QQGroup = c.getQQGroup();
}

string course::getName(){return name;}
void course::setName(string name){this->name = name;}
int course::getTime(){return time;}
void course::setTime(int time){this->time = time;}
string course::getAddress(){return address;}
void course::setAddress(string address){this->address = address;}
string* course::getDocuments(){return documents;}
void course::setDocuments(string * documents){this->documents = documents;}
string course::getCurrent(){return current;}
void course::setCurrent(string current){this->current = current;}
string * course::getHomeWork(){return this->homeWork;}
void course::setHomeWork(string * homeWork){this->homeWork = homeWork;}
void setHomeWork(string * homeWork);
int course::getExtime(){return extime;}
void course::setExtime(int extime){this->extime = extime;}
string course::getExaddress(){return exaddress;}
void course::setExaddress(string exaddress){this->exaddress = exaddress;}
string course::getQQGroup(){return QQGroup;}
void course::setQQGroup(string QQGroup){this->QQGroup = QQGroup;}

/**
 * @brief 上传学生作业
 * 
 * @param road 
 * @return string 
 */
string course::uploadHomework(string road, string stuName)
{
    string cmd = "copy " + road + " ..\\documents\\users\\" + stuName + "\\" + name;
    system(cmd.c_str());
    return " ..\\documents\\users\\" + stuName + "\\" + name + "\\doc";
}