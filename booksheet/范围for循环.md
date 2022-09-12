# 基于范围的for循环（C++11）
```cpp
for(变量:对象)
{
//自动确定遍历范围
}
```
```cpp
#include<iostream>
using namespace std;
int main()
{
int v[]={1,2,3,4,5,6};
for (int x:v)
cout<<x<<" ";
cin.get();
}
```
>输出:1 2 3 4 5 6