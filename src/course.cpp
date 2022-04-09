#include "course.h"

course::course(
    char * name,
    int time, 
    char * address, 
    char ** documents,
    char * current,
    char ** finished,
    char ** unfinished,
    int extime,
    char * exaddress)
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

char * course::getName(){return name;}
void course::setName(char * name){this->name = name;}
int course::getTime(){return time;}
void course::setTime(int time){this->time = time;}
char * course::getAddress(){return address;}
void course::setAddress(char * address){this->address = address;}
char ** course::getDocuments(){return documents;}
void course::setDocuments(char ** documents){this->documents = documents;}
char * course::getCurrent(){return current;}
void course::setCurrent(char * current){this->current = current;}
char ** course::getFinished(){return finished;}
void course::setFinished(char ** finished){this->finished = finished;}
char ** course::getUnfinished(){return unfinished;}
void course::setUnfinished(char ** unfinished){this->unfinished = unfinished;}
int course::getExtime(){return extime;}
void course::setExtime(int extime){this->extime = extime;}
char * course::getExaddress(){return exaddress;}
void course::setExaddress(char * exaddress){this->exaddress = exaddress;}

