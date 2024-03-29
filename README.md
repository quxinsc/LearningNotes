
# 🚀面向对象的三大特征

>三大特征具有承上启下的关系，而且适用于所有面向对象的编程语言
---
## 1.封装

>将数据（属性）和数据处理过程（行为）封装成一个独立性很强的模块（类）,对外提供接口，不需要让外界知道具体的实现细节

### 1.1类

```cpp
class Student //[定义类的关键字][类名]
{
private： // [成员访问限定符]public,protected,private
    int age;//数据成员
public： // [成员访问限定符]
    void GotoSchool();//成员函数
};//自定义类型要加;号
```

例如

```cpp
class Car 
{
public: 
       void drive(); 
       void stop();                         
private:
       int m_nWheels;
};
```

*成员函数的函数体既可以写在类中，也可以类外实现*

*[类的实现.md](booksheet\类的实现.md)*

### 1.2对象的创建和使用
*对象在栈中分配释放*

>`类名 对象名 [初始值];`  // 如果记不住，就想一想int a = 100
>
>`类名 对象名[(初始值列表)];`
>
>对象名.成员变量
>
>对象名.成员函数(实参列表)

*在堆中创建对象*
>
>`Student* ps = new Student; delete ps;`
>
>指针->成员变量	
>
>指针->成员函数(实参列表)

### 1.3成员函数的简单分类
- [构造函数](booksheet\构造函数.md)和析构函数
构造函数用于对象的`创建和初始化`
析构函数用于`对象的释放`

- 针对成员变量的Set/Get、Add/Del函数
```cpp
    class Student {
    private:
            int age;
    public:
            int GetAge() {return age;}
            void SetAge(int a) //{首先进行参数有效性检查; age = a;}
    }
```
- 其他功能性函数

### 1.4this指针
- this 是C++中的一个关键字，也是一个指针常量，它指向当前对象，通过它可以访问当前对象的所有成员
- this实际上是成员函数的一个隐式的形参，在调用成员函数时将`对象的地址`作为实参传递给 this

>this 只能在成员函数内部使用，用在其他地方没有意义，也是非法的。
this 是指针常量，它的值是不能被修改的，一切企图修改该指针的操作，如赋值、递增、递减等都是不允许的。
只有当对象被创建后 this 才有意义，因此不能在 static 成员函数中使用（后续会讲到 static 成员）。
```cpp
##定义一个成员函数，它查看两个Stock对象 ，并返回股价较高的那个对象的引用
//声明一个参数类型为【常量引用】的函数，返回类型为【常量引用】，结尾const防止【被隐式调用的对象】被修改
const Stock & Stock::topval(const Stock & s) const//括号中的const表明，该函数不会修改被显式地访问的对象--s
{                                               //括号后的const表明，该函数不会修改被隐式地访问的对象--total_val
    if(s.total_val>total_val)                   //返回类型为const引用
        return s;//topval( )中的 total_val只不过是this->total_val的简写
    else
        return *this;//返回的并不是this，因为this是对象的地址，而是对象本身，即*this
}
//常量指针，指向地址的值不能变<==>const Stock * top   
    Stock const * top = &stocks[0];
    for (st = 1; st < STKS; st++)
```
```cpp
       //->指针操作符的优先级非常高，于是&p->a就是&(p->a)     
        top =&top->topval(stocks[st]);
        top = &((*top).topval(stocks[st]));//top->topval(stocks[st])表示调用对象top的成员函数topval(..)，返回一个最大的对象，top->等价于(*top).因为.优先级比*高，所以加括号
```
### 1.5对象数组
`Stock mystuff[4]`创建四个对象，使用默认构造函数初始化
>创建一个对象数组，使用自定义构造函数初始化
```cpp
    Stock stocks[STKS] = {
        Stock("NanoSmart", 12, 20.0),
        Stock("Boffo Objects", 200, 2.0),
        Stock("Monolithic Obelisks", 130, 3.25),
        Stock("Fleep Enterprises", 60, 6.5)
        };
```
### 1.5静态(static)成员变量/函数
- 一个函数的每一次运行都会有一个独立的栈，里面存放了该函数的局部变量。函数运行结束后，栈会被自动释放；而再次调用该函数，会重新分配栈。所以函数的局部变量，在函数的每一次运行都是不同的内存单元。
---
- 为了能够让局部变量保留上一次运行的结果,`静态变量存储在静态区域中，不会因为函数结束而被释放`，所以静态局部变量会保存上一次运行的结果。
```cpp
void fun()
{
    int a=0;
    static int s;//static默认初始化为0
    cout<<++a<<endl;
    cout<<++s<<endl;
}
int main()
{
    fun();
    fun();
}
```
>输出1 1 1 2
- 静态局部变量可以被一个函数的每次调用所“共享”
- 一个类的静态成员变量可以被该类的所有对象所“共享”
```cpp
class Student{
     static int _sum; 
}    //声明表示学生总数的静态成员变量 
.....
int Student::_sum = 0;     //类外初始化静态成员变量_sum 
int main()
{
cout<<"人数是:"<<stu1._sum<<endl;   //通过对象访问静态成员变量 
cout<<"人数是"<<Student::_sum<<endl; //通过类访问静态成员变量 
}
```
- static修饰的静态成员变量只能在类内部定义，在类外部初始化
---
>static成员函数的参数中没有`默认的this指针`,静态成员函数无法调用非static成员
```cpp
class Demo{
	void fun1(){}	// 非静态成员函数
	static void fun2(){
		fun1();		// 错误，静态成员函数访问非静态成员
		x = 100;	// 错误，同上
	}
	int x;
};
```
```cpp
class Point 
{ 
public: 
     const static float getLen(); 
private: 
     const static float area; 
}; 
const float area=3600;

使用static const修饰符组合修饰类成员，既实现了数据共享又达到了数据不被改变的目的。此时，修饰成员函数与修饰普通函数格式一样，修饰成员变量必须在类的内部进行初始化
```
**应用场景1：由于可以通过类名直接调用静态成员，所以`把全局函数转换成某个类的静态成员函数`**
### 1.6关键字修饰类的成员
- const int a;
- static int a;
- int & a;
>都是int类型
>
>都需要初始化，static默认初始化为0
>
>默认的析构函数只能完成栈内存对象的资源清理，无法完成堆内存对象的资源清理
- 在一个`函数中定义了一个对象`，当函数调用结束时，对象应当被释放，对象释放之前编译器会调用析构函数释放资源
- 对于`static修饰的对象和全局对象`，只有在程序结束时编译器才会调用析构函数
- 对于`new`运算符创建的对象，在调用delete释放时，编译器会调用析构函数释放资源
---
### 1.7友元
1. 友元函数不是成员函数
2. 声明可以写在类中任意位置
- ①友元声明位置由程序设计者决定，且不受类中public、private、protected权限控制符的影响。
- ②友元`关系是单向的`，即类A是类B的友元，但B不是A的友元。
- ③友元关系`不具有传递性`，即类C是类D的友元，类E是类C的友元，但类E不是类D的友元。
- ④友元关系`不能被继承`。
#### 1.普通函数作为友元函数
```cpp
 #include<iostream> 
 using namespace std; 
 class Circle 
 { 
 friend void getArea(Circle &circle);    //声明普通函数getArea()为友元函数 
 private: 
     float _radius; 
     const float PI=3.14; 
 public: 
     Circle(float radius); 
     ~Circle(); 
 }; 
 ```
#### 2.其他类的成员函数作为友元函数
```cpp
class B;      //声明类B 
class A 
{ 
public： 
 int func();     //声明成员函数func() 
}; 
class B 
{ 
 friend int A::func();   //声明类A的成员函数func()为友元函数 
} 
```
#### 3.友元类
>声明友元类之后，友元类中的所有成员函数都是该类的友元函数，能够访问该类的所有成员
```cpp
class B；         //类B前向声明 
class A 
{ 
}; 
class B 
{ 
 friend class A；       //声明类A是类B的友元类 
} 
```

## 2.继承

>继承描述的是**基类**和**派生类**的关系。通过继承，派生类可以扩展基类的功能，从而提高了代码的**可重用性（Reuse）**，降低了代码维护的难度。共同的功能写在基类中；不同的功能写在派生类中
### 基本语法
```cpp
class 派生类名:[继承方式]基类名
{
派生类成员声明;
};
class Animal{};
class Fish:public Animal{};//派生类
```
- 基类的构造/析构函数不能被继承；
- 派生类继承基类的全部成员；
- 基类和派生类是多对多的关系
## 3.多态
### 虚函数
- **重载**：静态多态
- **隐藏**：基类派生类有同名函数；参数不同，基类函数都将被隐藏；参数相同，基类不是虚函数
- **覆盖**：动态多态

### 虚函数实现机制
> 虚函数就是通过动态绑定实现多态的，当编译器在编译过程中遇到virtual关键字时，它不会对函数调用进行绑定，而是为包含虚函数的类****建立一张虚函数表Vtable**。在虚函数表中，编译器按照虚函数的声明顺序依次保存虚函数地址。同时，编译器会在类中添加一个隐藏的****虚函数指针VPTR**，指向虚函数表。在创建对象时，将虚函数指针VPTR放置在对象的起始位置，为其分配空间，并调用构造函数将其初始化为虚函数表地址。需要注意的是，****虚函数表不占用对象空间**
---
## **S T L**
>六大组件: 容器、算法、迭代器、仿函数、适配器（配接器）、空间配置器
### 序列容器
```cpp
#include<vector>//容器与动态数组相同，在插入或删除元素时能够自动调整自身大小
#include<deque> //双端队列
#include<list>//双向链表 
#include<array> //大小固定的数组
#include<forward_list>//单向链表
```
### 迭代器iterator
>提供一种方法，使之能够依序寻访某个容器所含的各个元素，而又无需暴露该容器的内部表示方式
```cpp
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int main() {
  vector<int> v = {1, 3, 2, 4, 5};

  // Create an iterator that points to the first element in the vector
  vector<int>::iterator iter = v.begin();
  for(int i=0;i!=v.size();++i)
  cout<<v[i]<<" ";

  cout<<endl;;
  sort(v.begin(),v.end());//快速排序

  for(int i=0;i!=v.size();++i)
  cout<<v[i]<<" ";
  
  cin.get();
  return 0;
}
```
## 模板
### 函数模板
```cpp
 template <typename T1[,typename T2,]...>//返回值类型，函数名
 //class可以作为模板参数的关键字，struct不能
```
函数模板实例化
```cpp
template <typename T>
T Add(T a,T b){return a+b;}
int main()
{
    cout<<Add<int>(2,4)<<endl;
    cout<<Add<double>(1.2,3.4)<<endl;
    cout<<Add(1.2f,3.4f)<<endl;//隐式实例化
  //  cout<<Add('A',32)<<endl;//报错，存在二义性
    cout<<Add<char>('A',32)<<endl;
    cin.get();
}
```
### 类模板
```cpp

template<typename T>class Array;
template<typename T> ostream&operator<<(ostream&o,const Array<T>& other);

template<typename T>
class Array
{//在类模板的内部，声明模板函数为友元
    friend ostream&operator<<<>(ostream&o,const Array<T>& other);
public:
    Array(T a[],int size);
    ~Array();
private:
    T* _ptr;
    int _size;//数组大小
};

template<typename T>
 Array<T>::Array(T a[],int size):_size(size)
 {
 _ptr=new T[_size];
 for(int i=0;i<_size;++i)
 _ptr[i]=a[i];
 }

template<typename T>
Array<T>::~Array()
{
delete[] _ptr;
}

template<typename T>
ostream&operator<<(ostream&o,const Array<T>& other)
{
    for(int i=0;i<other._size;++i)
    o<<other._ptr[i]<<" ";
    return o;
}

int main()
{
    int a[]={1,2,3,4,5,6};
    Array<int> intArr(a,6);
    cout<<intArr<<endl;

    char str[]="hello";
    Array<char> charArr(str,5);
    cout<<charArr<<endl;
    cin.get();
}   

//模板的声明和实现都必须写在cpp文件中
```