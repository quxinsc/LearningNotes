/*
 * @Author: quxinsc 2224721143quxin@gmail.com
 * @Date: 2022-09-16 02:35:35
 * @LastEditors: quxinsc 2224721143quxin@gmail.com
 * @LastEditTime: 2022-09-16 21:34:20
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
Triangle::Triangle(const Point & pp1,const Point & pp2,const Point & pp3)
{
    index=!index;
    p1=pp1;
    p2=pp2;
    p3=pp3; 
    _a=p1.Set(p2);
    _b=p3.Set(p2);
    _c=p1.Set(p3);
    if(_a+_b>_c&&_b+_c>_a)
    {
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
Triangle::~Triangle()
{

}
float Triangle::Area()
{   
    return sqrt(_p*(_p-_a)*(_p-_b)*(_p-_c));
}
void Triangle::Show()
{   
    using std::cout;
    if(index)
    {
    cout<<"{[";
    p1.Show();
    cout<<"][";
    p2.Show();
    cout<<"][";
    p3.Show();
    cout<<"]}"<<'\n';
    !index;
    }
    else
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
Point::Point(float x,float y)
{
    _x=x;
    _y=y;
}
Point::Point()
{

}
float Point::Set(const Point & s)
{   
    float n,m;
    n=s._x-_x;  
    m=s._y-_y; 
    return sqrt(m*m+n*n);

}
void Point::Show() const
{
    std::cout<<_x<<'.'<<_y;
}
Point::~Point()
{

}
