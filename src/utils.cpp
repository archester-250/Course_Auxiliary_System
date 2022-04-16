//
// Created by ll on 2022/4/15.
//
#include "utils.h"

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
