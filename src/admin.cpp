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
        clog << "��ȡѧ��" << stuname << "�γ�\n";
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
    cout << "������γ����ƣ�";
    newArray[getCourse_size() - 1].setName(Input<string>());
    cout << "������ÿ�ܿγ̴�����";
    newArray[getCourse_size() - 1].setTimeSize(Input<int>());
    course_time * newTime = new course_time[newArray[getCourse_size() - 1].getTimeSize()];
    for (int i = 0; i < newArray[getCourse_size() - 1].getTimeSize(); i++)
    {
        cout << "�������" << i + 1 << "�ογ����ܼ��ϿΣ�";
        newTime[i].week = Input<int>();
        cout << "�������" << i + 1 << "�ογ̵Ŀ�ʼʱ�䣺";
        newTime[i].starthour = Input<int>();
        cout << "�������" << i + 1 << "�ογ̵Ľ���ʱ�䣺";
        newTime[i].endhour = Input<int>();
    }
    newArray[getCourse_size() - 1].setTime(newTime, newArray[getCourse_size() - 1].getTimeSize());
    cout << "������γ̵ص㣺";
    newArray[getCourse_size() - 1].setAddress(Input<string>());
    cout << "�����뵱ǰ�γ̽��ȣ�";
    newArray[getCourse_size() - 1].setCurrent(Input<string>());
    string * newDocuments = NULL;
    newArray[getCourse_size() - 1].setDocuments(newDocuments, 0);
    cout << "������γ�QQȺ��";
    newArray[getCourse_size() - 1].setQQGroup(Input<string>());
    Time t;
    t.yr = 0; t.mn = 0; t.day = 0; t.hr = 0;
    newArray[getCourse_size() - 1].setExtime(t);
    newArray[getCourse_size() - 1].setExaddress("null");
    newArray[getCourse_size() - 1].setHomeWork(newDocuments, 0);
    string stuname;
    //����ѧ������
    do
    {
        cout << "�������Ͽ�ѧ������,����0����:";
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
            cout << "û���ҵ���ѧ��!" << endl;
        }
    }while(stuname == "" && stuname != "0");
    cout << "��ӳɹ���" << endl;
    delete[] newTime;
    delete[] newDocuments;
    setCourses(newArray);
    delete[] newArray;
}

/**
 * @brief �ϴ��γ�����
 * 
 * @param road �ϴ�·��
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