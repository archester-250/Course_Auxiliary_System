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
#include "login.h"
#include "utils.h"
#include "student.h"
#include <iostream>
#include <ctime>
#include <fstream>
#include <io.h>
#include "hashMap.h"
#include "admin.h"

HashMap<int, Clock> clocks(64);
HashMap<int, Activity> activities(128);

using namespace std;

Time modtime;
int systime = clock();
int sys_time_bias_times = SYS_TIME_BIAS_TIMES;

ofstream _log("log");
streambuf *clogbuf = std::clog.rdbuf();

int main()
{
    ifstream config("../database/config");
    int init_time = 0;
    config >> init_time;
    modtime.inputTime(init_time);
    config.close();
    int notEnd = 1;
    while (notEnd) {
        cout << "初始时间：" <<  modtime.toString();
        if (clock() - systime > sys_time_bias_times){
            modtime.incre((clock() - systime) / sys_time_bias_times);
            systime = clock();
            // 检查闹钟
            Clock clock = clocks.get(modtime.timeStamp());
            if (clock.time.timeStamp()){//BUG here
                cout << "[事件提醒]" << clock.toString();
            }
        }
        notEnd = login::dologin().notEnd;
        if(notEnd == 1)
        {
            Student student;
        }
        else if(notEnd == 2)
        {

        }
    }
    clog.rdbuf(clogbuf);
    ofstream _config("../database/config");
    _config << modtime.timeStamp();
    _config.close();
    return 0;
}

