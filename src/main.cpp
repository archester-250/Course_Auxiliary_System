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

using namespace std;

Time modtime;//todo:�ļ���ȡ
int systime = time(nullptr);

ofstream log("log");
streambuf *clogbuf = std::clog.rdbuf();

int main()
{
    int notEnd = 1;
    while (notEnd) {
        printf("��ʼʱ�䣺%d(����0�˳���\n", modtime.timeStamp());
        //WARNING: Ŀǰ�ļ�ʱӦ�ö��Ǵ��
        if (clock() - systime > 98765){
            systime = clock();
            modtime.incre();
            // �������
        }
        notEnd = login::dologin();
    }
    clog.rdbuf(clogbuf);
    return 0;
}
