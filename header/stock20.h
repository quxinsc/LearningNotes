// stock20.h -- augmented version
#ifndef STOCK20_H_
#define STOCK20_H_
#include <string>

class Stock
{
private:
    std::string company;
    int shares;
    double share_val;
    double total_val;
    void set_tot(){ total_val = shares * share_val; }//内联函数
public:
    Stock();        // default constructor
    Stock(const std::string & co, long n = 0, double pr = 0.0);
    ~Stock();       // do-nothing destructor
    void buy(long num, double price);
    void sell(long num, double price);
    void update(double price);
    //不修改调用对象，就应将其声明为const成员函数
    void show()const;
    const Stock & topval(const Stock & s) const;//声明一个参数类型为【常量引用】的函数，返回类型为【常量引用】，结尾const防止【被隐式调用的对象】被修改
};


#endif
