#include <iostream>
#include <string>
#include <vector>
#include <list>
using namespace  std;
class Date{
    int year, month, day;
public:
    Date();
    Date(int y, int n , int d);
    int getYear();
    int getMonth();
    int getDay();
    void setDate(int y, int m, int d);
    void print();
    void addoneDay();
};

Date::Date()
{
}

Date::Date(int y, int m, int d)
{
    year = y;
    month = m;
    day = d;
}
int Date::getYear()
{
    return year;
}

int Date::getMonth()
{
    return month;
}

int Date::getDay()
{
    return day;
}

void Date::setDate(int y, int m, int d)
{
    year = y;
    month = m;
    day =d;
}
void Date::print()
{
    cout<< year << "/" << month << "/" << day;
}

void Date::addoneDay()
{
    day = day + 1;
    //这里需要判断一下day;
    //大小月、二月、润年这些
    //如果day超出了当前month的日,day就为1,month就加1
    //自己添加这里
}

int main()
{

    int yy, mm , dd, t;
    cin >> t;
    while(t -- ){
        cin >> yy >> mm >> dd;
	Date date(yy, mm, dd);
	cout<< "Today is:";
        date.print();
        date.addoneDay();
        cout<< "Tomorrow is:";
        date.print();
    }
 }