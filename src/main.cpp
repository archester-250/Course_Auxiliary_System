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


/*const */ int SYS_TIME_BIAS_TIMES = 5000;
//时间倍率，现在好像是5秒一小时
using namespace std;

Time modtime;
int systime = clock();

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
        printf("初始时间：%d", modtime.timeStamp());
        //WARNING: 目前的计时应该都是错的
        if (clock() - systime > SYS_TIME_BIAS_TIMES){
            systime = clock();
            modtime.incre(1);
            // 检查闹钟
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
