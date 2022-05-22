#include "admin.h"

Admin* admin;

Admin::Admin(/* args */)
{
    this->name = "null";
    this->course_size = 0;
    this->courses = NULL;
    this->student_size = 0;
    this->students = NULL;
}

Admin::~Admin()
{
    if(this->courses != NULL)
    {
        delete [] this->courses;
        this->courses = NULL;
        this->course_size = 0;
    }
    if(this->students != NULL)
    {
        delete [] this->students;
        this->students = NULL;
        this->student_size = 0;
    }
}

Admin::Admin(string name)
{
    this->name = name;
    int all_count;
    prepocess p;
    courses = p.coursesInitialize(all_count);
    this->course_size = all_count;
    ifstream in("../database/Administers.data");
    int student_count;
    in >> student_count;
    if (student_count)
        students = new Student[student_count];
    this->student_size = student_count;
    for(int i = 0; i < student_count; i++)
    {
        string stuname;
        in >> stuname;
        clog << "获取学生" << stuname << "课程\n";
        Student s(stuname);
        students[i].setName(stuname);
        students[i].setCourseSize(s.getCourseSize());
        students[i].setCourses(s.getCourses(), s.getCourseSize());
    }
    in.close();
}

int Admin::getCourse_size()
{
    return this->course_size;
}

void Admin::setCourse_size(int course_size)
{
    this->course_size = course_size;
}

course * Admin::getCourses()
{
    return this->courses;
}

void Admin::setCourses(course * courses)
{
    this->courses = new course[course_size];
    for (int i = 0; i < course_size; i++) {
        this->courses[i] = courses[i];
    }
}

void Admin::addCourse()
{
    setCourse_size(getCourse_size() + 1);
    //done
    course * newArray = new course[getCourse_size()];
    for (int i = 0; i < getCourse_size() - 1; i++)
    {
        newArray[i] = courses[i];
    }
    cout << "请输入课程名称：";
    newArray[getCourse_size() - 1].setName(Input<string>());
    cout << "请输入每周课程次数：";
    newArray[getCourse_size() - 1].setTimeSize(Input<int>());
    course_time * newTime = new course_time[newArray[getCourse_size() - 1].getTimeSize()];
    for (int i = 0; i < newArray[getCourse_size() - 1].getTimeSize(); i++)
    {
        cout << "请输入第" << i + 1 << "次课程在周几上课：";
        newTime[i].week = Input<int>();
        cout << "请输入第" << i + 1 << "次课程的开始时间：";
        newTime[i].starthour = Input<int>();
        cout << "请输入第" << i + 1 << "次课程的结束时间：";
        newTime[i].endhour = Input<int>();
    }
    newArray[getCourse_size() - 1].setTime(newTime, newArray[getCourse_size() - 1].getTimeSize());
    cout << "请输入课程地点：";
    newArray[getCourse_size() - 1].setAddress(Input<string>());
    cout << "请输入当前课程进度：";
    newArray[getCourse_size() - 1].setCurrent(Input<string>());
    string * newDocuments = NULL;
    newArray[getCourse_size() - 1].setDocuments(newDocuments, 0);
    cout << "请输入课程QQ群：";
    newArray[getCourse_size() - 1].setQQGroup(Input<string>());
    Time t;
    t.yr = 0; t.mn = 0; t.day = 0; t.hr = 0;
    newArray[getCourse_size() - 1].setExtime(t);
    newArray[getCourse_size() - 1].setExaddress("null");
    newArray[getCourse_size() - 1].setHomeWork(newDocuments, 0);
    string stuname;
    //输入学生名字
    do
    {
        cout << "请输入上课学生名字,输入0结束:";
        stuname = Input<string>();
        fstream in("../database/users.data");
        string name, temp;
        bool flag = false;
        while(in >> name >> temp)
        {
            if(!OurStr::StrCmp(stuname, name))
            {
                flag = true;
                break;
            }
        }
        if(flag)
        {
            string cmd = "mkdir ..\\documents\\users\\" + stuname + "\\" + newArray[getCourse_size() - 1].getName();
            system(cmd.c_str());
        }
        else
        {
            cout << "没有找到该学生!" << endl;
        }
    }while(stuname == "" && stuname != "0");
    cout << "添加成功！" << endl;
    delete[] newTime;
    delete[] newDocuments;
    setCourses(newArray);
    delete[] newArray;
}

/**
 * @brief 上传课程资料
 * 
 * @param road 上传路径
 */
string Admin::uploadDocument(string road, string name)
{
    string cmd = "copy " + road + " ..\\documents\\public\\" + name;
    system(cmd.c_str());
    return " ..\\documents\\public\\" + name;
}

void Admin::addHomework(string Course_name, string Homework)
{
    for(int i = 0; i < student_size; i++)
    {
        course c = students[i].searchCourse(courses, course_size, Course_name);
        if(c.getName() != "null")
        {
            c.setHomeWorkSize(c.getHomeWorkSize() + 1);
            string * newArray = new string[c.getHomeWorkSize()];
            for(int j = 0; j < c.getHomeWorkSize() - 1; j++)
            {
                newArray[j] = c.getHomeWork()[j];
            }
            newArray[c.getHomeWorkSize() - 1] = Homework;
            c.setHomeWork(newArray, c.getHomeWorkSize());
            delete[] newArray;
            string cmd = "mkdir ..\\documents\\users\\" + students[i].getName() + "\\" + Course_name + "\\" + to_string(c.getHomeWorkSize());
            system(cmd.c_str());
        }
    }
}

void Admin::showMenu()
{

}