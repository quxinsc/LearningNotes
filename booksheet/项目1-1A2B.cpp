/*
 * @Author: quxinsc 2224721143quxin@gmail.com
 * @Date: 2022-09-13 15:57:27
 * @LastEditors: quxinsc 2224721143quxin@gmail.com
 * @LastEditTime: 2022-09-14 12:30:36
 * @FilePath: \Code\booksheet\1A2B.cpp
 * @Description: 
 * 
 * Copyright (c) 2022 by quxinsc 2224721143quxin@gmail.com, All Rights Reserved. 
 */

#include <iostream>
#include <ctime>
#include <string>
#include <algorithm>//算法
using namespace std;

int MainMenu();
void PlayerGuess();
string MakeResult();
string GetAnswer();
bool IsAvailable(string s);
string Compare(string result,string answer);
////////////////////////////////////////Main函数
int main()
{
    srand(unsigned(time(0)));
    MainMenu();
    system("pause");
    return 0;
}
////////////////////////////////////////菜单
int MainMenu()
{
    system("cls");
    cout << "1.电脑出题，玩家猜" << endl;
    cout << "2.玩家出题，电脑猜" << endl;
    cout << "3.排行榜" << endl;
    cout << "0.退出" << endl;
    int choice;
    cout<<"输入你的选择：";
    cin>>choice;
    switch (choice)
    {
    case 1:
        PlayerGuess();system("pause");
        break;
    case 2:
    case 3:
    case 0:
        return 0;
    default:
        cout<<"错误"<<endl;
        break;
    }
    return 1;
}
////////////////////////////////////////输入消息
void PlayerGuess()
{
    string result=MakeResult();
    system("cls");
    cout<<"随机数产生完毕"<<endl;
    cout<<result<<endl;
    int round=0;
    for(;round<15;round++)
    {
        string answer=GetAnswer();    
        if(answer==result)
        {
        cout<<"正确"<<endl;
        break;
        }
        cout<<Compare(result,answer)<<endl;
    }
    if(round==15)
    {
        cout<<"挑战失败！"<<endl;
    }
}
////////////////////////////////////////产生随机数
string MakeResult()
{
    char temp[]="0123456789";
    random_shuffle(temp,temp+10);
    temp[4]='\0';
    return temp;
}
////////////////////////////////////////获取消息
string GetAnswer()
{
    string answer;
    while(1)
    {
        cout<<"输入四位数："<<endl;
        cin>>answer;
        if(answer=="0000")
            exit(0);
        if(IsAvailable(answer))
            break;    
    }
    return answer;
}
////////////////////////////////////////检测消息合法性
bool IsAvailable(string s)
{
    int count[10]={0};
    //是否都为数字
    for(int i=0;i<4;i++)
    {
        if(s[i]<'0'||s[i]>'9')
        {
            cout<<"包含非法字符"<<endl;
            system("pause");
            return false;
        }

        int n=s[i]-'0';//将字符转化为数字
        count[n]++;
        if(count[n]>1)
        {
            cout<<"存在重复字符"<<endl;
             system("pause");
             return false;
        }
    }
    return true;
}
////////////////////////////////////////识别正确个数
string Compare(string result,string answer)
{
        string temp="0A0B";
        int A=0,B=0;
        for(int i=0;i<4;i++)
        {
            for(int j=0;j<4;j++)
            {
                if(result[i]==answer[j])
                {
                    if(i==j)
                    A++;
                    else 
                    B++;
                }
            }
        }
        temp[0]=A+'0';
        temp[2]=B+'0';
        return temp;
}
