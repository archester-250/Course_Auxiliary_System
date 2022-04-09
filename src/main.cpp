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
#include "course.h"
#include "utils.h"
#include <iostream>
#include <ctime>
#include <fstream>


/*const */ int SYS_TIME_BIAS_TIMES 10000;
//时间倍率，默认是10秒一小时
using namespace std;

Time modtime;//todo:文件读取
int systime = time(nullptr);

ofstream _log("log");
streambuf *clogbuf = std::clog.rdbuf();

int main()
{
    int notEnd = 1;
    while (notEnd) {
        printf("初始时间：%d(输入0退出）\n", modtime.timeStamp());
        //WARNING: 目前的计时应该都是错的
        if (clock() - systime > SYS_TIME_BIAS_TIMES){
            systime = clock();
            modtime.incre();
            // 检查闹钟
        }
        notEnd = login::dologin();
    }
    clog.rdbuf(clogbuf);
    return 0;
}
