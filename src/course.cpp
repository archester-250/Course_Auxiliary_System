#include "course.h"

course::course( string name,
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
                string exaddress)
{
    this->name = name;
    this->time = new course_time[t_size];//构造函数新建另一个对象，而非直接赋值
    this->t_size = t_size;
    for(int i = 0; i < t_size; i++)
    {
        this->time[i] = time[i];
    }
    this->address = address;
    this->current = current;
    this->documents = new string[doc_count];
    this->doc_size = doc_count;
    for(int i = 0; i < doc_count; i++)
    {
        this->documents[i] = documents[i];
    }
    this->exaddress = exaddress;
    this->extime = extime;
    this->homeWork = new string[hw_size];
    this->hw_size = hw_size;
    for(int i = 0; i < hw_size; i++)
    {
        this->homeWork[i] = homeWork[i];
    }
    this->QQGroup = QQGroup;
}

course::course()
{
    name = "null";
    time = NULL;
    address = "null";
    documents = NULL;
    current = "null";
    homeWork = NULL;
    QQGroup = "null";
    exaddress = "null";
    finish_con = NULL;
}

void course::operator=(course& c)
{
    address = c.getAddress();
    name = c.getName();
    if(time != NULL)
    {
        delete [] time;
        time = NULL;
        t_size = 0;
    }
    time = new course_time[c.getTimeSize()];
    t_size = c.getTimeSize();
    for(int i = 0; i < t_size; i++)
    {
        time[i] = c.getTime()[i];
    }
    if(documents != NULL)
    {
        delete [] documents;
        documents = NULL;
        doc_size = 0;
    }
    documents = new string[c.getDocumentsSize()];
    doc_size = c.getDocumentsSize();
    for(int i = 0; i < doc_size; i++)
    {
        this->documents[i] = c.getDocuments()[i];
    }
    current = c.getCurrent();
    if(homeWork != NULL)
    {
        delete [] homeWork;
        homeWork = NULL;
        hw_size = 0;
    }
    homeWork = new string[c.getHomeWorkSize()];
    hw_size = c.getHomeWorkSize();
    for(int i = 0; i < hw_size; i++)
    {
        this->homeWork[i] = c.getHomeWork()[i];
    }
    extime = c.getExtime();
    exaddress = c.getExaddress();
    QQGroup = c.getQQGroup();
}//使用了深拷贝（不拷贝作业完成情况）

string course::getName(){return name;}
void course::setName(string name){this->name = name;}
course_time * course::getTime(){return time;}
void course::setTime(course_time * time, int size){
    this->time = new course_time[size];
    for(int i = 0; i < size; i++)
    {
        this->time[i].endhour = time[i].endhour;
        this->time[i].starthour = time[i].starthour;
        this->time[i].week = time[i].week;
    }
}
int course::getTimeSize(){return t_size;}
void course::setTimeSize(int size){this->t_size = size;}
string course::getAddress(){return address;}
void course::setAddress(string address){this->address = address;}
string* course::getDocuments(){return documents;}
void course::setDocuments(string * documents, int size)
{
    this->documents = new string[size];
    for(int i = 0; i < size; i++)
        this->documents[i] = documents[i];
}
int course::getDocumentsSize(){return doc_size;}
void course::setDocumentsSize(int size){this->doc_size = size;}
string course::getCurrent(){return current;}
void course::setCurrent(string current){this->current = current;}
string * course::getHomeWork(){return this->homeWork;}
void course::setHomeWork(string * homeWork, int size)
{
    this->homeWork = new string[size];
    for(int i = 0; i < size; i++)
        this->homeWork[i] = homeWork[i];
}
int course::getHomeWorkSize(){return hw_size;}
void course::setHomeWorkSize(int size){this->hw_size = size;}
Time course::getExtime(){return extime;}
void course::setExtime(Time extime){this->extime = extime;}
string course::getExaddress(){return exaddress;}
void course::setExaddress(string exaddress){this->exaddress = exaddress;}
string course::getQQGroup(){return QQGroup;}
void course::setQQGroup(string QQGroup){this->QQGroup = QQGroup;}
hw_con * course::getFinish(){return finish_con;}
void course::setFinish(hw_con * finish_con, int size)
{
    this->finish_con = new hw_con[size];
    for(int i = 0; i < size; i++)
    {
        this->finish_con[i].finish = finish_con[i].finish;
        this->finish_con[i].road.resize(finish_con[i].road.size());
        for(int j = 0; j < finish_con[i].road.length(); j++)
        {
            this->finish_con[i].road[j] = finish_con[i].road[j];
        }
    }
}
int course::getFinishSize(){return finish_size;}
void course::setFinishSize(int size){this->finish_size = size;}

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