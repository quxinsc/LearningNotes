#include"MyString.h"
#include<cstring>
/**
 * @brief 析构函数
 * @return null
 */
MyString::~MyString()
{

    delete[] _s;
}
/**
 * @brief 构造函数
 * @param *str 字符串
 * @return null
 */
 /**
  * @brief 拷贝构造函数
  * @param other 对象
  * @return null
  */
MyString::MyString(const MyString& other)
{
    _s = new char[strlen(other._s) + 1];
    strcpy(_s, other._s);
}
MyString::MyString(const char* str)
{
    _s = new char[strlen(str) + 1];//分配内存空间
    strcpy(_s, str);//
}
ostream& operator<<(ostream& o, const MyString& other)
{
    o << "\"" << other._s << "\"";//前面加转义字符'\'，输出双引号
    return o;
}
istream& operator>>(istream& i, MyString& other)
{   
    delete []other._s;
    other._s=new char[20];
    i>>other._s;
    return i;
}
MyString MyString::operator++(int)
{
    int len = strlen(_s);
    if (len == 0)  return *this;

    MyString r(_s);//创建新对象
    char* temp = new char[len + 2];
    strcpy(temp, _s);
    temp[len] = _s[len - 1];
    temp[len + 1] = '\0';
    delete[]_s;
    _s = temp;
    return r;//返回值为对象，会调用拷贝构造函数 ，包含指针类型成员，需要自定义拷贝构造函数
}
MyString& MyString::operator++()
{

    int len = strlen(_s);
    if (len == 0)  return *this;

    char* temp = new char[len + 2];//因为要复制一个字符
    temp[0] = _s[0];
    strcpy(temp + 1, _s);
    delete[]_s;
    _s = temp;
    return *this;
}
MyString& MyString::operator+=(const MyString& other)
{
    int len = strlen(_s) + strlen(other._s);
    char* temp = new char[len + 1];//内存分配
    strcpy(temp, _s);
    strcat(temp, other._s);
    delete[]_s;//释放掉原先的字符串
    _s = temp;
    return *this;
}
MyString& MyString::operator-=(const char str)
{
    //个人代码采用整体移动,需要使用strcpy
    for (int i = 0; i < strlen(_s); i++)
    {
        if (*_s == '\0') break;
        while (str == *(_s + i))
            strcpy(_s + i, _s + i + 1);//后面字符串向前移位
    }
    //课堂代码采用逐个移动
    //int src=0;int dst=0;
    //while(src<strlen(_s))
    //{
    // if(_s[src]!=str)
    // _s[dst++]=_s[src];
    // src++;
    //} 
    //_s[dst]=0;
    return *this;
}
MyString& MyString::operator-=(string other)
{
    //这里用STL的string的 find,然后用erase
    string p(_s);
    int m, flag = 0, num = 0;  //num是子串出现的次数
    while (flag == 0)
    {
        m = p.find(other);
        if (m < 0)
            flag = 1;
        else
        {
            p.erase(m,other.size());  //删除子串
            num++;
        }
    }
    strcpy(_s,p.c_str());//将string类型转化为const char *
    return *this;
}
MyString& MyString::operator=(const MyString& other)
{
    delete[]_s;
    _s = new char[strlen(other._s)+1];
    strcpy(_s, other._s);
    return *this;
}