#include<iostream>
using namespace std;
class Rational
{
friend ostream& operator<<(ostream &o,const Rational &other);
friend Rational operator+(const Rational &other1,const Rational &other2);
public:
    Rational(int x,int y=1);
    Rational(int z,int x,int y);
    Rational &operator+=(const Rational &other);
    Rational &operator++();
    Rational operator++(int);
    bool operator<(const Rational &other);
    bool operator==(const Rational &other);
    explicit operator double();//类型转换,只能显式调用
private:
    void Reduct();//约分
    int _n;//numerator分子
    int _d;//denominator分母
};
Rational::operator double()//类型转换
{
    return (double)_n/_d;
}
bool Rational::operator==(const Rational &other)
{
    return (_n==other._n)&&(_d==other._d);
}
bool Rational::operator<(const Rational &other)
{
    return ((float)_n/_d)<((float)other._n/other._d);
}
Rational &Rational::operator++()
{
    _n+=_d;
    return *this;
}
Rational Rational::operator++(int)
{   
    Rational temp(*this);
    _n+=_d;
    return temp;
}
Rational &Rational::operator+=(const Rational &other)
{
    _n=other._n*_d+other._d*_n;
    _d=other._d*_d;
    Reduct();
    return *this;
}
Rational operator+(const Rational &other1,const Rational &other2)
{
   return Rational(other1._n*other2._d+other1._d*other2._n,other1._d*other2._d);//匿名对象
}
ostream& operator<<(ostream &o,const Rational &other)
{   
    if((other._d==1)&&other._n>=0)
    { o<<" ["<<other._n<<']'<<endl;return o;}
    if(other._d==1&&other._n<0)
    { o<<"-["<<-other._n<<']'<<endl;return o;}
    if(other._n>0)
    o<<" ["<<other._n<<'/'<<other._d<<']'<<endl;
    else 
    o<<"-["<<-other._n<<'/'<<other._d<<']'<<endl;
    return o;
}
Rational::Rational(int x,int y):_n(x),_d(y)
{   
     Reduct();
}
Rational::Rational(int z,int x,int y):_d(y)
{
    if(z<0)
    _n=((-z)*y+x)*(-1);
    else
    _n=z*y+x;
    Reduct();
}
void Rational::Reduct()
{
    int x=_n,y=_d,t;
    //辗转相除法：O(n)=log(N)
    while(y!=0)//余数为零退出循环
    {
        t=x%y;//余数
        x=y;//被除数
        y=t;//除数
    }
    _n/=x;
    _d/=x;

    int flag=(_n*_d>0?1:-1);//符号表示在分子上
    _n=flag*abs(_n);
    _d=abs(_d);
}