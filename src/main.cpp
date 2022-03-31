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
bool inputString(char * str);
void writeIn(char * user, char * password, int loginCode);
bool match(char * user, char * password, int loginCode);

int main()
{
    printf("欢迎使用课程辅助系统！请选择登录方式\n1、学生用户\t2、管理员\t3、注册用户\t4、注册管理员");
    int loginCode;
    scanf("%d", &loginCode);getchar();
    char * user = (char *)malloc(sizeof(char) * 21);
    do
    {
        printf("请输入用户名(不能超过20位，中文一个字占2位):");
    } while (!inputString(user));
    char * password = (char *)malloc(sizeof(char) * 21);
    do
    {
        printf("请输入密码(不能超过20位，中文一个字占2位):");
    } while (!inputString(password));
    if((loginCode == 1 || loginCode == 2))
    {
        if(match(user, password, loginCode)) printf("登陆成功！\n");
        else printf("登陆失败！\n");
    }
    else if(loginCode == 3 || loginCode == 4)
    {
        writeIn(user, password, loginCode);
    }
    delete password;
    delete user;
    return 0;
}
void writeIn(char * user, char * password, int loginCode)
{
    try
    {
        FILE * fp;
        if(loginCode == 3) fp = fopen("../database/users.data", "a");
        else fp = fopen("../database/administers.data", "a");
        if(fp == NULL) throw 0;
        if(fprintf(fp, "%s,%s\n", user, password) < 0)
        {
            fclose(fp);
            throw 1;
        }
        fclose(fp);
    }
    catch(int error)
    {
        switch (error)
        {
        case 0:
            printf("Not found the file!\n");
            break;

        case 1:
            printf("Write in error!\n");
        
        default:
            break;
        }
    }
}
bool match(char * user, char * password, int loginCode)
{
    try
    {
        FILE * fp;
        if(loginCode == 1) fp = fopen("../database/users.data", "r");
        else fp = fopen("../database/administers.data", "r");
        if(fp == NULL) throw 0;
        char c;int index = 0;
        char * str = (char *)malloc(50 * sizeof(char));
        char * temp = (char *)malloc(50 * sizeof(char));
        for(int i = 0; i < strlen(user); i++)
        {
            str[i] = user[i];
        }
        str[strlen(user)] = ',';
        for(int i = 0; i < strlen(password); i++)
        {
            str[strlen(user) + i + 1] = password[i];
        }
        while (fscanf(fp, "%s", temp) == 1)
        {
            int i;
            for(i = 0; i < strlen(temp) && str[i] == temp[i]; i++);
            if(i == strlen(temp))
            {
                delete temp;
                delete str;
                fclose(fp);
                return true;
            }
        }
        delete temp;
        delete str;
        fclose(fp);
        return false;
    }
    catch(int error)
    {
        switch (error)
        {
        case 0:
            printf("Not found the file!\n");
            return false;
            break;

        default:
            break;
        }
    }
    return false;
}
bool inputString(char * str)
{
    char c;
    int index = 0;
    try
    {
        while((c = getchar()) != '\n')
        {
            if(index == 20) throw 0;
            str[index++] = c;
        }
    }
    catch(int error)
    {
        switch (error)
        {
        case 0:
            printf("The input exceeds the maximum limit!");
            return false;
            break;
        
        default:
            break;
        }
    }
    return true;
}