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
	bool operator==(const Point&);			//����O�_�۵�
	friend ostream& operator<<(ostream&, const Point&);
};
class IGeometry
{
public:
	virtual double Area() const = 0;
	virtual double Perimeter() const = 0;
	virtual double Volume() const = 0;
};

//�T���@(���r��)
class Pyramid:public IGeometry 
{
private:
	Point* vertices;					//�T���@���|���I
public:
	Pyramid();							//default constructor
	Pyramid(Point ori, Point x_axis, Point y_axis, Point z_axis);	//parametered constructor
	~Pyramid();							//destructor
	Pyramid(const Pyramid&);			//copy constructor
	bool operator==(const Pyramid&);	//����O�_�۵�
	Pyramid & operator=(const Pyramid&);//assignment operator
	Point & Center()const;				//�p��Τ�
	virtual double Area() const;		//overwrite function
	virtual double Perimeter()const;	//overwrite function
	virtual double Volume()const;		//overwrite function
	friend ostream& operator<<(ostream&, const Pyramid&);
};

//������
class Cuboid :public IGeometry
{
private:
	Point* vertices;					//�����骺�K���I
public:
	Cuboid();							//default constructor
	Cuboid(Point ori,Point x_axis,Point y_axis,Point z_axis);	//parametered constructor
	~Cuboid();							//destructor
	Cuboid(const Cuboid&);				//copy constructor
	bool operator==(const Cuboid &);	//����O�_�۵�
	Cuboid & operator=(const Cuboid&);	//assignment operator
	virtual double Area()const;				//overwrite function
	virtual double Perimeter()const;			//overwrite function
	virtual double Volume()const;			//overwrite function
	double*SideLength()const;				//�p��T�����
	double*SideArea()const;					//�p��T�խ��n
	friend ostream& operator<<(ostream&, const Cuboid&);
};
//����W��
class Cylinder :public IGeometry
{
private:
	Point Top;								//����W�骺�W������
	Point Bottom;							//����W�骺�U������
	double r;								//�b�|
public:
	Cylinder();								//default constructor
	Cylinder(Point, Point,double);			//parametered constructor
	~Cylinder(){};							//destructor
	Cylinder(const Cylinder&);				//copy constructor
	bool operator==(const Cylinder&);		//����O�_�۵�
	Cylinder & operator=(const Cylinder&);	//assignment operator
	virtual double Area()const;					//overwrite function
	virtual double Perimeter()const;				//overwrite function
	virtual double Volume()const;				//overwrite function
	double Height()const;						//�p�⪽��W�鰪��
	double BottomArea()const;					//�p�⩳�ꭱ�n
	double SideArea()const;						//�p�ⰼ���u�����n
	friend ostream& operator<<(ostream&, const Cylinder&);
};
#endif