#include "prepocess.h"
course * prepocess::coursesInitialize()
{
    ifstream fin("../documents/courses.data");
    int c_count;//¿Î³Ì×ÜÊý
    fin>>c_count;
    course * courses = new course[c_count];
    for(int i = 0; i < c_count; i++)
    {
        string name;
        int time;
        string address;
        fin>>name>>time>>address;
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
        int extime;
        string exaddress;
        fin>>QQGroup>>extime>>exaddress;
        course c(name, time, address, documents, current, homeWork, QQGroup, extime, exaddress);
        courses[i] = c;
    }
    return NULL;
}