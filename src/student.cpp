
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
    cout << "输入开始时间的字符串格式(如：22040715)" << endl;
    do {
        inTime = Input<int>();
    } while (time_conflict(inTime));
    startTime.inputTime(inTime);
    cout << "输入结束时间的字符串格式(如：22040718)" << endl;
    endTime.inputTime(Input<int>());
    cout << "输入活动地址" << endl;
    string address = Input<string>();
    cout << "输入活动成员(不含自己)" << endl;
    //todo
    cout << "输入活动描述" << endl;
    string description = Input<string>();
    cout << "提前多少小时进行提醒(输入-1则不提醒)" << endl;
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
    clog << student->name << "添加事件：" << activity.toString() << endl;
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
    printf("欢迎进入课内管理系统!请选择要进行的操作:\n");
    printf("1.查看今日课程信息\n");
    printf("2.导出课程表\n");
    printf("3.搜索课程查看详情\n");
    printf("4.查看课程作业\n");
    printf("5.上传作业\n");
    printf("9.返回上一级\n");
    printf("0.返回主页\n");
    int choice = input::getOperatorNum();
    while (choice) {
        switch (choice) {
            case 1:
                showTodayCourse();//显示今日课程表
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
                printf("输入错误，请重新输入\n");
                break;
        }
        printf("欢迎进入课内管理系统!请选择要进行的操作:\n");
        printf("1.查看今日课程信息\n");
        printf("2.导出课程表并打开查看\n");
        printf("3.搜索课程查看详情\n");
        printf("4.查看课程作业\n");
        printf("5.上传作业\n");
        printf("9.返回上一级\n");
        printf("0.返回主页\n");
        choice = input::getOperatorNum();
    }
    return 1;
}

void Student::showTodayCourse() {
    cout << "今天是" << modtime.yr << "年" << modtime.mn << "月" << modtime.day << "日,星期";
    string week[7] = {"日", "一", "二", "三", "四", "五", "六"};
    int weekDay = modtime.calculateWeekDay();
    cout << week[weekDay] << endl;
    for (int i = 0; i < course_size; i++) {
        for (int j = 0; j < courses[i].getTimeSize(); j++) {
            if (courses[i].getTime()[j].week == weekDay) {
                printf("%s\t%d时--%d时\n", courses[i].getName().c_str(), courses[i].getTime()[j].starthour,
                       courses[i].getTime()[j].endhour);
            }
        }
    }
}

void Student::courseTable() {
    ofstream out("../documents/users/" + this->name + "/courseTable_" + name + ".csv");
    out << ",星期一,星期二,星期三,星期四,星期五,星期六,星期日\n";
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
    cout << "已经生成课程表。正在打开..." << endl;
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
    cout << "已自动保存学生课程信息" << endl;
}

int Student::showActivityMenu() {
    int choice;
    do {
        updateTime();
        //亮神finish
        printf("欢迎进入活动管理系统!请选择要进行的操作:\n");
        cout << "1.增加事件" << endl;
        cout << "2.事件一览(全部)" << endl;
        cout << "3.今日事件一览" << endl;
        printf("9.返回上级\n");
        printf("0.返回主页\n");
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
        clog << "读取本地活动：" << activity.toString() << endl;
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
