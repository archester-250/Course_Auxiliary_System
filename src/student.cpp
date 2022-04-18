
#include "student.h"
#include "course.h"
#include "utils.h"
#include "hashMap.h"
#include "prepocess.h"
#include "input.h"

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
    string address;
    bool clk = false;
    cout << "输入开始时间的字符串格式(如：2022040715)" << endl;
    startTime.inputTime(Input<int>());
    cout << "输入结束时间的字符串格式(如：2022040718)" << endl;
    endTime.inputTime(Input<int>());
    cout << "输入活动地址" << endl;
    string tmp = Input<string>();
    cout << "输入活动成员(不含自己)" << endl;
    //todo
    cout << "是否设定闹钟（提前一小时提醒)？true/false" << endl;
    clk = Input<bool>();
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

void Student::setCourses(course * courses)
{
    this->courses = courses;
}

Student::Student(string name)
{
    this->name = name;
    ifstream in("../documents/users/"+name+"/"+name+".data");
    int c_count, all_count;//课程总数
    in>>c_count;
    courses = new course[c_count];
    prepocess p;
    course * allCourses = p.coursesInitialize(all_count);//done
    for(int i = 0; i < c_count; i++)
    {
        string course;int counts;//课程，作业布置次数
        in>>course>>counts;
        for(int j = 0; j < all_count; j++)
        {
            if(!OurStr::StrCmp(allCourses[j].getName(), course))
            {
                courses[i] = allCourses[j];
                break;
            }
        }
        for(int j = 0; j < counts; j++)
        {
            
        }
    }
    delete[] allCourses;
    in.close();
}