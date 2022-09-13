/*
 * @Author: quxinsc 2224721143quxin@gmail.com
 * @Date: 2022-09-13 13:22:25
 * @LastEditors: quxinsc 2224721143quxin@gmail.com
 * @LastEditTime: 2022-09-13 14:48:13
 * @FilePath: \Code\header\stock00.h
 * @Description: 
 * 
 * Copyright (c) 2022 by quxinsc 2224721143quxin@gmail.com, All Rights Reserved. 
 */
// stock00.h -- Stock class interface
// version 00
#ifndef STOCK00_H_
#define STOCK00_H_

#include <string>  

class Stock  // class declaration
{
private: 
    std::string company;
    long shares;
    double share_val;
    double total_val;
    void set_tot();
    //定义位于类声明中的函数都将自动成为内联函数，因此 Stock::set_tot( )是一个内联函数
public:
    void acquire(const std::string & co, long n, double pr);
    void buy(long num, double price);
    void sell(long num, double price);
    void update(double price);
    void show();
};    // note semicolon at the end
inline void Stock::set_tot()
{
    total_val=shares*share_val;
}
#endif