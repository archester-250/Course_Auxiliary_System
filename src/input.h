#ifndef INPUT_H
#define INPUT_H
#include <conio.h>
#include <stdio.h>
#include <string>
using namespace std;

extern Time modtime;

template <typename T> T Input() {
    //输入格式错误抛出异常
    modtime.pause();
    T in;
    cin >> in;
    modtime.recover();
    return in;
}

class input
{
private:
    /* data */
public:
    input(/* args */);
    ~input();
    static int getOperatorNum()
    {
        char op;
        while(!_kbhit());
        op = getch();
        printf("%d\n", op - '0');
        return op - '0';
    }

};

input::input(/* args */)
{
}

input::~input()
{
}

#endif
