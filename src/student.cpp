
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
    cout << "输入开始时间的字符串格式(如：22040715)" << endl;
    startTime.inputTime(Input<int>());
    cout << "输入结束时间的字符串格式(如：22040718)" << endl;
    endTime.inputTime(Input<int>());
    cout << "输入活动地址" << endl;
    string address = Input<string>();
    cout << "输入活动成员(不含自己)" << endl;
    //todo
    cout << "输入活动描述" << endl;
    string description = Input<string>();
    cout << "是否设定闹钟（提前一小时提醒)？true/false" << endl;
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
    clog << student.name << "添加事件：" << activity.toString() << endl;
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
    int c_count, all_count;//课程总数
    in >> c_count;
    course_size = c_count;
    courses = new course[c_count];
    prepocess p;
    course *allCourses = p.coursesInitialize(all_count);//done
    for (int i = 0; i < c_count; i++) {
        string course;
        int counts;//课程，作业布置次数
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
    printf("欢迎学生 %s，", getName().c_str());
    int choice = 0;
    do {
        updateTime();
        auto clockCheck = student.getClocks()->get(modtime.timeStamp());
        if (clockCheck->first) {
            cout << "[事件提醒]" << clockCheck->second.toString();
        }
        cout << "当前时间：" << modtime.toString() << endl;
        cout << "请选择要进入的系统(按0退出)\n";
        printf("1.课内信息管理系统\n");
        printf("2.课外信息管理系统\n");
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
                printf("输入错误，请重新输入\n");
                break;
        }
    } while (choice);
    return;
}

int Student::showCourseMenu() {
    updateTime();
    auto clockCheck = student.getClocks()->get(modtime.timeStamp());
    if (clockCheck->first) {
        cout << "[事件提醒]" << clockCheck->second.toString();
    }
    printf("欢迎进入课内管理系统!请选择要进行的操作:\n");
    printf("1.查看今日课程信息\n");
    printf("2.查看课程表\n");
    printf("3.搜索课程查看详情\n");
    printf("4.查看课程作业\n");
    printf("5.上传作业\n");
    printf("9.返回上一级\n");
    printf("0.返回主页\n");
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
                printf("输入错误，请重新输入\n");
                break;
        }
        printf("欢迎进入课内管理系统!请选择要进行的操作:\n");
        printf("1.查看今日课程信息\n");
        printf("2.查看课程表\n");
        printf("3.搜索课程查看详情\n");
        printf("4.查看课程作业\n");
        printf("5.上传作业\n");
        printf("9.返回上一级\n");
        printf("0.返回主页\n");
        choice = input::getOperatorNum();
    }
    return 1;
}

void Student::showTodayCourse()
{
    cout << "今天是" << modtime.yr << "年" << modtime.mn << "月" << modtime.day << "日,星期";
    string week[7] = {"日", "一", "二", "三", "四", "五", "六"};
    int weekDay = modtime.calculateWeekDay();
    cout << week[weekDay] << endl;
    for(int i = 0; i < course_size; i++)
    {
        for(int j = 0; j < courses[i].getTimeSize(); j++)
        {
            if(courses[i].getTime()[j].week == weekDay)
            {
                printf("%s\t%d时--%d时\n", courses[i].getName().c_str(), courses[i].getTime()[j].starthour, courses[i].getTime()[j].endhour);
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
            cout << "[事件提醒]" << clockCheck->second.toString();
        }
        //亮神finish
        printf("欢迎进入活动管理系统!请选择要进行的操作:\n");
        cout << "1.增加事件" << endl;
        cout << "2.事件一览" << endl;
        printf("9.返回上级\n");
        printf("0.返回主页\n");
        int choice = input::getOperatorNum();
        switch (choice) {
            case 1:
                student.addActivity();
                break;
            case 2:
                //这里需要一个循环
                break;
            case 9:
                return 1;
            case 0:
                return 0;
            default:
                printf("输入错误，请重新输入\n");
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
        clog << "读取本地活动：" << activity.toString() << endl;
    }
}
