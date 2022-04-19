#include "prepocess.h"
course * prepocess::coursesInitialize(int & all_count)
{
    ifstream fin("../database/course.data");
    int c_count;//¿Î³Ì×ÜÊý
    fin>>c_count;
    all_count = c_count;
    course * courses = new course[c_count];
    for(int i = 0; i < c_count; i++)
    {
        string name;
        fin>>name;
        courses[i].setName(name);

        int t_count;
        fin>>t_count;
        course_time * time = new course_time[t_count];
        for(int j = 0; j < t_count; j++)
        {
            fin>>time[j].week>>time[j].starthour>>time[j].endhour;
        }
        courses[i].setTime(time);

        string address;
        fin>>address;
        courses[i].setAddress(address);

        int doc_count;
        fin>>doc_count;
        string * documents = new string[doc_count];
        for(int j = 0; j < doc_count; j++)
        {
            fin>>documents[j];
        }
        courses[i].setDocuments(documents);

        string current;
        fin>>current;
        courses[i].setCurrent(current);

        string * homeWork;
        int hw_count;
        fin>>hw_count;
        homeWork = new string[hw_count];
        for(int j = 0; j < hw_count; j++)
        {
            fin>>homeWork[j];
        }
        courses[i].setHomeWork(homeWork);

        string QQGroup;
        fin>>QQGroup;
        courses[i].setQQGroup(QQGroup);

        Time extime;
        fin>>extime.yr>>extime.mn>>extime.day>>extime.hr;
        courses[i].setExtime(extime);
        string exaddress;
        fin>>exaddress;
        courses[i].setExaddress(exaddress);
    }
    fin.close();
    return courses;
}