/**
 * @file main.cpp
 * @author your name (you@domain.com)
 * @brief ������
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
    printf("��ӭʹ�ÿγ̸���ϵͳ����ѡ���¼��ʽ\n1��ѧ���û�\t2������Ա\t3��ע���û�\t4��ע�����Ա");
    int loginCode;
    scanf("%d", &loginCode);getchar();
    char * user = (char *)malloc(sizeof(char) * 21);
    do
    {
        printf("�������û���(���ܳ���20λ������һ����ռ2λ):");
    } while (!inputString(user));
    char * password = (char *)malloc(sizeof(char) * 21);
    do
    {
        printf("����������(���ܳ���20λ������һ����ռ2λ):");
    } while (!inputString(password));
    if((loginCode == 1 || loginCode == 2))
    {
        if(match(user, password, loginCode)) printf("��½�ɹ���\n");
        else printf("��½ʧ�ܣ�\n");
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