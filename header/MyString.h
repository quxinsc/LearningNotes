#ifndef MYSTRING_H_
#define MYSTRING_H_
#include<iostream>
using namespace std;
class MyString
{
    friend istream& operator>>(istream& i, MyString& other);
    friend ostream& operator<<(ostream& o, const MyString& other);
public:
    MyString(const char* str="");//转换构造函数,默认值为""空字符串，而非nullptr
    MyString(const MyString& other);//拷贝构造函数
    ~MyString();//析构函数
    //引用能提高运行速度，但是不要返回局部变量的引用，++(int)返回的是局部对象
    MyString operator++(int);//复制后面的字符，先相加
    MyString& operator++();//复制前面的字符，先返回
    MyString& operator+=(const MyString& other);//拼接字符串
    MyString& operator-=(string other);//删除字符串
    MyString& operator-=(const char str);//删除字符
    MyString& operator=(const MyString& other);//对象给对象赋值
private:
    char* _s;
};
#endif