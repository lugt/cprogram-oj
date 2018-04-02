#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <iomanip>
#include <cmath>

using namespace  std;

class Point {

    double x,y;
public:
    double getX() const;

    void setX(double x);

    double getY() const;

    void setY(double y);

    Point (){
        x = 0, y = 0;
    }

    Point(double x_, double y_){
        x = (x_);
        y = (y_);
    }

    double ydist(Point * point);

    double xdist(Point * point);

    double distanceToAnotherPoint(Point *p_){
        return sqrt(xdist(p_) * xdist(p_) + ydist(p_) * ydist(p_));
    }

    ~Point(){
        x = y = 0;
        cout << "point clear" << endl;
    }

};

double Point::getX() const {
    return x;
}

void Point::setX(double x) {
    Point::x = x;
}

double Point::getY() const {
    return y;
}

void Point::setY(double y) {
    Point::y = y;
}

double Point::ydist(Point *point) {
    return abs(point->y - y);
}

double Point::xdist(Point *point) {
    return abs(point->x - x);
}

class Circle {

public :
    Point * pts;
    double radius;

    Circle(){
        pts = new Point();
    }

    Circle (double x, double y, double rad){
        pts = new Point(x,y);
        radius = rad;
    }

    ~Circle(){
        delete pts;
        cout << "circle clear"<< endl;
    }


    bool contain(Point *p){
        return p->distanceToAnotherPoint(pts) <= radius;
    }

};

void checkContains(Circle circle, Point *pPoint);

void getPoint(Point * pt){
    int x1,y1;
    cin >> x1 >> y1;
    pt->setX(x1);
    pt->setY(y1);
}

int main()
{

    int n, t;
    //cin >> t;
    Point * pt;
    Point * ptArray;
    //while(t -- ){
    pt = new Point();
    getPoint(pt);
    cin >> n;
    ptArray = new Point[n];
    for (int i = 0; i < n; ++i) {
        getPoint(&ptArray[i]);
    }
    double x0, y0, rad;
    cin >> x0>>y0>>rad;
    Circle cir(x0, y0, rad);
    checkContains(cir, pt);
    for (int i = 0; i < n; ++i) {
        checkContains(cir, &ptArray[i]);
    }
    //}
 }

void checkContains(Circle circle, Point * pPoint) {
    if(circle.contain(pPoint)){
        cout << "in" << endl;
    }else cout << "out" << endl;
}
