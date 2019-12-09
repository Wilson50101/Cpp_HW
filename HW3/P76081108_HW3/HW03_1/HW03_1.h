#ifndef HW031_H_
#define HW031_H_
#include<iostream>
#include<cmath>
using namespace std;

class Point
{
private:
	double x;
	double y;
	double z;
public:
	Point();								//default constructor
	Point(double,double,double);			//parametered constructor
	~Point() {};							//destructor
	Point(const Point&);					//copy constructor
	void Set_data(double, double,double);
	double get_x() const{ return x; };
	double get_y() const{ return y; };
	double get_z() const{ return z; };
	Point operator+(const Point&);			//+ operator
	Point operator-(const Point&);			//- operator
	Point & operator=(const Point&);		//assignment operator
	bool operator==(const Point&);			//比較是否相等
	friend ostream& operator<<(ostream&, const Point&);
};
class IGeometry
{
public:
	virtual double Area() const = 0;
	virtual double Perimeter() const = 0;
	virtual double Volume() const = 0;
};

//三角錐(金字塔)
class Pyramid:public IGeometry 
{
private:
	Point* vertices;					//三角錐的四個點
public:
	Pyramid();							//default constructor
	Pyramid(Point ori, Point x_axis, Point y_axis, Point z_axis);	//parametered constructor
	~Pyramid();							//destructor
	Pyramid(const Pyramid&);			//copy constructor
	bool operator==(const Pyramid&);	//比較是否相等
	Pyramid & operator=(const Pyramid&);//assignment operator
	Point & Center()const;				//計算形心
	virtual double Area() const;		//overwrite function
	virtual double Perimeter()const;	//overwrite function
	virtual double Volume()const;		//overwrite function
	friend ostream& operator<<(ostream&, const Pyramid&);
};

//長方體
class Cuboid :public IGeometry
{
private:
	Point* vertices;					//長方體的八個點
public:
	Cuboid();							//default constructor
	Cuboid(Point ori,Point x_axis,Point y_axis,Point z_axis);	//parametered constructor
	~Cuboid();							//destructor
	Cuboid(const Cuboid&);				//copy constructor
	bool operator==(const Cuboid &);	//比較是否相等
	Cuboid & operator=(const Cuboid&);	//assignment operator
	virtual double Area()const;				//overwrite function
	virtual double Perimeter()const;			//overwrite function
	virtual double Volume()const;			//overwrite function
	double*SideLength()const;				//計算三組邊長
	double*SideArea()const;					//計算三組面積
	friend ostream& operator<<(ostream&, const Cuboid&);
};
//直圓柱體
class Cylinder :public IGeometry
{
private:
	Point Top;								//直圓柱體的上底圓圓心
	Point Bottom;							//直圓柱體的下底圓圓心
	double r;								//半徑
public:
	Cylinder();								//default constructor
	Cylinder(Point, Point,double);			//parametered constructor
	~Cylinder(){};							//destructor
	Cylinder(const Cylinder&);				//copy constructor
	bool operator==(const Cylinder&);		//比較是否相等
	Cylinder & operator=(const Cylinder&);	//assignment operator
	virtual double Area()const;					//overwrite function
	virtual double Perimeter()const;				//overwrite function
	virtual double Volume()const;				//overwrite function
	double Height()const;						//計算直圓柱體高度
	double BottomArea()const;					//計算底圓面積
	double SideArea()const;						//計算側面滾輪面積
	friend ostream& operator<<(ostream&, const Cylinder&);
};
#endif