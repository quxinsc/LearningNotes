/*
 * @Author: quxinsc 2224721143quxin@gmail.com
 * @Date: 2022-09-13 13:22:25
 * @LastEditors: quxinsc 2224721143quxin@gmail.com
 * @LastEditTime: 2022-09-14 12:29:38
 * @FilePath: \Code\class\stock01.cpp
 * @Description: 
 * 
 * Copyright (c) 2022 by quxinsc 2224721143quxin@gmail.com, All Rights Reserved. 
 */
// stock01.cpp -- revised show() method
#include <iostream>
#include "stock00.h"


void Stock::acquire(const std::string & co, long n, double pr)
{
    company = co;
    if (n < 0)
    {
        std::cerr << "Number of shares can't be negative; "
                  << company << " shares set to 0.\n";
        shares = 0;
    }
    else
        shares = n;
    share_val = pr;
    set_tot();
}

void Stock::buy(long num, double price)
{
     if (num < 0)
    {
        std::cerr << "Number of shares purchased can't be negative. "
             << "Transaction is aborted.\n";
    }
    else
    {
        shares += num;
        share_val = price;
        set_tot();
    }
}

void Stock::sell(long num, double price)
{
    using std::cerr;
    if (num < 0)
    {
        cerr << "Number of shares sold can't be negative. "
             << "Transaction is aborted.\n";
    }
    else if (num > shares)
    {
        cerr << "You can't sell more than you have! "
             << "Transaction is aborted.\n";
    }
    else
    {
        shares -= num;
        share_val = price;
        set_tot();
    }
}

void Stock::update(double price)
{
    share_val = price;
    set_tot();
}

void Stock::show()
{
    using std::cout;
    using std::ios_base;
    ios_base::fmtflags orig;
    //setf( )返回调用它之前有效的所有格式化设置
    //ios_base::fmtflags是存储这种信息所需的数据类型名称
    // set format to #.###
    orig = cout.setf(ios_base::fixed); //将对象置于使用定点表示法的模式---orig储存之前的模式
    int prec = cout.precision(3);//指定显示多少位小数---prec储存之前的精确值

    cout << "Company: " << company
        << "  Shares: " << shares << '\n';
    cout << "  Share Price: $" << share_val;
    // set format to *.**
    cout.precision(2);
    cout << "  Total Worth: $" << total_val << '\n';

    // restore original format
    cout.setf(orig, ios_base::scientific);
    cout.precision(prec);
}
