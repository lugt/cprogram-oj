#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <iomanip>

using namespace  std;

static int simple_year[] = {31,28,31,30,31,30,31,31,30,31,30,31};
static int special_year[] = {31,29,31,30,31,30,31,31,30,31,30,31};
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
    int daysInThisMonth(int year, int month){
        if(isSpecialYear(year)){
            return special_year[month - 1];
        }else{
            return simple_year[month - 1];
        }
    }
    int isSpecialYear(int year){
        if(year % 100 == 0){
            return (year % 400 == 0) ;
        }else return (year % 4 == 0) ;
    }

    void goNextMonth();
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
    cout ;
    cout<< setfill('0') << year << "/" << setw(2)<<  month << "/" <<setw(2)<<  day << endl;
}

void Date::addoneDay()
{
    day = day + 1;
    if(daysInThisMonth(year, month) < day){
        goNextMonth();
        day = 1;
    }
}

void Date::goNextMonth(){
    if(month == 12){
        year ++;
        month = 1;
    }else{
        month ++;
    }
}

int main()
{

    int yy, mm , dd, t;
    cin >> t;
    while(t -- ){
        cin >> yy >> mm >> dd;
    	Date date(yy, mm, dd);
	    cout<< "Today is ";
        date.print();
        date.addoneDay();
        cout<< "Tomorrow is ";
        date.print();
    }
 }