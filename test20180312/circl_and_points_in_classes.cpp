//
// Created by lugt on 2018/3/26.

/*
 *      圆和点的关系，使用Class来解决。
 *
 *
 */

//

#include <iostream>

#include <iomanip> //必须包含这个头文件
#include <cmath>

using namespace std;


inline double dis(double x1, double x2, double y1, double y2) {
    return sqrt(pow((x1 - x2), 2) + pow((y1 - y2), 2));
}

struct Point {
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


//-----主函数-----

int main_my_answer() {
    //创建一个圆对象和一个点对象
    // cout << setprecision(3);
    double x, y, r;
    double nx, ny;

    cin >> x >> y >> r;

    Point cent(x, y);
    Circle *ccl = new Circle(cent, r);

    cin >> nx >> ny;
    Point np(nx, ny);

    cout << ccl->area() << " " << ccl->length() << endl;
    cout << (ccl->contain(np) ? "yes" : "no") << endl;
    //输出圆是否包含点，包含则输出yes，否则输出no

    return 0;

}


#include<iostream>
#include<cmath>

using namespace std;

class xPoint {
private:
    int x, y;
public:
    xPoint(int x, int y);

    int getx();

    int gety();
};

class xCircle {

private:
    int x, y, r;

public:
    xCircle(int x, int y, int r);

    float getarea();

    float getlenth();

    int iscontain(int, int);

};

xPoint::xPoint(int x1, int y1) : x(x1), y(y1) {}

int xPoint::getx() { return x; }

int xPoint::gety() { return y; }

xCircle::xCircle(int xx, int yy, int rr) : x(xx), y(yy), r(rr) {}

float xCircle::getarea() { return 3.14 * r * r; }

float xCircle::getlenth() { return 2 * 3.14 * r; }

int xCircle::iscontain(int x3, int y3) {
    float dis, n;
    n = (x3 - x) * (x3 - x) + (y3 - y) * (y3 - y);
    dis = sqrt(n);
    if (dis > r) return 1; else return 0;
}

int main_official_answer() {
    int x1, y1, x2, y2, r2;
    cin >> x2 >> y2 >> r2 >> x1 >> y1;
    xPoint sb1(x1, y1);
    xCircle sb2(x2, y2, r2);
    cout << sb2.getarea()
         << " " << sb2.getlenth()
         <<endl;
    if (sb2.iscontain(x1, y1) == 1)
        cout << "no" << endl;
    else
        cout << "yes" <<  endl;
}

