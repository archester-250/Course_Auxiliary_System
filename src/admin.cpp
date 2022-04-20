#include "admin.h"

course * admin::addCourse(course * c, int & size, string stuname)
{
    size++;
    //done
    course * newArray = new course[size];
    for (int i = 0; i < size - 1; i++)
    {
        newArray[i] = c[i];
    }
    cout << "请输入课程名称：";
    newArray[size - 1].setName(Input<string>());
    cout << "请输入每周课程次数：";
    newArray[size - 1].setTimeSize(Input<int>());
    course_time * newTime = new course_time[newArray[size - 1].getTimeSize()];
    for (int i = 0; i < newArray[size - 1].getTimeSize(); i++)
    {
        cout << "请输入第" << i + 1 << "次课程在周几上课：";
        newTime[i].week = Input<int>();
        cout << "请输入第" << i + 1 << "次课程的开始时间：";
        newTime[i].starthour = Input<int>();
        cout << "请输入第" << i + 1 << "次课程的结束时间：";
        newTime[i].endhour = Input<int>();
    }
    newArray[size - 1].setTime(newTime, newArray[size - 1].getTimeSize());
    cout << "请输入课程地点：";
    newArray[size - 1].setAddress(Input<string>());
    cout << "请输入当前课程进度：";
    newArray[size - 1].setCurrent(Input<string>());
    string * newDocuments = NULL;
    newArray[size - 1].setDocuments(newDocuments, 0);
    cout << "请输入课程QQ群：";
    newArray[size - 1].setQQGroup(Input<string>());
    Time t;
    t.yr = 0; t.mn = 0; t.day = 0; t.hr = 0;
    newArray[size - 1].setExtime(t);
    newArray[size - 1].setExaddress("null");
    newArray[size - 1].setHomeWork(newDocuments, 0);
    cout << "添加成功！" << endl;
    string cmd = "mkdir ..\\documents\\users\\" + stuname + "\\" + newArray[size - 1].getName();
    system(cmd.c_str());
    delete[] newTime;
    delete[] newDocuments;
    delete[] c;
    return newArray;
}

/**
 * @brief 上传课程资料
 * 
 * @param road 上传路径
 */
string admin::uploadDocument(string road, string name)
{
    string cmd = "copy " + road + " ..\\documents\\public\\" + name;
    system(cmd.c_str());
    return " ..\\documents\\public\\" + name;
}