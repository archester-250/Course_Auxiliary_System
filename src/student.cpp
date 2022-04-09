
#include "student.h"
#include "course.h"

using namespace std;

int Student::getId() const {
    return id;
}

void Student::setId(int id) {
    Student::id = id;
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
    cout << "输入活动成员" << endl;
    //todo
    cout << "是否设定闹钟（提前一小时提醒)？true/false" << endl;
    cin >> clk;
    activity.setStartTime(startTime);
    activity.setEndTime(endTime);
    activity.setAddress(address);
    activity.setClk(clk);
    if (clk){
        Clock clock;
        clock.setTime(startTime);
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
}
