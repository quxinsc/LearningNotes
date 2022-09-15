/*
 * @Author: quxinsc 2224721143quxin@gmail.com
 * @Date: 2022-09-16 01:55:06
 * @LastEditors: quxinsc 2224721143quxin@gmail.com
 * @LastEditTime: 2022-09-16 03:05:22
 * @FilePath: \Code\header\Side.h
 * @Description: 
 * Copyright (c) 2022 by quxinsc 2224721143quxin@gmail.com, All Rights Reserved. 
 */
//Side.h --头文件2
#ifndef SIDE_H_
#define SIDE_H_
class Side
{
    public:
        Side(float a=0,float b=0,float c=0);
        ~Side();
        void Show();
        float SetX();
        float SetY();
        float Area();
    private:
        float _a;
        float _b;
        float _c;
        float _S;
        float _p;
        void C(){_p=_a+_b+_c;}
};

#endif