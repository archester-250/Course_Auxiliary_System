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
    return to_string(yr) + "��" + to_string(mn) + "��" + to_string(day) + "��" + to_string(hr) + "ʱ ";
}
