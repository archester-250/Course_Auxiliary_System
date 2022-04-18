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

        course_time * time;
        int t_count;
        fin>>t_count;
        time = new course_time[t_count];
        for(int j = 0; j < t_count; j++)
        {
            fin>>time[j].week>>time[j].starthour>>time[j].endhour;
        }

        string address;
        fin>>address;

        string * documents;
        int doc_count;
        fin>>doc_count;
        documents = new string[doc_count];
        for(int j = 0; j < doc_count; j++)
        {
            fin>>documents[j];
        }

        string current;
        fin>>current;

        string * homeWork;
        int hw_count;
        fin>>hw_count;
        homeWork = new string[hw_count];
        for(int j = 0; j < hw_count; j++)
        {
            fin>>homeWork[j];
        }

        string QQGroup;
        fin>>QQGroup;

        Time extime;
        fin>>extime.yr>>extime.mn>>extime.day>>extime.hr;
        string exaddress;
        fin>>exaddress;
        course c(name, time, address, documents, current, homeWork, QQGroup, extime, exaddress);
        courses[i] = c;
    }
    fin.close();
    return courses;
}