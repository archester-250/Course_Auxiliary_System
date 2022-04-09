/**
 * @file main.cpp
 * @author your name (you@domain.com)
 * @brief ������
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
#include <io.h>


/*const */ int SYS_TIME_BIAS_TIMES = 5000;
//ʱ�䱶�ʣ����ں�����5��һСʱ
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
        printf("��ʼʱ�䣺%d(����0�˳���\n", modtime.timeStamp());
        //WARNING: Ŀǰ�ļ�ʱӦ�ö��Ǵ��
        if (clock() - systime > SYS_TIME_BIAS_TIMES){
            systime = clock();
            modtime.incre();
            // �������
        }
        notEnd = login::dologin();
    }
    clog.rdbuf(clogbuf);
    ofstream _config("../database/config");
    _config << modtime.timeStamp();
    _config.close();
    return 0;
}
