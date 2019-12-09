#include <iostream>
#include"HW03_1.h"
#include <cmath>
const double PI = 3.1415926;
using namespace std;
//class Point���w�q
Point::Point()											//�w�]�غc�l 
{
	x = 0.0;
	y = 0.0;
	z = 0.0;
}
Point::Point(double x1, double y1,double z1)						//�غc�l
{
	x = x1;
	y = y1;
	z = z1;
}
Point::Point(const Point & p)							//�ƻs�غc�l
{
	x = p.x;
	y = p.y;
	z = p.z;
}
Point Point::operator+(const Point&p) //+ operator
{
	return Point(x + p.x, y+p.y,z+p.z);
}
Point Point::operator-(const Point&p) //- operator
{
	return Point(x - p.x, y - p.y, z - p.z);
}
Point & Point::operator=(const Point & p)				//���w�B��l
{
	if (*this == p)
		return*this;
	x = p.x;
	y = p.y;
	z = p.z;
	return *this;
}
bool Point::operator == (const Point & p)
{
	if (x == p.x&&y == p.y&&z==p.z)
		return true;
	else
		return false;
}
void Point::Set_data(double x1, double y1,double z1)
{
	x = x1;
	y = y1;
	z = z1;
}
ostream & operator<<(ostream & os, const Point & p) 
{
	os << "(" << p.x << "," << p.y << ","<<p.z<<")"<<endl;
	return os;
}
//class Pyramid���w�q
Pyramid::Pyramid()									//�w�]�غc�l 
{
	//��l�ƥ|���I����(0,0)
	vertices = new Point[4];
}
Pyramid::Pyramid(Point ori, Point x_axis, Point y_axis, Point z_axis)	//parametered constructor
{
	/*
		pyramid���c:
		0~3�ӥN���P���I
		���T�T�Φ��@�ӤT����
	*/
	vertices = new Point[4];
	vertices[0] = ori;
	vertices[1] = x_axis;
	vertices[2] = y_axis;
	vertices[3] = z_axis;
}
Pyramid::~Pyramid()									//�Ѻc�l
{
	delete[] vertices;
}
Pyramid::Pyramid(const Pyramid	& pr)				//�ƻs�غc�l
{
	vertices = new Point[4];
	for (int i = 0; i < 4; i++)
		vertices[i] = pr.vertices[i];
}
bool Pyramid::operator==(const Pyramid	& pr)		//����O�_�۵�
{
	for (int i = 0; i < 4; i++)
		if (!(vertices[i] == pr.vertices[i]))
			return false;
	return true;
}
Pyramid & Pyramid::operator=(const Pyramid	& pr)	//���w�B��l
{
	if (*this == pr)
		return *this;
	delete[] vertices;
	vertices = new Point[4];
	for (int i = 0; i < 4; i++)
		vertices[i] = pr.vertices[i];
}
Point & Pyramid::Center() const
{
	Point *center=new Point;
	double xsum = 0.0;
	double ysum = 0.0;
	double zsum = 0.0;
	for (int i = 0; i < 4; i++)
	{
		xsum += vertices[i].get_x();
		ysum += vertices[i].get_y();
		zsum += vertices[i].get_z();
	}
	xsum /= 4;
	ysum /= 4;
	zsum /= 4;
	center->Set_data(xsum, ysum,zsum);
	return *center;
}
double Pyramid::Area() const
{
	double area = 0.0;
	//by ���s����
	for(int i=0;i<2;i++)
		for(int j=i+1;j<3;j++)
			for (int k = j + 1; k < 4; k++) 
			{
				double a = 
				sqrt(
						pow(vertices[i].get_x() - vertices[j].get_x(), 2) +
						pow(vertices[i].get_y() - vertices[j].get_y(), 2) +
						pow(vertices[i].get_z() - vertices[j].get_z(), 2)
					);
				double b = 
				sqrt(
						pow(vertices[i].get_x() - vertices[k].get_x(), 2) +
						pow(vertices[i].get_y() - vertices[k].get_y(), 2) +
						pow(vertices[i].get_z() - vertices[k].get_z(), 2)
					);
				double c = 
				sqrt(
						pow(vertices[j].get_x() - vertices[k].get_x(), 2) +
						pow(vertices[j].get_y() - vertices[k].get_y(), 2) +
						pow(vertices[j].get_z() - vertices[k].get_z(), 2)
					);
				double s = 0.5*(a + b + c);
				area+= sqrt(s*(s - a)*(s - b)*(s - c));
			}
	return area;

}
double Pyramid::Perimeter() const
{
	double perimeter = 0.0;
	for(int i=0;i<3;i++)
		for (int j = i + 1; j < 4; j++)
		{
			perimeter +=																	
				sqrt(	
						pow(vertices[i].get_x() - vertices[j].get_x(), 2) + 
						pow(vertices[i].get_y() - vertices[j].get_y(), 2) + 
						pow(vertices[i].get_z() - vertices[j].get_z(), 2)
					);
		}
	return perimeter;
}
double Pyramid::Volume() const
{
	double vol = 0.0;
	//�Q�Φ�C���D�T���W��n
	//�T���@��n=1/3���T���W��n
	double arr[3][3];
	//arr[0]��V1-V0���V�q
	arr[0][0] = vertices[1].get_x()-vertices[0].get_x(); 
	arr[0][1] = vertices[1].get_y()-vertices[0].get_y();
	arr[0][2] = vertices[1].get_z()-vertices[0].get_z();
	//arr[1]��V2-V0���V�q
	arr[1][0] = vertices[2].get_x()- vertices[0].get_x();
	arr[1][1] = vertices[2].get_y()- vertices[0].get_y();
	arr[1][2] = vertices[2].get_z()- vertices[0].get_z();
	//arr[2]��V3-V0���V�q
	arr[2][0] = vertices[3].get_x()- vertices[0].get_x();
	arr[2][1] = vertices[3].get_y()- vertices[0].get_y();
	arr[2][2] = vertices[3].get_z()- vertices[0].get_z();
	/*
		arr=
				x			y			z
		v1-v0	arr[0][0]	arr[0][1]	arr[0][2]
		v2-v0	arr[1][0]	arr[1][1]	arr[1][2]
		v3-v0	arr[2][0]	arr[2][1]	arr[2][2]

		��T����C��:
		sum1=a[0][2]*a[1][0]*a[2][1]+a[0][1]*a[1][2]*a[2][0]+a[0][0]*a[1][1]*a[2][2];

		sum2=a[2][2]*a[0][1]*a[1][0]+a[2][1]*a[1][2]*a[0][0]+a[0][2]*a[1][1]*a[2][0];

		sum=sum1-sum2;
	*/
	double sum1 = arr[0][2] * arr[1][0] * arr[2][1] + arr[0][1] * arr[1][2] * arr[2][0] + arr[0][0] * arr[1][1] * arr[2][2];
	double sum2 = arr[2][2] * arr[0][1] * arr[1][0] + arr[2][1] * arr[1][2] * arr[0][0] + arr[0][2] * arr[1][1] * arr[2][0];
	//sum1-sum2�O����6������n /2�ܦ��T���W��n �A/3�ܤT���@��n �ҥH�`�@/6
	vol = abs(sum1 - sum2) / 6;
	return vol;
}
ostream & operator<<(ostream & os, const Pyramid & py)
{
	os << "4 points of Pyramid:" << endl;
	for (int i = 0; i < 4; i++)
		os << "point" << i << ":" << py.vertices[i];
	os << "Center:" << py.Center();
	os << "Area:" << py.Area() << endl;
	os << "Perimeter:" << py.Perimeter() << endl;
	os << "Volume:" << py.Volume() << endl;
	return os;
}

//������Cuboid���w�q
Cuboid::Cuboid()									//�w�]�غc�l 
{
	//��l�ƥ|���I����(0,0)
	vertices = new Point[8];
}
Cuboid::Cuboid(Point ori, Point x_axis, Point y_axis, Point z_axis)	//parametered constructor
{
	/*
		�����鵲�c:
			3---------------5
		   /|			  /	|
		0---|-----------1	|				
		|	7-----------|---4
		| /				| /
		2---------------6

	*/
	vertices = new Point[8];
	vertices[0] = ori;
	vertices[1] = x_axis;
	vertices[2] = y_axis;
	vertices[3] = z_axis;
	vertices[6] = vertices[1] + vertices[2] - vertices[0];
	vertices[7] = vertices[3] + vertices[2] - vertices[0];
	vertices[4] = vertices[7] + vertices[1] - vertices[0];
	vertices[5] = vertices[3] + vertices[1] - vertices[0];
}
Cuboid::~Cuboid()									//�Ѻc�l
{
	delete[] vertices;
}
Cuboid::Cuboid(const Cuboid	& cub)					//�ƻs�غc�l
{
	vertices = new Point[8];
	for (int i = 0; i < 8; i++)
		vertices[i] = cub.vertices[i];
}
bool Cuboid::operator==(const Cuboid & cub)			//����O�_�۵�
{
	for (int i = 0; i < 8; i++)
		if (!(vertices[i] == cub.vertices[i]))
			return false;
	return true;
}
Cuboid & Cuboid::operator=(const Cuboid	& cub)		//���w�B��l
{
	if (*this == cub)
		return *this;
	delete[] vertices;
	vertices = new Point[8];
	for (int i = 0; i < 8; i++)
		vertices[i] = cub.vertices[i];
}
double* Cuboid::SideLength() const
{
	double *sl = new double[3];
	sl[0]= 
	sqrt(
			pow(vertices[0].get_x() - vertices[1].get_x(), 2) +
			pow(vertices[0].get_y() - vertices[1].get_y(), 2) +
			pow(vertices[0].get_z() - vertices[1].get_z(), 2)
		);
	sl[1] =
		sqrt(
			pow(vertices[0].get_x() - vertices[2].get_x(), 2) +
			pow(vertices[0].get_y() - vertices[2].get_y(), 2) +
			pow(vertices[0].get_z() - vertices[2].get_z(), 2)
		);
	sl[2] =
		sqrt(
			pow(vertices[0].get_x() - vertices[3].get_x(), 2) +
			pow(vertices[0].get_y() - vertices[3].get_y(), 2) +
			pow(vertices[0].get_z() - vertices[3].get_z(), 2)
		);
	return sl;
}
double* Cuboid::SideArea()const
{
	double *sa = new double[3];
	sa[0] =
		sqrt(
			pow(vertices[0].get_x() - vertices[1].get_x(), 2) +
			pow(vertices[0].get_y() - vertices[1].get_y(), 2) +
			pow(vertices[0].get_z() - vertices[1].get_z(), 2)
		)
		*
		sqrt(
			pow(vertices[0].get_x() - vertices[2].get_x(), 2) +
			pow(vertices[0].get_y() - vertices[2].get_y(), 2) +
			pow(vertices[0].get_z() - vertices[2].get_z(), 2)
		)
		;
	sa[1] =
		sqrt(
			pow(vertices[0].get_x() - vertices[1].get_x(), 2) +
			pow(vertices[0].get_y() - vertices[1].get_y(), 2) +
			pow(vertices[0].get_z() - vertices[1].get_z(), 2)
		)
		*
		sqrt(
			pow(vertices[0].get_x() - vertices[3].get_x(), 2) +
			pow(vertices[0].get_y() - vertices[3].get_y(), 2) +
			pow(vertices[0].get_z() - vertices[3].get_z(), 2)
		);
	sa[2] =
		sqrt(
			pow(vertices[0].get_x() - vertices[2].get_x(), 2) +
			pow(vertices[0].get_y() - vertices[2].get_y(), 2) +
			pow(vertices[0].get_z() - vertices[2].get_z(), 2)
		)
		*
		sqrt(
			pow(vertices[0].get_x() - vertices[3].get_x(), 2) +
			pow(vertices[0].get_y() - vertices[3].get_y(), 2) +
			pow(vertices[0].get_z() - vertices[3].get_z(), 2)
		);
	return sa;
}
double Cuboid::Area() const
{
	double *sidearea = SideArea();
	return (sidearea[0] + sidearea[1] + sidearea[2]) * 3;
}
double Cuboid::Perimeter()const
{
	double *sidelength = SideLength();
	return (sidelength[0] + sidelength[1] + sidelength[2]) * 3;
}
double Cuboid::Volume()const
{
	double *sidelength = SideLength();
	return (sidelength[0] * sidelength[1] * sidelength[2]);
}
ostream & operator<<(ostream & os, const Cuboid & cu)
{
	os << "\n8 points of Cuboid:" << endl;
	for (int i = 0; i < 8; i++)
		os << "point"<<i<<":"<<cu.vertices[i];
	os << "Area:" << cu.Area()<<endl;
	os << "Perimeter:" << cu.Perimeter()<<endl;
	os << "Volume:" << cu.Volume()<<endl;
	return os;
}

//��W��Cylinder���w�q
Cylinder::Cylinder() 
{
	Top.Set_data(0.0, 0.0, 0.0);
	Bottom.Set_data(0.0, 0.0, 0.0);
	r = 0.0;
}
Cylinder::Cylinder(Point top, Point bot,double radius)	//parametered constructor
{
	Top = top;
	Bottom = bot;
	r = radius;
}
Cylinder::Cylinder(const Cylinder & cy)
{
	Top = cy.Top;
	Bottom = cy.Bottom;
	r = cy.r;
}
bool Cylinder::operator==(const Cylinder & cy)
{
	if (Top==cy.Top && Bottom==cy.Bottom && r==cy.r)
		return true;
	else
		return false;
}
Cylinder& Cylinder::operator=(const Cylinder & cy)
{
	if (*this == cy)
		return *this;
	Top = cy.Top;
	Bottom = cy.Bottom;
	r = cy.r;
	return *this;
}
double Cylinder::Height() const
{
	return 
	sqrt(
		pow(Top.get_x() - Bottom.get_x(), 2) +
		pow(Top.get_y() - Bottom.get_y(), 2) +
		pow(Top.get_z() - Bottom.get_z(), 2)
	);
}
double Cylinder::BottomArea() const
{
	return PI * r*r;
}
double Cylinder::SideArea()const
{
	return Height() *Perimeter();
}
double Cylinder::Area() const
{
	return BottomArea() * 2 + SideArea();

}
double Cylinder::Perimeter() const//��W�P��=�������P��
{
	return 2 * PI*r;
}
double Cylinder::Volume() const
{
	return Height()*BottomArea();
}
ostream & operator<<(ostream & os, const Cylinder & cy)
{
	os << "Cylinder data:" << endl;
	os << "Top plate center:" << cy.Top;
	os << "Bottom plate center:" << cy.Bottom;
	os << "Radius:" << cy.r << endl;
	os << "Height:" << cy.Height() << endl;
	os << "BottomArea:" << cy.BottomArea() << endl;
	os << "SideArea:" << cy.SideArea() << endl;
	os << "Area:" << cy.Area() << endl;
	os << "Perimeter:" << cy.Perimeter() << endl;
	os << "Volume:" << cy.Volume() << endl;
	return os;
}