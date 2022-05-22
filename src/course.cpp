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
        this->finish_con[i].road = finish_con[i].road;
        this->finish_con[i].MD5 = finish_con[i].MD5;
    }
    this->finish_size = size;
}
int course::getFinishSize(){return finish_size;}
void course::setFinishSize(int size){this->finish_size = size;}

/**
 * @brief 上传学生作业
 * 
 * @param road 
 * @return string 
 */
void course::uploadHomework(string road, string stuName, int no)
{
    string input;
    unsigned char decrypt[16];
    ifstream in(road);
    char c;
    while(in.get(c))
    {
        input += c;
    }
    in.close();
    MD5 md5;
    md5.MD5Update(md5.getContext(), (unsigned char *)input.c_str(), input.length());
    md5.MD5Final(md5.getContext(), decrypt);
    md5.~MD5();
    string md5str = "";
    for(int i = 0; i < 16; i++)
    {
        md5str += (char)decrypt[i];
    }
    if(OurStr::StrCmp(md5str, finish_con[no].MD5))
    {
        cout << "已经上传过该作业，请勿重复上传！" << endl;
        return;
    }
    else
    {
        if(OurStr::getSuffix(road) == "txt")
        {
            string outRoad = "..\\documents\\users\\" + stuName + "\\" + name + "\\" + to_string(no) + "\\" +  OurStr::getFilename(road).substr(0, OurStr::getFilename(road).rfind('.'));
            compression c;
            if(c.Code(road, outRoad))
            {
                cout << "压缩上传成功" << endl;
                finish_con[no].finish = true;
                finish_con[no].road = OurStr::getFilename(road);
                finish_con[no].MD5 = md5str;
            }
            else
            {
                cout << "压缩上传失败" << endl;
            }
        }
        else
        {
            cout << "检测到不是txt文件,取消压缩" << endl;
            string cmd = "copy " + road + " ..\\documents\\users\\" + stuName + "\\" + name + "\\" + to_string(no);
            system(cmd.c_str());
        }
    }
    
}

void course::viewDocument(string stuName)
{
    cout << "请选择要查看的类型:" << endl;
    printf("1.课程资料\t2.课程作业\n");
    int type = input::getOperatorNum();
    if(type == 1)
    {
        cout << "请选择要查看的资料:" << endl;
        for(int i = 0; i < doc_size; i++)
        {
            cout << i + 1 << "." << documents[i] << endl;
        }
        int no = input::getOperatorNum() - 1;
        string inroad = "..\\documents\\public\\" + name + "\\" + documents[no];
        string outroad = "..\\documents\\public\\" + name + "\\" + documents[no];
        compression c;
        if(c.Decode(inroad, outroad))
        {
            cout << "解压成功,正在打开文件..." << endl;
            system(("start ..\\documents\\public\\" + name + "\\" + documents[no]).c_str());
            cout << "浏览结束,自动删除解压文件" << endl;
            system(("del ..\\documents\\public\\" + name + "\\" + documents[no]).c_str());
        }
        else
        {
            cout << "解压失败" << endl;
        }
    }
    else if(type == 2)
    {
        cout << "请选择要查看的作业:" << endl;
        for(int i = 0; i < hw_size; i++)
        {
            cout << i + 1 << "." << homeWork[i] << endl;
        }
        int no = input::getOperatorNum() - 1;
        string inroad = "..\\documents\\users\\" + stuName + "\\" + name + "\\" + to_string(no) + '\\' + homeWork[no];
        string outroad = "..\\documents\\users\\" + stuName + "\\" + name + "\\" + to_string(no) + '\\' + homeWork[no];
        compression c;
        if(c.Decode(inroad, outroad))
        {
            cout << "解压成功,正在打开文件..." << endl;
            system(("start ..\\documents\\users\\" + stuName + "\\" + name + "\\" + to_string(no) + '\\' + homeWork[no]).c_str());
            cout << "浏览结束,自动删除解压文件" << endl;
            system(("del ..\\documents\\users\\" + stuName + "\\" + name + "\\" + to_string(no) + '\\' + homeWork[no]).c_str());
        }
        else
        {
            cout << "解压失败" << endl;
        }
    }
}