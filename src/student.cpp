
#include <cassert>
#include "student.h"
#include "course.h"
#include "utils.h"
#include "hashMap.h"
#include "prepocess.h"
#include "input.h"

using namespace std;

extern void updateTime();

extern HashMap<string, Student> students;
Student student("wxl");

string Student::getName() {
    return name;
}

void Student::setName(string name) {
    this->name = name;
}

void Student::addActivity() {
    Activity activity;
    Time startTime, endTime;
    bool clk = false;
    cout << "���뿪ʼʱ����ַ�����ʽ(�磺22040715)" << endl;
    startTime.inputTime(Input<int>());
    cout << "�������ʱ����ַ�����ʽ(�磺22040718)" << endl;
    endTime.inputTime(Input<int>());
    cout << "������ַ" << endl;
    string address = Input<string>();
    cout << "������Ա(�����Լ�)" << endl;
    //todo
    cout << "��������" << endl;
    string description = Input<string>();
    cout << "�Ƿ��趨���ӣ���ǰһСʱ����)��true/false" << endl;
    clk = Input<bool>();
    activity.setStartTime(startTime);
    activity.setEndTime(endTime);
    activity.setAddress(address);
    activity.setClk(clk);
    activity.setDescription(description);
    if (clk) {
        Clock clock;
        Time time = startTime.desc(1);
        clock.setTime(time);
        this->activities->put(startTime.timeStamp(), activity);
    }
    clog << student.name << "����¼���" << activity.toString() << endl;
    ofstream _config("../database/activities/" + student.name, ios::app);
    assert(_config);
    _config << activity.storeStr() << endl;
    _config.close();
}

course Student::searchCourse(course c[], int size, string name) {
    course temp;
    for (int i = 0; i < size; i++) {
        if (!OurStr::StrCmp(c[i].getName(), name)) {
            return c[i];
        }
    }
    return temp;
}

course *Student::getCourses() {
    return this->courses;
}

void Student::setCourses(course *courses, int c_count) {
    this->courses = new course[c_count];
    for (int i = 0; i < c_count; i++) {
        this->courses[i] = courses[i];
    }
}

int Student::getCourseSize() {
    return this->course_size;
}

Student::Student(string name) {
    this->name = name;
    ifstream in("../documents/users/" + name + "/" + name + ".data");
    int c_count, all_count;//�γ�����
    in >> c_count;
    course_size = c_count;
    courses = new course[c_count];
    prepocess p;
    course *allCourses = p.coursesInitialize(all_count);//done
    for (int i = 0; i < c_count; i++) {
        string course;
        int counts;//�γ̣���ҵ���ô���
        in >> course >> counts;
        courses[i].setFinishSize(counts);
        for (int j = 0; j < all_count; j++) {
            if (!OurStr::StrCmp(allCourses[j].getName(), course)) {
                courses[i] = allCourses[j];
                break;
            }
        }
        hw_con *b = new hw_con[counts];
        for (int j = 0; j < counts; j++) {
            in >> b[j].finish;
            if (b[j].finish) {
                in >> b[j].road;
            }
        }
        courses[i].setFinish(b, counts);
        delete[] b;
    }
    delete[] allCourses;
    in.close();
}

void Student::showMenu() {
    printf("��ӭѧ�� %s��", getName().c_str());
    int choice = 0;
    do {
        updateTime();
        auto clockCheck = student.getClocks()->get(modtime.timeStamp());
        if (clockCheck->first) {
            cout << "[�¼�����]" << clockCheck->second.toString();
        }
        cout << "��ǰʱ�䣺" << modtime.toString() << endl;
        cout << "��ѡ��Ҫ�����ϵͳ(��0�˳�)\n";
        printf("1.������Ϣ����ϵͳ\n");
        printf("2.������Ϣ����ϵͳ\n");
        choice = input::getOperatorNum();
        switch (choice) {
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
    } while (choice);
    return;
}

int Student::showCourseMenu() {
    updateTime();
    auto clockCheck = student.getClocks()->get(modtime.timeStamp());
    if (clockCheck->first) {
        cout << "[�¼�����]" << clockCheck->second.toString();
    }
    printf("��ӭ������ڹ���ϵͳ!��ѡ��Ҫ���еĲ���:\n");
    printf("1.�鿴���տγ���Ϣ\n");
    printf("2.�鿴�γ̱�\n");
    printf("3.�����γ̲鿴����\n");
    printf("4.�鿴�γ���ҵ\n");
    printf("5.�ϴ���ҵ\n");
    printf("9.������һ��\n");
    printf("0.������ҳ\n");
    int choice = input::getOperatorNum();
    while (choice) {
        switch (choice) {
            case 1:
                showTodayCourse();//done
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

void Student::showTodayCourse()
{
    cout << "������" << modtime.yr << "��" << modtime.mn << "��" << modtime.day << "��,����";
    string week[7] = {"��", "һ", "��", "��", "��", "��", "��"};
    int weekDay = modtime.calculateWeekDay();
    cout << week[weekDay] << endl;
    for(int i = 0; i < course_size; i++)
    {
        for(int j = 0; j < courses[i].getTimeSize(); j++)
        {
            if(courses[i].getTime()[j].week == weekDay)
            {
                printf("%s\t%dʱ--%dʱ\n", courses[i].getName().c_str(), courses[i].getTime()[j].starthour, courses[i].getTime()[j].endhour);
            }
        }
    }
}

int Student::showActivityMenu() {
    int choice;
    do {
        updateTime();
        auto clockCheck = student.getClocks()->get(modtime.timeStamp());
        if (clockCheck->first) {
            cout << "[�¼�����]" << clockCheck->second.toString();
        }
        //����finish
        printf("��ӭ��������ϵͳ!��ѡ��Ҫ���еĲ���:\n");
        cout << "1.�����¼�" << endl;
        cout << "2.�¼�һ��" << endl;
        printf("9.�����ϼ�\n");
        printf("0.������ҳ\n");
        int choice = input::getOperatorNum();
        switch (choice) {
            case 1:
                student.addActivity();
                break;
            case 2:
                //������Ҫһ��ѭ��
                break;
            case 9:
                return 1;
            case 0:
                return 0;
            default:
                printf("�����������������\n");
                break;
        }
    } while (choice);
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

void Student::InitStudent() {
    ifstream db("../database/activities/" + student.name);
    int startTime, endTime;
    string address, description;
    while (db >> startTime >> endTime >> address >> description) {
        Activity activity;
        Time start, end;
        start.inputTime(startTime);
        end.inputTime(endTime);
        activity.setStartTime(start);
        activity.setEndTime(end);
        activity.setAddress(address);
        activity.setDescription(description);
        student.getActivities()->put(activity.getStartTime().timeStamp(), activity);
        clog << "��ȡ���ػ��" << activity.toString() << endl;
    }
}
