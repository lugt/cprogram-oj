//
// Created by lugt on 2018/4/9.

#include <iostream>
#include <iomanip>
#include <iostream>


using namespace std;

class Date
{
public:
    Date(){}

    Date(const Date &d):
            my(d.my),
            mm(d.mm),
            mmd(d.mmd){}

    ~Date(){}

    friend ostream& operator <<(ostream &out,const Date &d);
    int y()const{return my;}
    int m()const{return mm;}


    friend istream& operator >>(istream &in,Date &d);
    Date(int y,int m,int d);

    int d()const{return mmd;}
    void sD(int year, int month, int day);

private:
    int my,mm,mmd;

};


Date::Date(int y,int m,int d):my(y),mm(m),mmd(d) {}

void Date::sD(int year, int month, int day)
{
    this->my = year;
    this->mm = month;
    this->mmd = day;
}



//重载输入输出运算符
ostream& operator <<(ostream &out,const Date &d)
{
    out<< d.y()<<"-"
       << d.m()<<"-"
       << d.d()<<endl;

    return out;
}

istream& operator >>(istream &insj,Date &d)
{
    int yyy,mm,dd;
    insj>>yyy>>mm>>dd;
    d.sD(yyy, mm, dd);
    return insj;
}


class MemberVIP{
public :
    MemberVIP(int id_, Date birth_) : id(id_) , birth(birth_) {} ;

    int id;
    Date birth;
};

int main(int argc, char **argv){
    Date today;
    int t, id, y, m ,d;
    double charge;

    cin >> today;
    cin >> t;
    while(t --){
        cin >> id >> y >> m >> d;
        MemberVIP member(id, * new Date(y,m,d));
        cin >> charge;
        if(member.birth.m() == today.m()
           && member.birth.d() == today.d()){
            charge = 0.5 * charge;
        }else{
            charge = 0.95 * charge;
        }
        cout<<member.id<<"'s consumption is "<<int(charge)<<endl;
    }
    cin >> t;
}