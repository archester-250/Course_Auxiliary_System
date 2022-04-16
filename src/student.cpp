
#include "student.h"
#include "course.h"
#include "utils.h"
#include "hashMap.h"

using namespace std;

extern HashMap<int, Activity> activities;

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
    char address[128];
    bool clk = false;
    int tmp;
    cout << "输入开始时间的字符串格式(如：2022040715)" << endl;
    cin >> tmp;
    startTime.inputTime(tmp);
    cout << "输入结束时间的字符串格式(如：2022040718)" << endl;
    cin >> tmp;
    endTime.inputTime(tmp);
    cout << "输入活动地址" << endl;
    cin >> address;
    cout << "输入活动成员(不含自己)" << endl;
    //todo
    cout << "是否设定闹钟（提前一小时提醒)？true/false" << endl;
    cin >> clk;
    activity.setStartTime(startTime);
    activity.setEndTime(endTime);
    activity.setAddress(address);
    activity.setClk(clk);
    if (clk){
        Clock clock;
        Time time = startTime.desc(1);
        clock.setTime(time);
        activities.put(startTime.timeStamp(), activity);
//        clock.setStudent();todo
    }
}

void Student::addCourse(course * c[], int & size, course newc)
{
    size++;
    course * newArray = new course[size];
    memcpy(newArray, c, sizeof(course) * (size - 1));
    newArray[size-1] = newc;
    delete *c;
    (*c) = newArray;
    string cmd = "mkdir ..\\documents\\users\\" + name + "\\" + newc.getName();
    system(cmd.c_str());
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


