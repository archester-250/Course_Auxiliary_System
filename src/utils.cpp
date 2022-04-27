//
// Created by ll on 2022/4/15.
//
#include "utils.h"
#include "input.h"
#include "login.h"

int tmptime = clock();

void Time::pause() {
    tmptime = clock();
}

void Time::recover() {
    sys_time_bias_times += (clock() - tmptime);
}

string Time::toString() {
    return to_string(yr) + "年" + to_string(mn) + "月" + to_string(day) + "日" + to_string(hr) + "时 ";
}

void Time::incre(int h) {
    sys_time_bias_times = SYS_TIME_BIAS_TIMES;
    while (h--) {
        if (hr == 23) {
            hr = 0;
            if (day == MonthDays(yr, mn)) {
                day = 1;
                if (mn < 12)
                    mn++;
                else{
                    mn = 1;
                    yr++;
                }
            } else
                day++;
        } else
            hr++;
        auto clockCheck = student->getActivities()->get(modtime.timeStamp());
        if (clockCheck->first){
            cout << "[事件提醒]" << clockCheck->second.toString() << endl;
        }
    }
    cout << "[当前时间]" << toString() << endl;
}
