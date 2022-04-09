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

