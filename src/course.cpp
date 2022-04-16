#include "course.h"

course::course(
    string stuName,
    string name,
    int time, 
    string address, 
    string * documents,
    string current,
    hwork * homeWork,
    string QQGroup,
    int extime,
    string exaddress)
{
    this->stuName = stuName;
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

course::~course()
{
    stuName = "";
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
    stuName = c.getStuName();
    address = c.getAddress();
    name = c.getName();
    time = c.getTime();
    documents = c.getDocuments();
    current = c.getCurrent();
    homeWork = c.getHomeWork();
    extime = c.getExtime();
    exaddress = c.getExaddress();

}

string course::getStuName(){return stuName;}
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
hwork * course::getHomeWork(){return this->homeWork;}
void course::setHomeWork(hwork * homeWork){this->homeWork = homeWork;}
void setHomeWork(hwork homeWork);
int course::getExtime(){return extime;}
void course::setExtime(int extime){this->extime = extime;}
string course::getExaddress(){return exaddress;}
void course::setExaddress(string exaddress){this->exaddress = exaddress;}

/**
 * @brief 上传课程资料
 * 
 * @param road 上传路径
 */
string course::uploadDocument(string road)
{
    string cmd = "copy " + road + " ..\\documents\\public\\" + name;
    system(cmd.c_str());
    return " ..\\documents\\users\\" + stuName + "\\" + name + "\\doc";
}
/**
 * @brief 上传学生作业
 * 
 * @param road 
 * @return string 
 */
string course::uploadHomework(string road)
{
    string cmd = "copy " + road + " ..\\documents\\users\\" + stuName + "\\" + name;
    system(cmd.c_str());
    return " ..\\documents\\users\\" + stuName + "\\" + name + "\\doc";
}
bool addHomework(hwork ** h, string homework)
{
    hwork temp;
    printf("请输入文件路径:(绝对路径噢)\n");
    cin>>temp.road;
    temp.homework = homework;
}