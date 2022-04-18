#include "course.h"

course::course(
    string name,
    course_time * time, 
    string address, 
    string * documents,
    string current,
    string * homeWork,
    string QQGroup,
    Time extime,
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
    time = NULL;
    address = "";
    documents = NULL;
    current = "";
    homeWork = NULL;
    QQGroup = "";
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
course_time * course::getTime(){return time;}
void course::setTime(course_time * time){this->time = time;}
string course::getAddress(){return address;}
void course::setAddress(string address){this->address = address;}
string* course::getDocuments(){return documents;}
void course::setDocuments(string * documents){this->documents = documents;}
string course::getCurrent(){return current;}
void course::setCurrent(string current){this->current = current;}
string * course::getHomeWork(){return this->homeWork;}
void course::setHomeWork(string * homeWork){this->homeWork = homeWork;}
void setHomeWork(string * homeWork);
Time course::getExtime(){return extime;}
void course::setExtime(Time extime){this->extime = extime;}
string course::getExaddress(){return exaddress;}
void course::setExaddress(string exaddress){this->exaddress = exaddress;}
string course::getQQGroup(){return QQGroup;}
void course::setQQGroup(string QQGroup){this->QQGroup = QQGroup;}
hw_con * course::getFinish(){return finish_con;}
void course::setFinish(hw_con * finish_con){this->finish_con = finish_con;}

/**
 * @brief 上传学生作业
 * 
 * @param road 
 * @return string 
 */
string course::uploadHomework(string road, string stuName, int no)
{
    finish_con[no].finish = true;
    finish_con[no].road = OurStr::getFilename(road);
    string cmd = "copy " + road + " ..\\documents\\users\\" + stuName + "\\" + name;
    system(cmd.c_str());
    return finish_con[no].road;
}