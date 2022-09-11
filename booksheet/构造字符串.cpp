#include<sstream>
#include<iostream>
using namespace std;
string fun(int a,int b);
int main()
{

    fun(2,4);
    cin.get();
    return 0;
}
string fun(int a,int b)
{
    stringstream ss;//定义字符串流
    ss<<a<<"+"<<b<<"="<<a+b;//ss<<流输出
    return ss.str();//将字符串流转化为字符串
}