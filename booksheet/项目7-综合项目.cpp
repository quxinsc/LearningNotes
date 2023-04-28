#include <string>
#include <fstream>
#include <iostream>
#include <list>
#include <typeinfo>
using namespace std;
class Student
{
public:
    Student(string str);
    ~Student();
    void Study();
    virtual void PE()=0;//纯虚函数
protected:
    string name;

};

class Boy:public Student
{
public:
    Boy(string str);
    void PE();
    void PlayGame();
};
class Girl:public Student
{
public:
    Girl(string str);
    void PE();
    void Shopping();
};
void Student::Study()
{
    cout<<name<<"学习...."<<endl;
}
Student::Student(string str):name(str)
{
}
Student::~Student()
{
}
Boy::Boy(string str):Student(str)
{
}
void Boy::PE()
{
    cout<<name<<"打篮球..."<<endl;
}
void Boy::PlayGame()
{
    cout<<name<<"打游戏..."<<endl;
}
Girl::Girl(string str):Student(str)
{

}
void Girl::PE()
{
    cout<<name<<"打排球..."<<endl;
}
void Girl::Shopping()
{
    cout<<name<<"购物..."<<endl;
}
void operator>>(istream& in,list<Student*>& all)
{
    string type,name;
    in>>type>>name;
    if(type=="男")
        all.push_back(new Boy(name));
    else
        all.push_back(new Girl(name));
    
}
int main() 
{
    list<Student*> allStudents;
    ifstream ifs;
    ifs.open("student.txt",ios::in);//向文件读取信息"男 A...."
    if(!ifs) exit(0);

    while(!ifs.eof())
        ifs>>allStudents;
    ifs.close();

    for(Student* x:allStudents)
    {
        x->Study();
        x->PE();
        //RTTI,运行时类型识别
        if(typeid(*x)==typeid(Boy))
        {
            Boy* boy=dynamic_cast<Boy*>(x);//向下类型转换
            boy->PlayGame();
        }
        else
        {
            Girl* girl=dynamic_cast<Girl*>(x);
            girl->Shopping();
        }
    }
    cin.get();
    return 0;
}
