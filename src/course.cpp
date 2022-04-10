#include "course.h"

course::course(
    string stuName,
    string name,
    int time, 
    string address, 
    string * documents,
    string current,
    string * finished,
    string * unfinished,
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
    this->finished = finished;
    this->unfinished = unfinished;
}

course::~course()
{
}

void course::operator=(course& c)
{
    address = c.getAddress();
    name = c.getName();
    time = c.getTime();
    documents = c.getDocuments();
    current = c.getCurrent();
    finished = c.getFinished();
    unfinished = c.getUnfinished();
    extime = c.getExtime();
    exaddress = c.getExaddress();
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
string* course::getFinished(){return finished;}
void course::setFinished(string* finished){this->finished = finished;}
string* course::getUnfinished(){return unfinished;}
void course::setUnfinished(string* unfinished){this->unfinished = unfinished;}
int course::getExtime(){return extime;}
void course::setExtime(int extime){this->extime = extime;}
string course::getExaddress(){return exaddress;}
void course::setExaddress(string exaddress){this->exaddress = exaddress;}

void course::uploadFile(string road)
{
    string cmd = "copy " + road + " ..\\documents\\users\\" + stuName + "\\" + name;
    system(cmd.c_str());
}