
==================================头文件
#ifndef PRESIDENT_H_
#define PRESIDENT_H_
class President
{
public:
  static President* GetInstance();//静态成员函数
  void SetName(const char*p);
  const char*GetName();
private:
  President();//构造函数私有化，无法从外部创建对象
  static President* instance;//唯一实例指针
  const char* name;//用const char*代替string,效率更高
};

#endif
====================================实现文件
#include "President.h" 
President *President::instance=nullptr;
President *President::GetInstance()
{
  if(instance==nullptr)
  instance=new President;
  return instance;
}
void President::SetName(const char*p)
{
  name=p;
}
const char* President::GetName()
{
  return name;
}
President::President()
{
  
}
================================主文件
#include <iostream> 
#include "President.h"
using namespace std;
void fun()
{
  President* B=President::GetInstance();
  B->SetName();
}
int main()
{
  President *A=President::GetInstance();
  A->SetName();
  fun();
  cout<<A->GetName();
  //输出结果为B->SetName()的值
  return 0;
}
//单例模式，确保了对象唯一性，任何对象的修改都是针对同一个对象