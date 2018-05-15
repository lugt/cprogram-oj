#include<iostream>
#include<iomanip>
using namespace std;
class Shape
{
	public:
	virtual float printArea() const {return 0.0;};	
};
class Circle:public Shape
{
	public:
	 Circle(float =0);
	 virtual float printArea() const {return 3.14*radius*radius;}	
	protected:
		float radius;
};
Circle::Circle(float r):radius(r)
{
}
class Rectangle:public Shape
{
	public:
		Rectangle(float =0,float =0);
	virtual float printArea() const;
	protected:
		float height;
		float width;
};
Rectangle::Rectangle(float w,float h):width(w),height(h){
}
float Rectangle::printArea()const
{
	return width*height;
}
class Triangle:public Shape
{
	public:
		Triangle(float =0,float =0);
	virtual float printArea() const;
	protected:
		float height;
		float width;
};
Triangle::Triangle(float w,float h):width(w),height(h){
}
float Triangle::printArea()const
{
	return 0.5*width*height;
}

void printArea(const Shape&s)
{
  cout<<fixed<<setprecision(2)<<s.printArea()<<endl;	
}

int main()
{
  int t;
  double dia,dia2;
  cin >> t;
  while(t--){
    cin >> dia;
    Circle circle(dia);
  //cout<<"area of circle=";
    printArea(circle);
    cin>>dia;
    Rectangle rectangle(dia,dia);
  //cout<<"area of rectangle=";
    cin>>dia>>dia2;
    printArea(rectangle);
    Rectangle ce(dia,dia2);
	//	cout<<"area of triangle=";
    printArea(ce);
  }
}
