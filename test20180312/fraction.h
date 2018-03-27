//
// Created by lugt on 2018/3/26.
//

#include <iostream>
using namespace std;

class fraction{

private:
    int numerator; //定义分子
    int denominator;  //定义分母
    int maxFactor(int nr,int dr);  //求最大公约数

public:
    fraction(int numerator, int denominator = 1);  //构造函数
    void print() const;                            //输出
    fraction operator+(const fraction& rv) const;  //重载 +
    fraction operator-(const fraction& rv) const;  //重载 -
    fraction operator*(const fraction& rv) const;  //重载*
    fraction operator/(const fraction& rv) const;  //重载 /
    fraction operator-();                          //重载单目运算符-
    fraction& operator=(const fraction& rv);       //重载=
    bool operator>(const fraction& rv) const;      //重载>
    bool operator>=(const fraction& rv) const;     //重载>=
    bool operator<(const fraction& rv) const;      //重载<
    bool operator<=(const fraction& rv) const;     //重载<=
    bool operator==(const fraction& rv) const;     //重载==
    bool operator!=(const fraction& rv) const;     //重载!=
    void fractionReduction();                      //约分
    void reciprocal();                             //倒数
    ~fraction();                                   //析构函数
};

//处理当 int 类型在双目运算符左边时的情形，在右边可由编译器自动代入构造函数
const fraction operator+(int, const fraction&);
const fraction operator-(int, const fraction&);
const fraction operator*(int, const fraction&);
const fraction operator/(int, const fraction&);
const bool operator>(int, const fraction&);
const bool operator>=(int, const fraction&);
const bool operator<(int, const fraction&);
const bool operator<=(int, const fraction&);
const bool operator==(int, const fraction&);
const bool operator!=(int, const fraction&);


//============================================================================
// Name        : fraction.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#define ABS(x) ((x>0)?x:-x)

const fraction operator+(int x, const fraction& rv)
{
    return fraction(x) + rv;
}

const fraction operator-(int x, const fraction& rv)
{
    return fraction(x) - rv;
}

const fraction operator*(int x, const fraction& rv)
{
    return fraction(x) * rv;
}

const fraction operator/(int x, const fraction& rv)
{
    return fraction(x) / rv;
}

const bool operator>(int x, const fraction& rv)
{
    return fraction(x) > rv;
}

const bool operator>=(int x, const fraction& rv)
{
    return fraction(x) >= rv;
}

const bool operator<(int x, const fraction& rv)
{
    return fraction(x) < rv;
}

const bool operator<=(int x, const fraction& rv)
{
    return fraction(x) <= rv;
}

const bool operator==(int x, const fraction& rv)
{
    return fraction(x) == rv;
}

const bool operator!=(int x, const fraction& rv)
{
    return fraction(x) != rv;
}

fraction::fraction(int numerator, int denominator)
{
    if((numerator>=0 && denominator>0)|| (numerator<=0 && denominator<0))
    {
        this->numerator = ABS(numerator);
        this->denominator = ABS(denominator);
    }else{
        this->numerator = -ABS(numerator);
        this->denominator = ABS(denominator);
    }

}

fraction fraction::operator+(const fraction& rv) const
{
    fraction a = fraction(numerator*rv.denominator + rv.numerator*denominator, denominator*rv.denominator);
    a.fractionReduction();
    return a;
}

fraction fraction::operator-(const fraction& rv) const
{
    fraction a = fraction(numerator*rv.denominator - rv.numerator*denominator, denominator*rv.denominator);
    a.fractionReduction();
    return a;
}

fraction fraction::operator*(const fraction& rv) const
{
    fraction a = fraction(numerator * rv.numerator, denominator * rv.denominator);
    a.fractionReduction();
    return a;
}

fraction fraction::operator/(const fraction& rv) const
{
    fraction a = fraction(numerator * rv.denominator, denominator * rv.numerator);
    a.fractionReduction();
    return a;
}

fraction fraction::operator-()
{
    numerator = -numerator;
    return *this;
}

fraction& fraction::operator=(const fraction& rv)
{
    numerator=rv.numerator;
    denominator=rv.denominator;
    return *this;
}

bool fraction::operator>(const fraction& rv) const
{
    if(numerator*rv.denominator > rv.numerator*denominator)
        return true;
    else
        return false;
}

bool fraction::operator>=(const fraction& rv) const
{
    if(numerator*rv.denominator >= rv.numerator*denominator)
        return true;
    else
        return false;
}

bool fraction::operator<(const fraction& rv) const
{
    if(numerator*rv.denominator < rv.numerator*denominator)
        return true;
    else
        return false;
}

bool fraction::operator<=(const fraction& rv) const
{
    if(numerator*rv.denominator <= rv.numerator*denominator)
        return true;
    else
        return false;
}

bool fraction::operator==(const fraction& rv) const
{
    if(numerator*rv.denominator == rv.numerator*denominator)
        return true;
    else
        return false;
}

bool fraction::operator!=(const fraction& rv) const
{
    if(numerator*rv.denominator != rv.numerator*denominator)
        return true;
    else
        return false;
}

void fraction::print() const
{
    if(denominator==1){
        cout << numerator<< endl;
    }
    else
        cout << numerator << "/" << denominator << endl;
}

int fraction::maxFactor(int nr,int dr)
{
    int th=nr,tl=dr;
    if(nr<dr)
    {
        th=dr;
        tl=nr;
    }
    if(th%tl==0)
        return tl;
    else
        return maxFactor(tl,th%tl);
}

void fraction::fractionReduction()
{
    int a = maxFactor(ABS(denominator), ABS(numerator));
    if(a>1){
        denominator /= a;
        numerator /= a;
    }

    if((numerator>=0 && denominator>0)|| (numerator<=0 && denominator<0))
    {
        numerator = ABS(numerator);
        denominator = ABS(denominator);
    }else{
        numerator = -ABS(numerator);
        denominator = ABS(denominator);
    }
}

void fraction::reciprocal()
{
    if(numerator>=0)
    {
        int temp = numerator;
        numerator = denominator;
        denominator = temp;
    }else{
        int temp = numerator;
        numerator = -denominator;
        denominator = ABS(temp);
    }
}

fraction::~fraction()
{
}

int main_fraction(){
    fraction new_fc = (1,1);
    int t, fm, fz;
    char nonsense;
    cin >> t;
    while(t--){
        cin >> fz >> nonsense >> fm;
        fraction fc(fz, fm);
        cin >> fz >> nonsense  >> fm;
        fraction fc2(fz, fm);
        new_fc = fc + fc2;
        new_fc.print();

        new_fc = fc - fc2;
        new_fc.print();

        new_fc = fc * fc2;
        new_fc.print();

        new_fc = fc / fc2;
        new_fc.print();
        cout << endl;
    }
}

/*
3
1/2
2/3
3/4
5/8
21/23
8/13
 */