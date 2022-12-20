/*
 * @Author: quxinsc 2224721143quxin@gmail.com
 * @Date: 2022-09-14 19:09:53
 * @LastEditors: quxinsc 2224721143quxin@gmail.com
 * @LastEditTime: 2022-12-20 16:45:08
 * @FilePath: \Code\booksheet\项目6-策略模式.cpp
 * @Description: 
 * Copyright (c) 2022 by quxinsc 2224721143quxin@gmail.com, All Rights Reserved. 
 */
#include<iostream>
using namespace std;
class Strategy
{
    public:
    virtual string show()=0;
    virtual ~Strategy();//虚析构，先释放子类
};
Strategy::~Strategy()
{

}
class StrategyA:public Strategy
{
    public:
    string show();
};
string StrategyA::show()
{
    return "买一送一";
}
class StrategyB:public Strategy
{
    public:
    string show();
};
string StrategyB::show()
{
    return "买200-50";
}
class StrategyC:public Strategy
{
    public:
    string show();
};
string StrategyC::show()
{
    return "1000换购任意商品";
}

class SaleMan//Context
{
public:
    SaleMan(Strategy* strategy);
    void saleManShow();
    void setStrategy(Strategy* strategy);
private:
    Strategy* strategy;
};
SaleMan::SaleMan(Strategy* strategy)
{
    this->strategy=strategy;
}
void SaleMan::saleManShow()
{
    cout<<strategy->show()<<endl;
}
void SaleMan::setStrategy(Strategy* strategy)
{
    this->strategy=strategy;
}
int main()
{
    SaleMan saleman(new StrategyA); 
    saleman.saleManShow();  
    saleman.setStrategy(new StrategyB);
    saleman.saleManShow();  
    saleman.setStrategy(new StrategyC);
    saleman.saleManShow();  
    cin.get();    
    return 0;
}
