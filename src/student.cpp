
#include "student.h"
#include "course.h"
#include "utils.h"
#include "hashMap.h"
#include "prepocess.h"
#include "input.h"

using namespace std;

extern HashMap<int, Student> students;
Student student("wxl");

string Student::getName()
{
    return name;
}

void Student::setName(string name)
{
    this->name = name;
}

void Student::addActivity() {
    Activity activity;
    Time startTime, endTime;
    string address;
    bool clk = false;
    cout << "���뿪ʼʱ����ַ�����ʽ(�磺2022040715)" << endl;
    startTime.inputTime(Input<int>());
    cout << "�������ʱ����ַ�����ʽ(�磺2022040718)" << endl;
    endTime.inputTime(Input<int>());
    cout << "������ַ" << endl;
    string tmp = Input<string>();
    cout << "������Ա(�����Լ�)" << endl;
    //todo
    cout << "�Ƿ��趨���ӣ���ǰһСʱ����)��true/false" << endl;
    clk = Input<bool>();
    activity.setStartTime(startTime);
    activity.setEndTime(endTime);
    activity.setAddress(address);
    activity.setClk(clk);
    if (clk){
        Clock clock;
        Time time = startTime.desc(1);
        clock.setTime(time);
        this->activities->put(startTime.timeStamp(), activity);
    }
}

course Student::searchCourse(course c[], int size, string name)
{
    course temp;
    for(int i = 0; i < size; i++)
    {
        if(!OurStr::StrCmp(c[i].getName(), name))
        {
            return c[i];
        }
    }
    return temp;
}

course * Student::getCourses()
{
    return this->courses;
}

void Student::setCourses(course * courses, int c_count)
{
    this->courses = new course[c_count];
    for(int i = 0; i < c_count; i++)
    {
        this->courses[i] = courses[i];
    }
}

int Student::getCourseSize()
{
    return this->course_size;
}

Student::Student(string name)
{
    this->name = name;
    ifstream in("../documents/users/"+name+"/"+name+".data");
    int c_count, all_count;//�γ�����
    in>>c_count;
    course_size = c_count;
    courses = new course[c_count];
    prepocess p;
    course * allCourses = p.coursesInitialize(all_count);//done
    for(int i = 0; i < c_count; i++)
    {
        string course;int counts;//�γ̣���ҵ���ô���
        in>>course>>counts;
        courses[i].setFinishSize(counts);
        for(int j = 0; j < all_count; j++)
        {
            if(!OurStr::StrCmp(allCourses[j].getName(), course))
            {
                courses[i] = allCourses[j];
                break;
            }
        }
        hw_con * b = new hw_con[counts];
        for(int j = 0; j < counts; j++)
        {
            in>>b[j].finish;
            if(b[j].finish)
            {
                in>>b[j].road;
            }
        }
        courses[i].setFinish(b, counts);
        delete[] b;
    }
    delete[] allCourses;
    in.close();
}

void Student::showMenu()
{
    auto clockCheck = student.getClocks()->get(modtime.timeStamp());
    if (clockCheck->first){
        cout << "[�¼�����]" << clockCheck->second.toString();
    }
    printf("��ӭѧ�� %s\n��ѡ��Ҫ�����ϵͳ:\n", getName().c_str());
    printf("1.������Ϣ����ϵͳ\n");
    printf("2.������Ϣ����ϵͳ\n");
    printf("0.�˳�ϵͳ\n");
    int choice = input::getOperatorNum();
    while(choice)
    {
        switch(choice)
        {
            case 1:
                choice = showCourseMenu();
                break;
            case 2:
                choice = showActivityMenu();
                break;
            case 0:
                return;
            default:
                printf("�����������������\n");
                break;
        }
        if(!choice)
        {
            return;
        }
        printf("��ѡ��Ҫ�����ϵͳ:\n");
        printf("1.������Ϣ����ϵͳ\n");
        printf("2.������Ϣ����ϵͳ\n");
        printf("0.�˳�ϵͳ\n");
        choice = input::getOperatorNum();
    }
}

int Student::showCourseMenu()
{
    printf("��ӭ������ڹ���ϵͳ!��ѡ��Ҫ���еĲ���:\n");
    printf("1.�鿴���տγ���Ϣ\n");
    printf("2.�鿴�γ̱�\n");
    printf("3.�����γ̲鿴����\n");
    printf("4.�鿴�γ���ҵ\n");
    printf("5.�ϴ���ҵ\n");
    printf("9.������һ��\n");
    printf("0.������ҳ\n");
    int choice = input::getOperatorNum();
    while(choice)
    {
        switch(choice)
        {
            case 1:
                // showTodayCourse();//todo
                break;
            case 2:
                // showCourseTable();//todo
                break;
            case 3:
                // showCourseDetail();//todo
                break;
            case 4:
                // showCourseHw();//todo
                break;
            case 5:
                // uploadHw();//todo
                break;
            case 9:
                return 1;
            case 0:
                return 0;
            default:
                printf("�����������������\n");
                break;
        }
        printf("��ӭ������ڹ���ϵͳ!��ѡ��Ҫ���еĲ���:\n");
        printf("1.�鿴���տγ���Ϣ\n");
        printf("2.�鿴�γ̱�\n");
        printf("3.�����γ̲鿴����\n");
        printf("4.�鿴�γ���ҵ\n");
        printf("5.�ϴ���ҵ\n");
        printf("9.������һ��\n");
        printf("0.������ҳ\n");
        choice = input::getOperatorNum();
    }
    return 1;
}

int Student::showActivityMenu()
{
    //����finish
    printf("��ӭ��������ϵͳ!��ѡ��Ҫ���еĲ���:\n");
    printf("9.������һ��\n");
    printf("0.������ҳ\n");
    int choice = input::getOperatorNum();
    while(choice)
    {
        switch(choice)
        {
            case 9:
                return 1;
            case 0:
                return 0;
            default:
                printf("�����������������\n");
                break;
        }
        printf("��ӭ��������ϵͳ!��ѡ��Ҫ���еĲ���:\n");
        printf("9.������һ��\n");
        printf("0.������ҳ\n");
        choice = input::getOperatorNum();
    }
    return 1;
}

Student::Student() {

}

HashMap<int, Activity> *Student::getActivities() const {
    return activities;
}

HashMap<int, Clock> *Student::getClocks() const {
    return clocks;
}
