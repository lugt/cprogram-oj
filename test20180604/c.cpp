#include<iostream>
#include<cstring>
#include<stdlib.h>
using namespace std;

class Point
{
protected:
    int x;
    int y;
    int z;

public:

    Point(int X = 0, int Y = 0, int Z = 0) :x(X), y(Y), z(Z) {}
    friend Point operator ++(Point& a);
    friend Point operator ++(Point&a, int);
    friend Point operator --(Point&);
    friend Point operator --(Point&a, int);

    void show()
    {
        cout << "x=" << x << " " << "y=" << y << " " << "z=" << z << endl;
    }
};

Point operator++(Point& a)
{
    a.x++;
    a.y++;
    a.z++;
    return a;
}

Point operator++(Point& a, int)
{
    Point temp(a);
    a.x++;
    a.y++;
    a.z++;
    return temp;
}

Point operator--(Point& a)
{
    a.x--;
    a.y--;
    a.z--;
    return a;
}

Point operator--(Point&a, int)
{
    Point temp(a);
    a.x--;
    a.y--;
    a.z--;
    return temp;
}

int main()
{
    int a, b, c;
    cin >> a >> b >> c;
    Point p1(a,b,c);

    (++p1).show();

    Point p2(p1);
    (--p2).show();
    (++p2).show();
    p2.show();

    --p2;
    (--p2).show();

    ++p2;
    p2.show();

    (--p2).show();
    p2.show();

    //getchar();
    return 0;
}