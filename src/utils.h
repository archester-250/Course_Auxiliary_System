#ifndef COURSE_AUXILIARY_SYSTEM_UTILS_H
#define COURSE_AUXILIARY_SYSTEM_UTILS_H

#include "activity.h"
#include "student.h"
#include <iostream>
#include <cstdlib>

using namespace std;

class Time {
    int yr, mn, day, hr;

    int timeStamp() const {
        return hr + day * 100 + mn * 10000 + (yr / 100) * 1000000;
    }

    void desc(int h) {//减少h小时
        while (h--) {
            if (hr == 0) {
                hr = 24;
                day--;
                //todo：最后一天 if (day == )
            }
            hr--;
        }
    }

public:
    int inputTime(int timestamp) {
        hr = timestamp % 100;
        timestamp /= 100;
        day = timestamp % 100;
        timestamp /= 100;
        mn = timestamp % 100;
        timestamp /= 100;
        yr = timestamp + 2000;
        return EXIT_SUCCESS;
    }
    
};


class Student;

// 闹钟
class Clock {
    //todo

public:
    int repeat{};
    Time time{};

    int getRepeat() const {
        return repeat;
    }

    void setRepeat(int repeat) {
        Clock::repeat = repeat;
    }

    const Time &getTime() const {
        return time;
    }

    void setTime(const Time &time) {
        Clock::time = time;
    }

};

#endif
