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
    cout << "������γ����ƣ�";
    newArray[size - 1].setName(Input<string>());
    cout << "������ÿ�ܿγ̴�����";
    newArray[size - 1].setTimeSize(Input<int>());
    course_time * newTime = new course_time[newArray[size - 1].getTimeSize()];
    for (int i = 0; i < newArray[size - 1].getTimeSize(); i++)
    {
        cout << "�������" << i + 1 << "�ογ����ܼ��ϿΣ�";
        newTime[i].week = Input<int>();
        cout << "�������" << i + 1 << "�ογ̵Ŀ�ʼʱ�䣺";
        newTime[i].starthour = Input<int>();
        cout << "�������" << i + 1 << "�ογ̵Ľ���ʱ�䣺";
        newTime[i].endhour = Input<int>();
    }
    newArray[size - 1].setTime(newTime, newArray[size - 1].getTimeSize());
    cout << "������γ̵ص㣺";
    newArray[size - 1].setAddress(Input<string>());
    cout << "�����뵱ǰ�γ̽��ȣ�";
    newArray[size - 1].setCurrent(Input<string>());
    string * newDocuments = NULL;
    newArray[size - 1].setDocuments(newDocuments, 0);
    cout << "������γ�QQȺ��";
    newArray[size - 1].setQQGroup(Input<string>());
    Time t;
    t.yr = 0; t.mn = 0; t.day = 0; t.hr = 0;
    newArray[size - 1].setExtime(t);
    newArray[size - 1].setExaddress("null");
    newArray[size - 1].setHomeWork(newDocuments, 0);
    cout << "��ӳɹ���" << endl;
    string cmd = "mkdir ..\\documents\\users\\" + stuname + "\\" + newArray[size - 1].getName();
    system(cmd.c_str());
    delete[] newTime;
    delete[] newDocuments;
    delete[] c;
    return newArray;
}

/**
 * @brief �ϴ��γ�����
 * 
 * @param road �ϴ�·��
 */
string admin::uploadDocument(string road, string name)
{
    string cmd = "copy " + road + " ..\\documents\\public\\" + name;
    system(cmd.c_str());
    return " ..\\documents\\public\\" + name;
}