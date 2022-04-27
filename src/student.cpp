
#include <cassert>
#include "hashMap.h"
#include "activity.h"
#include "student.h"
#include "course.h"
#include "utils.h"
#include "prepocess.h"
#include "input.h"

using namespace std;

extern void updateTime();

extern HashMap<string, Student> students;
Student *student;

string Student::getName() {
    return name;
}

void Student::setName(string name) {
    this->name = name;
}

void Student::addActivity() {
    Activity activity;
    Time startTime, endTime;
    int clk = 0;
    int inTime;
    cout << "���뿪ʼʱ����ַ�����ʽ(�磺22040715)" << endl;
    do {
        inTime = Input<int>();
    } while (time_conflict(inTime));
    startTime.inputTime(inTime);
    cout << "�������ʱ����ַ�����ʽ(�磺22040718)" << endl;
    endTime.inputTime(Input<int>());
    cout << "������ַ" << endl;
    string address = Input<string>();
    cout << "������Ա(�����Լ�)" << endl;
    //todo
    cout << "��������" << endl;
    string description = Input<string>();
    cout << "��ǰ����Сʱ��������(����-1������)" << endl;
    clk = Input<int>();
    activity.setStartTime(startTime);
    activity.setEndTime(endTime);
    activity.setAddress(address);
    activity.setDescription(description);
    activity.setClk(clk);
    if (clk >= 0) {
        Time time = startTime.desc(clk);
        if (clocks->get(time.timeStamp())->first) {
            clocks->get(time.timeStamp())->second.addEvent(activity.toString());
        } else {
            Clock clock;
            clock.setTimestamp(time.timeStamp());
            clock.addEvent(activity.toString());
            clocks->put(time.timeStamp(), clock);
        }
    }
    clog << student->name << "����¼���" << activity.toString() << endl;
    ofstream _config("../database/activities/" + student->name, ios::app);
    assert(_config);
    _config << activity.storeStr() << endl;
    _config.close();
    Activities->push(activity);
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
    printf("��ӭ������ڹ���ϵͳ!��ѡ��Ҫ���еĲ���:\n");
    printf("1.�鿴���տγ���Ϣ\n");
    printf("2.�����γ̱�\n");
    printf("3.�����γ̲鿴����\n");
    printf("4.�鿴�γ���ҵ\n");
    printf("5.�ϴ���ҵ\n");
    printf("9.������һ��\n");
    printf("0.������ҳ\n");
    int choice = input::getOperatorNum();
    while (choice) {
        switch (choice) {
            case 1:
                showTodayCourse();//��ʾ���տγ̱�
                break;
            case 2:
                courseTable();//todo
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
        printf("2.�����γ̱��򿪲鿴\n");
        printf("3.�����γ̲鿴����\n");
        printf("4.�鿴�γ���ҵ\n");
        printf("5.�ϴ���ҵ\n");
        printf("9.������һ��\n");
        printf("0.������ҳ\n");
        choice = input::getOperatorNum();
    }
    return 1;
}

void Student::showTodayCourse() {
    cout << "������" << modtime.yr << "��" << modtime.mn << "��" << modtime.day << "��,����";
    string week[7] = {"��", "һ", "��", "��", "��", "��", "��"};
    int weekDay = modtime.calculateWeekDay();
    cout << week[weekDay] << endl;
    for (int i = 0; i < course_size; i++) {
        for (int j = 0; j < courses[i].getTimeSize(); j++) {
            if (courses[i].getTime()[j].week == weekDay) {
                printf("%s\t%dʱ--%dʱ\n", courses[i].getName().c_str(), courses[i].getTime()[j].starthour,
                       courses[i].getTime()[j].endhour);
            }
        }
    }
}

void Student::courseTable() {
    ofstream out("../documents/users/" + this->name + "/courseTable_" + name + ".csv");
    out << ",����һ,���ڶ�,������,������,������,������,������\n";
    string table[14][7];
    for (int i = 0; i < course_size; i++) {
        for (int j = 0; j < courses[i].getTimeSize(); j++) {
            for (int k = courses[i].getTime()[j].starthour; k <= courses[i].getTime()[j].endhour; k++) {
                table[k - 8][(courses[i].getTime()[j].week + 6) % 7] = courses[i].getName();
            }
        }
    }
    for (int i = 0; i < 14; i++) {
        out << i + 8 << ":00";
        for (int j = 0; j < 7; j++) {
            out << ',' << table[i][j];
        }
        out << endl;
    }
    out.close();
    cout << "�Ѿ����ɿγ̱����ڴ�..." << endl;
    string cmd = "cd ..\\documents\\users\\" + this->name + " & courseTable_" + this->name + ".csv";
    system(cmd.c_str());
}

void Student::saveStuInfo() {
    ofstream out("../documents/users/" + this->name + "/" + this->name + ".data");
    out << course_size << endl;
    for (int i = 0; i < course_size; i++) {
        out << courses[i].getName() << ' ';
        out << courses[i].getFinishSize() << endl;
        for (int j = 0; j < courses[i].getFinishSize(); j++) {
            out << courses[i].getFinish()[j].finish;
            if (courses[i].getFinish()[j].finish) {
                out << ' ' << courses[i].getFinish()[j].road << endl;
            } else {
                out << endl;
            }
        }
    }
    cout << "���Զ�����ѧ���γ���Ϣ" << endl;
}

int Student::showActivityMenu() {
    int choice;
    do {
        updateTime();
        //����finish
        printf("��ӭ��������ϵͳ!��ѡ��Ҫ���еĲ���:\n");
        cout << "1.�����¼�" << endl;
        cout << "2.�¼�һ��(ȫ��)" << endl;
        cout << "3.�����¼�һ��" << endl;
        printf("9.�����ϼ�\n");
        printf("0.������ҳ\n");
        choice = input::getOperatorNum();
        switch (choice) {
            case 1:
                student->addActivity();
                break;
            case 2:
                student->showActivities(false);
                break;
            case 3:
                student->showActivities(true);
                break;
            case 9:
                return 1;
            case 0:
                student->Activities->size = 0;
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

void Student::InitStudent() {
    ifstream db("../database/activities/" + student->name);
    int startTime, endTime, clk;
    string address, description;
    while (db >> startTime >> endTime >> address >> description >> clk) {
        Activity activity;
        Time start, end;
        start.inputTime(startTime);
        end.inputTime(endTime);
        activity.setStartTime(start);
        activity.setEndTime(end);
        activity.setAddress(address);
        activity.setDescription(description);
        activity.setClk(clk);
        student->getActivities()->put(activity.getStartTime().timeStamp(), activity);
        if (clk >= 0) {
            Time time = start.desc(clk);
            if (clocks->get(time.timeStamp())->first) {
                clocks->get(time.timeStamp())->second.addEvent(activity.toString());
            } else {
                Clock clock;
                clock.setTimestamp(time.timeStamp());
                clock.addEvent(activity.toString());
                clocks->put(time.timeStamp(), clock);
            }
        }
        clog << "��ȡ���ػ��" << activity.toString() << endl;
        Activities->push(activity);
    }
}

void Student::showActivities(bool today) {
    int sz = Activities->size;
    for (int i = 0; i < sz; i++) {
        Activity activity = Activities->get(i);
        if (today && activity.getStartTime().day != modtime.day) {
            continue;
        }
        cout << Activities->get(i).toString() << endl;
    }
}

HashMap<int, Clock> *Student::getClocks() const {
    return clocks;
}
