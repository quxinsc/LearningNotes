/*
 * @Author: quxinsc 2224721143quxin@gmail.com
 * @Date: 2022-09-16 02:35:35
 * @LastEditors: quxinsc 2224721143quxin@gmail.com
 * @LastEditTime: 2022-09-16 03:10:19
 * @FilePath: \Code\class\Side.cpp
 * @Description: 
 * Copyright (c) 2022 by quxinsc 2224721143quxin@gmail.com, All Rights Reserved. 
 */
//Side.cpp --实现文件2
#include <iostream>
#include <math.h>
#include "Side.h"
Side::Side(float a,float b,float c)
{
    if((a+b>c)||(a+c>b))
    {
    _a=a;
    _b=b;
    _c=c;
    }
    else
    {
    _a=0;
    _b=0;
    _c=0;
    }
    C();
    Area();
}
Side::~Side()
{
    
}
float Side::Area()
{   
    return _S=sqrt(_p*(_p-_a)*(_p-_b)*(_p-_c));
}
void Side::Show() 
{   
    std::cout<<"{[0,0]["<<_a<<",0]["<<SetX()<<','<<SetY()<<"]}"<<'\n';
}
float Side::SetX()
{          
    return sqrt(_c*_c-SetY()*SetY());
}
float Side::SetY()
{
    return 2*_S/_a;
}