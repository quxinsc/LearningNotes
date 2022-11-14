/*
 * @Author: quxinsc 2224721143quxin@gmail.com
 * @Date: 2022-11-14 22:39:43
 * @LastEditors: quxinsc 2224721143quxin@gmail.com
 * @LastEditTime: 2022-11-14 22:55:00
 * @FilePath: \Code\booksheet\项目5-所有人发起进攻.cpp
 * @Description: 
 * Copyright (c) 2022 by quxinsc 2224721143quxin@gmail.com, All Rights Reserved. 
 */
#include<time.h>
#include<iostream>
using namespace std;
class Enemy
{
public:
    virtual ~Enemy(){cout<<"敌人消失"<<endl;}
    virtual void Attack(){cout<<"敌人进攻"<<endl;}
};
class Cat:public Enemy
{
public:
    Cat(){cout<<"生成猫"<<endl;}
    ~Cat(){cout<<"猫消失"<<endl;}
    void Attack(){cout<<"猫"<<endl;}
};
class Dog:public Enemy

{
public:
    Dog(){cout<<"生成狗"<<endl;}
    ~Dog(){cout<<"狗消失"<<endl;}
    void Attack()override{cout<<"狗"<<endl;}
};
int main()
{
    srand(time(0));
    const int size=4;
    Enemy *A[size];

    for(int i=0;i<size;++i)
        if(rand()%2==0)
            A[i]=new Cat;
        else
            A[i]=new Dog;
    for(int i=0;i<size;i++)
    A[i]->Attack();
    cin.get();

    for(int i=0;i<size;i++)
        delete A[i];
    return 0;
}