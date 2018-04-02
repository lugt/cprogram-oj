//
// Created by lugt on 2018/4/2.
//

#ifndef TEST20180402_POINT_H
#define TEST20180402_POINT_H


#include<iostream>
#include <iomanip>
#include <cmath>

using namespace std;
class Point
{
private:
    double x,y;
public:
    Point(double x_value, double y_value);
    Point();
    void setx(double x_value);
    void sety(double y_value);
    double GetX();
    double GetY();

    double distanceToAnotherPoint(Point p);
};

Point::Point(double x_value, double y_value):x(x_value),y(y_value) {};
Point::Point():x(0),y(0) {};
void Point::setx(double x_value) {x = x_value;}
void Point::sety(double y_value){y = y_value;}
double Point::GetX() {return x;}
double Point::GetY() {return y;}
double Point::distanceToAnotherPoint(Point p2)
{
    return sqrt((x-p2.GetX())*(x-p2.GetX())+(y-p2.GetY())*(y-p2.GetY()));
}
int main(void)
{
    Point sb1,sb2;
    int t;
    cin>>t;
    while(t--)
    {
        double x_1 , y_1 , x_2 , y_2;
        double distance_value;
        cin>> x_1 >> y_1 >> x_2 >> y_2 ;
        sb1.setx(x_1);
        sb1.sety(y_1);
        sb2.setx(x_2);
        sb2.sety(y_2);
        distance_value = sb1.distanceToAnotherPoint(sb2);
        cout << fixed << setprecision(2);
        cout << "Distance of Point(" << sb1.GetX() << "," << sb1.GetY()<< ") "
           << "to " << "Point(" << sb2.GetX()<< "," << sb2.GetY()<< ") " << "is "
           <<distance_value
           <<endl;
    }
    return 0;
}


#endif //TEST20180402_POINT_H
