#ifndef COURSE_AUXILIARY_SYSTEM_UTILS_H
#define COURSE_AUXILIARY_SYSTEM_UTILS_H

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "admin.h"
#include <string>

using namespace std;

extern int sys_time_bias_times;

class Time {
public:
    int yr = 0, mn = 0, day = 0, hr = 0;
    int timestamp = timeStamp();

    int MonthDays(int yr, int mn) {
        switch (mn) {
            case 1:
            case 3:
            case 5:
            case 7:
            case 8:
            case 10:
            case 12:
                return 31;
            case 4:
            case 6:
            case 9:
            case 11:
                return 30;
            case 2:
                if (yr % 400 == 0) {
                    return 29;
                } else if (yr % 100 == 0) {
                    return 28;
                } else if (yr % 4 == 0) {
                    return 29;
                } else
                    return 28;

        }
        return 28;
    }

    Time desc(int h) {//????hС?
        while (h--) {
            if (hr == 0) {
                hr = 24;
                if (day == 1) {
                    if (mn != 1) {
                        day = MonthDays(yr, mn - 1);
                        mn--;
                    } else {
                        day = 31;
                        mn = 12;
                        yr--;
                    }
                } else
                    day--;
            }
            hr--;
        }
        return *this;
    }


    int inputTime(int _timestamp) {
        hr = _timestamp % 100;
        _timestamp /= 100;
        day = _timestamp % 100;
        _timestamp /= 100;
        mn = _timestamp % 100;
        _timestamp /= 100;
        yr = _timestamp + 2000;
        return EXIT_SUCCESS;
    }

    int timeStamp() const {
        return hr + day * 100 + mn * 10000 + (yr % 100) * 1000000;
    }

    void incre(int h) {
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
        }
    }

    void pause();

    void recover();

    string toString();
};


// ????
class Clock {
    //todo

public:
    int repeat{};
    Time time{};

    int getRepeat() const {
        return repeat;
    }

    void setRepeat(int rep) {
        Clock::repeat = rep;
    }

    const Time &getTime() const {
        return time;
    }

    void setTime(Time t) {
        Clock::time = t;
    }

    const char* toString(){
        return "todo";
    }
};

class OurStr
{
    public:
    /**
     * @brief 字符串比较函数
     * 
     * @param s1 
     * @param s2 
     * @return int -1时s1<s2,0时字符串相等,1时s1>s2
     */
        static int StrCmp(string s1, string s2)
        {
            int len = min(s1.length(), s2.length()), i;
            for(i = 0; i < len && s1[i] == s2[i]; i++);
            if(i == len)
            {
                if(s1.length() < s2.length()) return -1;
                else if(s1.length() > s2.length()) return 1;
                return 0;
            }
            if(s1[i] < s2[i]) return -1;
            return 1;
        }
};

#endif
