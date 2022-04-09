#include "course.h"

course::course(int time, 
    char * address, 
    char ** documents,
    char * current,
    char ** finished,
    char ** unfinished,
    int extime,
    char * exaddress)
{
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

