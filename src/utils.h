#ifndef COURSE_AUXILIARY_SYSTEM_UTILS_H
#define COURSE_AUXILIARY_SYSTEM_UTILS_H

#include <iostream>
#include <cstdlib>

using namespace std;

class Time {
public:
    int yr{}, mn{}, day{}, hr{};
    int timestamp = timeStamp();

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
        return hr + day * 100 + mn * 10000 + (yr / 100) * 1000000;
    }

    void incre(){
        if (hr == 23) {
            hr = 0;
            day++;
            //todo
        } else
            hr++;
    }
};


// 闹钟
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

    void setTime(const Time &t) {
        Clock::time = t;
    }

};

#endif
