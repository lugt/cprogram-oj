//
// Created by lugt on 2018/5/28.
//

//
// Created by lugt on 2018/3/26.
//

#include <iostream>
using namespace std;

class CFraction{

private:
    int numup;
    int numdown;
    int maxFactor(int nr,int dr);

public:
    CFraction(int numerator, int denominator = 1);
    void print() const;
    CFraction operator+(const CFraction& rv) const;
    CFraction operator-(const CFraction& rv) const;
    CFraction operator*(const CFraction& rv) const;
    CFraction operator/(const CFraction& rv) const;
    CFraction operator-();
    CFraction& operator=(const CFraction& rv);
    bool operator>(const CFraction& rv) const;
    bool operator>=(const CFraction& rv) const;
    bool operator<(const CFraction& rv) const;
    bool operator<=(const CFraction& rv) const;
    bool operator==(const CFraction& rv) const;
    bool operator!=(const CFraction& rv) const;
    void reduceMe();
    void reciprocal();
    ~CFraction();
};


const CFraction operator+(int, const CFraction&);
const CFraction operator-(int, const CFraction&);
const CFraction operator*(int, const CFraction&);
const CFraction operator/(int, const CFraction&);
const bool operator>(int, const CFraction&);
const bool operator>=(int, const CFraction&);
const bool operator<(int, const CFraction&);
const bool operator<=(int, const CFraction&);
const bool operator==(int, const CFraction&);
const bool operator!=(int, const CFraction&);


//============================================================================
// Name        : CFraction.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#define ABS(x) ((x>0)?x:-x)

const CFraction operator+(int x, const CFraction& rv)
{
    return CFraction(x) + rv;
}

const CFraction operator-(int x, const CFraction& rv)
{
    return CFraction(x) - rv;
}

const CFraction operator*(int x, const CFraction& rv)
{
    return CFraction(x) * rv;
}

const CFraction operator/(int x, const CFraction& rv)
{
    return CFraction(x) / rv;
}

const bool operator>(int x, const CFraction& rv)
{
    return CFraction(x) > rv;
}

const bool operator>=(int x, const CFraction& rv)
{
    return CFraction(x) >= rv;
}

const bool operator<(int x, const CFraction& rv)
{
    return CFraction(x) < rv;
}

const bool operator<=(int x, const CFraction& rv)
{
    return CFraction(x) <= rv;
}

const bool operator==(int x, const CFraction& rv)
{
    return CFraction(x) == rv;
}

const bool operator!=(int x, const CFraction& rv)
{
    return CFraction(x) != rv;
}

CFraction::CFraction(int numerator, int denominator)
{
    if((numerator>=0 && denominator>0)|| (numerator<=0 && denominator<0))
    {
        this->numup = ABS(numerator);
        this->numdown = ABS(denominator);
    }else{
        this->numup = -ABS(numerator);
        this->numdown = ABS(denominator);
    }

}

CFraction CFraction::operator+(const CFraction& rv) const
{
    if(this->numup == 0){
        CFraction a = CFraction(rv.numup,rv.numdown);
        a.reduceMe();
        return a;
    }
    if(rv.numup == 0){
        CFraction a = CFraction(numup,numdown);
        a.reduceMe();
        return a;
    }
    CFraction a = CFraction(numup*rv.numdown + rv.numup*numdown, numdown*rv.numdown);
    a.reduceMe();
    return a;
}

CFraction CFraction::operator-(const CFraction& rv) const
{

    if(rv.numdown == 0 || this->numdown == 0){
        return CFraction(0,0);
    }

    if(rv.numup == 0){
        return CFraction(this->numup, this->numdown);
    }

    if(this->numup == 0){
        return CFraction(rv.numup, rv.numdown);
    }

    CFraction a = CFraction(numup*rv.numdown - rv.numup*numdown, numdown*rv.numdown);
    a.reduceMe();
    return a;
}

CFraction CFraction::operator*(const CFraction& rv) const
{
    if(rv.numdown == 0 || this->numdown == 0){
        return CFraction(0,0);
    }

    if(rv.numup == 0){
        return CFraction(0,1);
    }

    if(this->numup == 0){
        return CFraction(0,1);
    }

    CFraction a = CFraction(numup * rv.numup, numdown * rv.numdown);
    a.reduceMe();
    return a;
}

CFraction CFraction::operator/(const CFraction& rv) const
{
    if(rv.numdown == 0 || this->numdown == 0){
        return CFraction(0,0);
    }

    if(rv.numup == 0){
        return CFraction(0,0);
    }

    if(this->numup == 0){
        return CFraction(0,1);
    }

    CFraction a = CFraction(numup * rv.numdown, numdown * rv.numup);
    a.reduceMe();
    return a;
}

CFraction CFraction::operator-()
{
    numup = -numup;
    return *this;
}

CFraction& CFraction::operator=(const CFraction& rv)
{
    numup=rv.numup;
    numdown=rv.numdown;
    return *this;
}

bool CFraction::operator>(const CFraction& rv) const
{
    if(numup*rv.numdown > rv.numup*numdown)
        return true;
    else
        return false;
}

bool CFraction::operator>=(const CFraction& rv) const
{
    if(numup*rv.numdown >= rv.numup*numdown)
        return true;
    else
        return false;
}

bool CFraction::operator<(const CFraction& rv) const
{
    if(numup*rv.numdown < rv.numup*numdown)
        return true;
    else
        return false;
}

bool CFraction::operator<=(const CFraction& rv) const
{
    if(numup*rv.numdown <= rv.numup*numdown)
        return true;
    else
        return false;
}

bool CFraction::operator==(const CFraction& rv) const
{
    if(numup*rv.numdown == rv.numup*numdown)
        return true;
    else
        return false;
}

bool CFraction::operator!=(const CFraction& rv) const
{
    if(numup*rv.numdown != rv.numup*numdown)
        return true;
    else
        return false;
}

void CFraction::print() const
{
    cout << "fraction=";
//    if(numdown==1){
//        cout << numup<< endl;
//    }
//    else
    cout << numup << "/" << numdown << endl;
}

int CFraction::maxFactor(int nr,int dr)
{
    int th=nr,tl=dr;
    if(nr<dr)
    {
        th=dr;
        tl=nr;
    }
    if(tl == 0) return 1;
    if(th%tl==0)
        return tl;
    else
        return maxFactor(tl,th%tl);
}

void CFraction::reduceMe()
{
    /*if(numdown == 0) return;

    if(numup == 0){
        numup = 0;
        numdown = 1;
        return;
    }

    int a = maxFactor(ABS(numdown), ABS(numup));
    if(a>1){
        numdown /= a;
        numup /= a;
    }

    if((numup>=0 && numdown>0)|| (numup<=0 && numdown<0))
    {
        numup = ABS(numup);
        numdown = ABS(numdown);
    }else{
        numup = -ABS(numup);
        numdown = ABS(numdown);
    }*/
}

void CFraction::reciprocal()
{
    if(numup>=0)
    {
        int temp = numup;
        numup = numdown;
        numdown = temp;
    }else{
        int temp = numup;
        numup = -numdown;
        numdown = ABS(temp);
    }
}

CFraction::~CFraction()
{
}

int main(){

    int fm, fz;
    cin >> fz >> fm;
    CFraction fc(fz, fm), new_fc(0,0);
    cin >> fz >> fm;
    CFraction fc2(fz, fm);

    new_fc = fc + fc2;
    new_fc.print();

    new_fc = fc - fc2;
    new_fc.print();

    new_fc = fc * fc2;
    new_fc.print();

    new_fc = fc / fc2;
    new_fc.print();
}