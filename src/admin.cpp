#include "admin.h"

void admin::addCourse(course * c[], int & size)
{
    string name;
    size++;
    course newc;
    //todo
    course * newArray = new course[size];
    memcpy(newArray, c, sizeof(course) * (size - 1));
    newArray[size-1] = newc;
    delete *c;
    (*c) = newArray;
    string cmd = "mkdir ..\\documents\\users\\" + name + "\\" + newc.getName();
    system(cmd.c_str());
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