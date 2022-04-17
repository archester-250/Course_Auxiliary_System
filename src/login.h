/**
 * @file login.h
 * @author wxl (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-04-09
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef LOGIN_H
#define LOGIN_H

#include <stdio.h>
#include <iostream>
#include <fstream>
#include <cstring>
#include "hashMap.h"
#include "utils.h"
#include "input.h"

using namespace std;

struct info
{
    int notEnd;
    string user;
    /* data */
};


class login
{
private:
    /* data */
public:
    static info dologin()
    {
        printf("��ӭʹ�ÿγ̸���ϵͳ��(����0�˳���\n");
        printf("��ѡ���¼��ʽ\n1��ѧ���û�\t2������Ա\t3��ע���û�\t4��ע�����Ա\n(����Ҫ��enter��!^_^)");
        info inf;
        input in;
        int loginCode;
        loginCode = in.getOperatorNum();
        if (loginCode == 0)
        {
            inf.notEnd = 0;
            return inf;
        }
        if ((loginCode == 1 || loginCode == 2)) {
            char *user = (char *) malloc(sizeof(char) * 21);
            memset(user, 0, 21);
            do {
                printf("�������û���(���ܳ���20λ������һ����ռ2λ):");
            } while (!inputString(user));
            char *password = (char *) malloc(sizeof(char) * 21);
            memset(password, 0, 21);
            do {
                printf("����������(���ܳ���20λ������һ����ռ2λ):");
            } while (!inputString(password));
            if (match(user, password, loginCode)) 
            {
                printf("��½�ɹ���\n");
                inf.notEnd = loginCode;
                string suser(user);
                inf.user = suser;
                return inf;
            }
            else printf("��½ʧ�ܣ�\n");
            delete password;
            delete user;
        } 
        else if (loginCode == 3 || loginCode == 4) {
            char *user = (char *) malloc(sizeof(char) * 21);
            memset(user, 0, 21);
            do {
                printf("�������û���(���ܳ���20λ������һ����ռ2λ):");
            } while (!inputString(user));
            char *password = (char *) malloc(sizeof(char) * 21);
            memset(password, 0, 21);
            do {
                printf("����������(���ܳ���20λ������һ����ռ2λ):");
            } while (!inputString(password));
            writeIn(user, password, loginCode);
            if(loginCode == 3)
            {
                string userstr(user);
                string cmd = "mkdir ..\\documents\\users\\" + userstr;
                system(cmd.c_str());
                cmd = "cd ..\\documents\\users\\" + userstr + " & echo 0 > " + userstr + ".data";
                system(cmd.c_str());
            }
            delete password;
            delete user;
        }
        inf.notEnd = 5;
        return inf;
    }
    static void writeIn(char * user, char * password, int loginCode)
    {
        try
        {
            if(match(user, password, loginCode) && loginCode == 3) throw 2;
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
                break;
            
            case 2:
                printf("Repetive user's name!\n");
            
            default:
                break;
            }
        }
    }
    static bool match(char * user, char * password, int loginCode)
    {
        try
        {
            
            string s0;
            if(loginCode == 1 || loginCode == 3) s0 = "../database/users.data";
            else s0 = "../database/administers.data";
            ifstream in(s0);
            char c;int index = 0;
            string s1(user);
            string temp;
            if(loginCode == 1 || loginCode == 2)
            {
                string s2(password);
                s1 = s1 + ',' +  s2;
                while (in >> temp)
                {
                    if(!OurStr::StrCmp(s1, temp))
                    {
                        in.close();
                        return true;
                    }
                }
            }
            else
            {
                while (in >> temp)
                {
                    int l;//','����λ��
                    for(l = 0; temp[l] != ','; l++);
                    temp = temp.substr(0, l);
                    if(!OurStr::StrCmp(s1, temp))
                    {
                        in.close();
                        return true;
                    }
                }
                
            }
            in.close();
            return false;
        }
        catch(int error)
        {
            switch (error)
            {
            case 0:
                printf("Not found the file!\n");
                break;

            default:
                break;
            }
        }
        return false;
    }
    static bool inputString(char * str)
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
                printf("The input exceeds the maximum limit!\n");
                while(getchar() != '\n');
                return false;
                break;
            
            default:
                break;
            }
        }
        return true;
    }
};

#endif
