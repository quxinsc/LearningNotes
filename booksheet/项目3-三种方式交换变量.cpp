#include<iostream>
void SwapA(int a,int b);
void SwapB(int &a,int &b);
void SwapC(int *a,int *b);
int main()
{
    int a(1),b(0);
    std::cout<<a<<','<<b<<'\n';

    SwapA(a,b);//值传递
    std::cout<<a<<','<<b<<'\n';

    SwapB(a,b);//引用传递
    std::cout<<a<<','<<b<<'\n';

    SwapC(&a,&b);//指针传递
    std::cout<<a<<','<<b<<'\n';
    
    std::cin.get();
    return 0;
}
void SwapA(int a,int b)
{
//无法在函数内部交换实参的值
}
void SwapB(int &a,int &b)
{
    int temp=a;
    a=b;
    b=temp;
}
void SwapC(int *a,int *b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}