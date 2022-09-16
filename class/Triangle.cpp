/*
 * @Author: quxinsc 2224721143quxin@gmail.com
 * @Date: 2022-09-16 02:35:35
 * @LastEditors: quxinsc 2224721143quxin@gmail.com
 * @LastEditTime: 2022-09-16 15:31:47
 * @FilePath: \Code\class\Triangle.cpp
 * @Description: 
 * Copyright (c) 2022 by quxinsc 2224721143quxin@gmail.com, All Rights Reserved. 
 */
//Triangle.cpp --实现文件2
#include <iostream>
#include <math.h>
#include "Triangle.h"
Triangle::Triangle(float a,float b,float c)
{
    _S=0;
    _x=0;
    _y=0;
    if(a+b>c&&b+c>a)
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
    _S=Area();
    SetY();
    SetX();    
}
float Triangle::Area()
{   
    return sqrt(_p*(_p-_a)*(_p-_b)*(_p-_c));
}
void Triangle::Show() const
{   
    using std::cout;
    //using std::ios_base;
    //// set format to #.##
    //ios_base::fmtflags orig =cout.setf(ios_base::fixed, ios_base::floatfield); 
    //std::streamsize prec = cout.precision(2);
    cout<<"{[0,0]["<<_a<<",0]["<<_x<<','<<_y<<"]}"<<'\n';
    
}
void Triangle::SetX()
{       
    if (_S==0)
    _x=0;
    else 
    _x=sqrt(_c*_c-_y*_y);
}
void Triangle::SetY()
{
    if (_S==0)
    _y=0;
    else
    _y=2*_S/_a;
}

//Point::Point(float _x=0,float _y=0)
//{
//    for(int i=0;i<3;i++)
//    {
//    x=_x;
//    y=_y;
//    }   
//}
//Point::~Point()
//{
//
//}
//
//void Point::Set()
//{   
//     float _x,_y,a;
//
//    _x=x-x;  
//    _y=y-y; 
//    a=sqrt(_x*_x+_y*_y);
//
//}
//
