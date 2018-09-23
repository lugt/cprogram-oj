//
// Created by lugt on 2018/3/26.

/*
 *      圆和点的关系，使用Class来解决。
 */

//

#include <iostream>
#include <iomanip>
#include <cmath>

#define L_PI 3.14

using namespace std;


inline double dis(double x1, double x2, double y1, double y2) {
    return sqrt(pow((x1 - x2), 2) + pow((y1 - y2), 2));
}

class Point {
public:
    double x;
    double y;

    Point(double x_, double y_) {
        x = x_;
        y = y_;
    }

    Point() {}
};

class Circle {
public:
    Point poit;
    double radius;

    void center(double i, double i1);

    double area();

    double length();

    bool contain(Point np);

    void setRadius(double radius_);

    void center(Point point);

    Circle(Point myp, double r) {
        poit = myp;
        radius = r;
    }

};

bool Circle::contain(Point np) {
    return dis(poit.x, np.x, poit.y, np.y) <= radius;
}

void Circle::center(double i, double i1) {
    poit.x = i;
    poit.y = i1;
}

void Circle::setRadius(double radius_) {
    radius = abs(radius_);
}

double Circle::length() {
    return abs(2 * 3.14 * radius);
}

double Circle::area() {
    return abs(3.14 * radius * radius);
}

void Circle::center(Point point) {
    this->center(point.x, point.y);
}

class Line{
private:
    Point p1, p2;

public:
    Line(Point &a, Point &b){
        this->p1 = a;
        this->p2 = b;
    }

    double length(){
        dis(p1.x, p2.x, p1.y, p2.y);
    }

    double slope(){
        if(fabs(p1.x - p2.x) <= 0.001){
            //same point;
            return 0;
        }else{
            return (p1.y-p2.y) / (p1.x - p2.x);
        }
    }

};

class D3Shape{
public:
    virtual double volume() const = 0;
    virtual double surface_area() const = 0;
};

class Cylinder: public D3Shape{

    Point bottom_center;
    double radius;
    double height;

public:
    Cylinder(Point a, double r, double h) : height(h),radius(r),bottom_center(a) {

    }

    double volume(){
        return (radius*radius*L_PI) * height;
    };
    double surface_area(){
        return (radius*L_PI*2) * height;
    }
};

class Spheroid : public D3Shape{
private:
    Point center;
    double radius;

public:
    Spheroid(Point &a, double r){
        radius = r;
        center = a;
    }

    double volume(){
        return (radius*radius*radius*L_PI*4.0/3.0);
    };
    double surface_area(){
        return (radius*L_PI*4.0);
    }

};

//-----主函数-----

int main() {
    //创建一个圆对象和一个点对象
    // cout << setprecision(3);
    double x, y, r;
    double nx, ny;

    cin >> x >> y >> r;

    Point cent(x, y);

    Circle *ccl = new Circle(cent, r);

    cin >> nx >> ny;
    Point np(nx, ny);

    cin >> nx >> ny;
    Line l0(np, *new Point(nx,ny));
    cout << l0.length() << endl;
    cout << l0.slope() << endl;

    Cylinder ncy(np,1.0,1.0);
    Spheroid sphere(np,1.0);

    return 0;

}