/*
  设计任务十六： 继承与派生机制的应用
*/

#include <iostream>
#include <cmath>//包含很多数学函数的头文件，开根号，求次方等都用上

using namespace std;

const double PI = 3.14159;//const常值常量(后面不能修改)

class Point                      //Point类(基类)，加了成员属性和成员函数的叫派生类
{
public:                          //公有权限，主函数里point类里的对象可以直接访问public里的函数
    Point() {}                   //缺省构造函数，不起任何作用
    void Po(double x_, double y_) //赋值函数，公有权限下的函数可以直接访问私有权限下的成员
    {
        x = x_;
        y = y_;
    }

    double get_x() {              //取x的值
        return x;
    }

    double get_y() {              //取y的值
        return y;
    }

private:
    double x;                    //坐标
    double y;
};                               //注意有分号

class Line : public Point       //Line类(Point类的派生类)，派生类是在基类的基础上再增加成员函数和成员变量
{
private:
    Point p1, p2;              //定义Point对象
public:
    void Li(Point a, Point b)     //赋值函数
    {
        p1 = a;
        p2 = b;
    }

    double length();//长度
    double slope();           //斜率
};

double Line::length()//长度  //同一个类中公有函数可以直接访问私有成员。派生类中要访问基类的私有成员，需要通过基类的公有函数
{
    double dista = p1.get_x() - p2.get_x(), distb = (p1.get_y() - p2.get_y());
    return sqrt(dista * dista + distb * distb);
}   //注意sqrt和pow的参数类型。double sqrt(double x)和double pow(double x,double y)

double Line::slope()            //斜率
{
    if (p1.get_x() == p2.get_x())
        return 0;
    else if (p1.get_y() == p2.get_y())
        return 99999999;//斜率不存在
    else
        return (p1.get_y() - p2.get_y()) / (p1.get_x() - p2.get_x());
}

class Circle : public Point     //Circle类(Point类的派生类)
{
private:
    Point poit;                //定义Point类对象
    double radius;             //半径
public:
    Circle() {}                 //缺省构造函数
    void Ci(Point myp, double r)//赋值函数
    {
        poit = myp;
        radius = r;
    }

    double area();             //面积
    double get_radius()       //取radius的值
    {
        return radius;
    }
};

double Circle::area()         //面积
{
    return PI * radius * radius;
}

class Cylinder : public Circle    //Cylinder类(Circle类的派生类)
{
private:
    Circle cc;                   //定义Circle类对象
    double height;
public:
    void Cy(Circle c1, double h)//赋值函数
    {
        cc = c1;
        height = h;
    }

    double volume()            //体积
    {
        return cc.area() * height;
    }

    double surface_area()     //表面积
    {
        return cc.get_radius() * PI * 2 * height;
    }
};

class Spheroid : public Circle   //Spheroid类(Circle类的派生类)
{
private:
    Circle c;
public:
    void Sp(Circle c2)         //赋值函数
    {
        c = c2;
    }

    double volume()            //体积
    {
        return c.get_radius() * c.get_radius() * c.get_radius() * PI * 4.0 / 3.0;
    }

    double surface_area()      //表面积
    {
        return c.area() * 4.0;
    }
};

char get_a_char();

string getexistline();

double get_an_int(string &input);

//-----主函数-----
int main() {
    double x1, y1, x2, y2, r, h;//分别为坐标、半径、高度
    char c = '0';
    string whole_input_line;
    Point p1, p2;           //定义Point类对象
    Line l1;               //定义Line类对象
    Circle c1;            //定义Circle类对象
    Cylinder cy;          //定义Cylinder类对象
    Spheroid sp;         //定义Spheroid类对象
    cout << "欢迎使用该程序。" << endl;
    while (c != '5') {
        cout << "***************************************" << endl;
        cout << "  主界面" << endl;
        cout << "  该程序具有以下功能：" << endl;
        cout << "* 1.直线类：  计算长度、斜率。" << endl;
        cout << "* 2.圆类：    计算圆面积。" << endl;
        cout << "* 3.圆柱体类：计算圆柱的表面积、体积。" << endl;
        cout << "* 4.球体：    计算球体的表面积、体积。" << endl;
        cout << "* 5.退出该程序。" << endl;
        cout << "***************************************" << endl;
        cout << "请输入你的选择：";
        c = get_a_char();
        cout << endl;
        switch (c) {
            case '1':
                cout << "请分别输入两个点的坐标:" << endl;
                whole_input_line = getexistline();
                x1 = get_an_int(whole_input_line);
                y1 = get_an_int(whole_input_line);
                x2 = get_an_int(whole_input_line);
                y2 = get_an_int(whole_input_line);
                p1.Po(x1, y1);                              // 所有public权限下的成员函数和成员变量都可以这样引用 对象名.变量名
                p2.Po(x2, y2);
                l1.Li(p1, p2);
                cout << "该线段长度：" << l1.length() << endl;
                cout << "      斜率：" << l1.slope() << endl;
                cout << "已返回到主界面。" << endl << endl;
                break;
            case '2':
                cout << "请输入圆心坐标和半径：" << endl;
                whole_input_line = getexistline();
                x1 = get_an_int(whole_input_line);
                y1 = get_an_int(whole_input_line);
                r = get_an_int(whole_input_line);
                p1.Po(x1, y1);
                c1.Ci(p1, r);
                cout << "该圆的面积：" << c1.area() << endl;
                cout << "已返回到主界面。" << endl << endl;
                break;
            case '3':
                cout << "请输入下底圆心坐标、半径：" << endl;
                whole_input_line = getexistline();
                x1 = get_an_int(whole_input_line);
                y1 = get_an_int(whole_input_line);
                r = get_an_int(whole_input_line);
                cout << "请输入圆柱高度：" << endl;
                cin >> h;

                p1.Po(x1, y1);
                c1.Ci(p1, r);
                cy.Cy(c1, h);

                cout << "该圆柱的表面积:" << cy.surface_area() << endl;
                cout << "        体积：" << cy.volume() << endl;
                cout << "已返回到主界面。" << endl << endl;
                break;
            case '4':
                cout << "请输入圆心坐标和半径：" << endl;
                whole_input_line = getexistline();
                x1 = get_an_int(whole_input_line);
                y1 = get_an_int(whole_input_line);
                r = get_an_int(whole_input_line);
                p1.Po(x1, y1);
                c1.Ci(p1, r);
                sp.Sp(c1);
                cout << "该球体的表面积：" << sp.surface_area() << endl;
                cout << "        体积：" << sp.volume() << endl;
                cout << "已返回到主界面。" << endl << endl;
                break;
            case '5':
                cout << "已退出主界面。" << endl;
                break;
            default:
                cout << "输入错误，请重新输入。" << endl;
                cout << "已返回到主界面。" << endl << endl;
                break;
        }
    }
    cout << "谢谢您的使用！" << endl;
    return 0;
}


double get_an_int(string &input) {
    int length = 0, i;
    bool flag = false;
    string target = "";
    for(i=0;i<input.length();i++){
        if(input[i] >= '0' && input[i] <= '9'){
            target = target + input[i];
            length ++;
            flag = true;
        }else if(flag){
            input = input.substr(static_cast<unsigned long>(i), input.length() - i);
            return strtod(target.c_str(), NULL);
        }
    }
    return 0;
}

string getexistline() {
    string m;
    getline(cin,m);
    if(m.empty()){
        getline(cin,m);
    }
    return m;
}

char get_a_char() {
    char ch = 0;
    while(ch < '0' || ch > '9'){ // 排除空行 \r \n, 等对程序的影响
        cin >> ch;
    }
    return ch;
}