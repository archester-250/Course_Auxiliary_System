/**
 * @file main.cpp
 * @author your name (you@domain.com)
 * @brief 主程序
 * @version 0.1
 * @date 2022-03-17
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#define DEBUG
#include "login.h"
#include "student.h"
#include "admin.h"
#include <ctime>
#include <fstream>
#include <io.h>
#include "hashMap.h"


HashMap<int, Student> students(128);

using namespace std;

extern Student * student;

Time modtime;
int systime = clock();
int sys_time_bias_times = SYS_TIME_BIAS_TIMES;

void updateTime(){
    if (clock() - systime > sys_time_bias_times){
        modtime.incre((clock() - systime) / sys_time_bias_times);
        systime = clock();
    }
}

int main()
{
    ofstream ofs("../log", ios::app);
    clog.rdbuf(ofs.rdbuf());
    ifstream config("../database/config");
    int init_time = 0;
    config >> init_time;
    modtime.inputTime(init_time);
    config.close();
#ifdef DEBUG
    modtime.inputTime(21010818);
#endif
    int notEnd = 1;
    while (notEnd) {
        cout << "\033[40;31m|\033[0m";
        cout << "=====BUPT GUIDE====" << "时间：" <<  modtime.toString();
        updateTime();
        info login_info = login::dologin();
        notEnd = login_info.notEnd;
        if(notEnd == 1)
        {
            student = new Student(login_info.user);
            student->InitStudent();
            student->showMenu();
            student->saveStuInfo();//保存学生个人信息至文件
        }
        else if(notEnd == 2)
        {
            admin = new Admin(login_info.user);
            admin->showMenu();
            admin->saveAdminInfo();//保存管理员个人信息至文件
        }
    }
    ofstream _config("../database/config");
    _config << modtime.timeStamp();
    _config.close();
    ofs.close();
    return 0;
}

