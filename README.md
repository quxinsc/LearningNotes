
# 🚀面向对象的三大特征
![图层 2.png](https://s2.loli.net/2022/09/14/c5Eam6qMGuV2S1y.png)
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
//常量指针，指向的值不能变<==>const Stock * top   
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

---

## 2.继承

>继承描述的是**父类**和**子类**的关系。通过继承，子类可以扩展父类的功能，从而提高了代码的**可重用性（Reuse）**，降低了代码维护的难度。共同的功能写在父类中；不同的功能写在子类中

## 3.多态
---
<p align="center"><a><u>-----GIT思维导图------</u></a></p>

![iamge](https://s1.328888.xyz/2022/09/14/cLCdE.jpg)