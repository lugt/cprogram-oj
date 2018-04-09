#include<iostream>
using namespace std;
class date
{
private:
    int year,month,day;
public:
    void set(int a,int b,int c);
    int set1();
    int set2();
    int set3();
};
void date::set(int a,int b,int c)
{
    year=a,month=b,day=c;
}
int date::set1()
{
    return year;
}
int date::set2()
{
    return month;
}
int date::set3()
{
    return day;
}

class vip
{
private:
    int id;
    date birth;
public:
    void set1(int a);
    double dis(int x,int y,int b,int c);
    date set2();
    /*vip(vip & r);
    vip();*/
};
void vip::set1(int a)
{
    id=a;
}
date vip::set2()
{
    return birth;
}
/*vip::vip(vip & r)
{
	birth=r.birth;
}*/
double vip::dis(int x,int y,int b,int c)
{
    if(x==b&&y==c)
        return 0.5;
    else
        return 0.95;
}

int main()
{
    vip *p;
    date p1;

    int a,b,c,d,e,f,g,i,j,t;
    double h,x,y;
    cin>>a>>b>>c;
    cin>>t;
    p=new vip[t];

    for(i=0;i<t;i++)
    {
        cin>>d>>e>>f>>g;
        p[i].set2().set(e,f,g);
        p[i].set1(d);
        y=p[i].dis(f,g,b,c);
        cin>>h;
        x=h*y;
        cout<<d<<"'s consumption is "<<int(x)<<endl;
    }
    delete []p;


}