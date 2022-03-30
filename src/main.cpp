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
#include "course.h"
#include <cstring>
void input();
void writeIn(char * user, char * password);
bool match(char * user, char * password);

int main()
{
    printf("欢迎使用课程辅助系统！请选择登录方式\n1、学生用户\t2、管理员\t3、注册");
    int loginCode;
    scanf("%d", &loginCode);
    printf("请输入用户名(不能超过20位，中文一个字占2位):");
    char * user = (char *)malloc(sizeof(char) * 20);
    scanf("%s", user);
    printf("请输入密码(不能超过20位，中文一个字占2位):");
    char * password = (char *)malloc(sizeof(char) * 20);
    scanf("%s", password);
    if(loginCode != 3 && match(user, password))
    {
        printf("登陆成功！");
    }
    else if(loginCode == 3)
    {
        writeIn(user, password);
    }
    delete password;
    delete user;
    return 0;
}
