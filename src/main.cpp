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
void input();
void writeIn(char * user, char * password);
bool match(char * user, char * password);

int main()
{
    printf("��ӭʹ�ÿγ̸���ϵͳ����ѡ���¼��ʽ\n1��ѧ���û�\t2������Ա\t3��ע��");
    int loginCode;
    scanf("%d", &loginCode);
    printf("�������û���(���ܳ���20λ������һ����ռ2λ):");
    char * user = (char *)malloc(sizeof(char) * 20);
    scanf("%s", user);
    printf("����������(���ܳ���20λ������һ����ռ2λ):");
    char * password = (char *)malloc(sizeof(char) * 20);
    scanf("%s", password);
    if(loginCode != 3 && match(user, password))
    {
        printf("��½�ɹ���");
    }
    else if(loginCode == 3)
    {
        writeIn(user, password);
    }
    delete password;
    delete user;
    return 0;
}
