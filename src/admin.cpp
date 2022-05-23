#include "admin.h"

Admin * admin;

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
    ifstream in("../database/Administer.data");
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
    if(this->courses != NULL)
    {
        delete [] this->courses;
        this->courses = NULL;
    }
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
        in.close();
        if(flag)
        {
            string cmd = "mkdir ..\\documents\\users\\" + stuname + "\\" + newArray[getCourse_size() - 1].getName();
            system(cmd.c_str());
            for(int i = 0; i < student_size; i++)
            {
                if(!OurStr::StrCmp(students[i].getName(), stuname))
                {
                    students[i].setCourseSize(students[i].getCourseSize() + 1);
                    course * newCourse = new course[students[i].getCourseSize()];
                    for(int j = 0; j < students[i].getCourseSize() - 1; j++)
                    {
                        newCourse[j] = students[i].getCourses()[j];
                    }
                    newCourse[students[i].getCourseSize() - 1] = newArray[getCourse_size() - 1];
                    students[i].setCourses(newCourse, students[i].getCourseSize());
                    delete [] newCourse;
                }
            }
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
string Admin::uploadDocument()
{
    string road, course_name;
    cout << "������Ҫ�ϴ�������·��(�㼶Ŀ¼���ԡ�\\\\���ָ�)��";
    road = Input<string>();
    cout << "������γ����ƣ�";
    course_name = Input<string>();
    Student s;
    course c = s.searchCourse(courses, course_size, course_name);
    if(c.getName() == "null")
    {
        cout << "û���ҵ��ÿγ̣�" << endl;
        return "null";
    }
    for(int i = 0; i < c.getDocumentsSize(); i++)
    {
        if(OurStr::StrCmp(c.getDocuments()[i], OurStr::getFilename(road)))
        {
            cout << "�������Ѵ��ڣ�" << endl;
            return "null";
        }
    }
    if(OurStr::getSuffix(road) == "txt")
    {
        string outRoad = "..\\documents\\public\\" + course_name + "\\" + OurStr::getFilename(road).substr(0, OurStr::getFilename(road).length() - 4);
        compression com;
        cout << "����ѹ���ļ�..." << endl;
        if(com.Code(road, outRoad))
        {
            cout << "ѹ���ϴ��ɹ�" << endl;
        }
        else
        {
            cout << "ѹ���ϴ�ʧ��" << endl;
        }
    }
    else
    {
        cout << "��⵽����txt�ļ�,ȡ��ѹ��" << endl;
        string cmd = "copy " + road + " ..\\documents\\public\\" + course_name;
        system(cmd.c_str());
    }
    c.setDocumentsSize(c.getDocumentsSize() + 1);
    string * newDocuments = new string[c.getDocumentsSize()];
    for(int i = 0; i < c.getDocumentsSize() - 1; i++)
    {
        newDocuments[i] = c.getDocuments()[i];
    }
    newDocuments[c.getDocumentsSize() - 1] = OurStr::getFilename(road);
    c.setDocuments(newDocuments, c.getDocumentsSize());
    return OurStr::getFilename(road);
}

void Admin::addHomework()
{
    string Course_name,Homework;
    cout << "������γ����ƣ�";
    Course_name = Input<string>();
    Student s;
    course c = s.searchCourse(courses, course_size, Course_name);
    if(c.getName() == "null")
    {
        cout << "û���ҵ��ÿγ�!" << endl;
        return;
    }
    cout << "��������ҵ���ƣ�";
    Homework = Input<string>();
    bool flag = false;
    for(int j = 0; j < c.getHomeWorkSize(); j++)
    {
        if(!OurStr::StrCmp(Homework, c.getHomeWork()[j]))
        {
            flag = true;
            break;
        }
    }
    if(flag)
    {
        cout << "����ҵ�Ѵ���!" << endl;
        return;
    }
    for(int i = 0; i < student_size; i++)
    {
        course c = students[i].searchCourse(students[i].getCourses(), students[i].getCourseSize(), Course_name);
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
            c.setFinishSize(c.getFinishSize() + 1);
            hw_con * newArray2 = new hw_con[c.getFinishSize()];
            for(int j = 0; j < c.getFinishSize() - 1; j++)
            {
                newArray2[j] = c.getFinish()[j];
            }
            newArray2[c.getFinishSize() - 1].finish = false;
            c.setFinish(newArray2, c.getFinishSize());
            delete[] newArray2;
        }
    }
    cout << "��ӳɹ���" << endl;
}

void Admin::showMenu()
{
    updateTime();
    printf("��ӭ����Ա%s\n", name.c_str());
    printf("1.�鿴���пγ�\n");
    printf("2.�鿴����ѧ��\n");
    printf("3.��ӿγ�\n");
    printf("4.�����ҵ\n");
    printf("5.�鿴�γ�����\n");
    printf("6.�ϴ��γ�����\n");
    printf("0.�˳�����Աϵͳ\n");
    printf("����������ѡ��");
    int choice = input::getOperatorNum();
    while(choice)
    {
        switch(choice)
        {
            case 1:
                cout << "���пγ̣�" << endl;
                for(int i = 0; i < course_size; i++)
                {
                    printf("%s\t", courses[i].getName().c_str());
                }
                cout << endl;
                break;
            case 2:
                cout << "����ѧ����" << endl;
                for(int i = 0; i < student_size; i++)
                {
                    printf("%s\t", students[i].getName().c_str());
                }
                cout << endl;
                break;
            case 3:
                addCourse();
                break;
            case 4:
                addHomework();
                break;
            case 5:
                showDocument();
                break;
            case 6:
                uploadDocument();
                break;
            case 0:
                return;
            default:
                printf("����������������룡\n");
                break;
        }
        printf("��ӭ����Ա%s\n", name.c_str());
        printf("1.�鿴���пγ�\n");
        printf("2.�鿴����ѧ��\n");
        printf("3.��ӿγ�\n");
        printf("4.�����ҵ\n");
        printf("5.�鿴�γ�����\n");
        printf("6.�ϴ��γ�����\n");
        printf("0.�˳�����Աϵͳ\n");
        printf("����������ѡ��");
        choice = input::getOperatorNum();
    }
}

void Admin::showDocument()
{
    string Course_name;
    cout << "������γ����ƣ�";
    Course_name = Input<string>();
    Student s;
    course c = s.searchCourse(courses, course_size, Course_name);
    if(c.getName() == "null")
    {
        cout << "û���ҵ��ÿγ�!" << endl;
        return;
    }
    cout << "�γ��������£�" << endl;
    for(int i = 0; i < c.getDocumentsSize(); i++)
    {
        printf("%s\t", c.getDocuments()[i].c_str());
    }
}

void Admin::saveAdminInfo()
{
    for(int i = 0; i < student_size; i++)
    {
        students[i].saveStuInfo();
    }
    cout << "����Ա��Ϣ������ɣ�" << endl;
}