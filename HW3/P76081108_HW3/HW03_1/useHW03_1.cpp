// HW03_1.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
#include <iostream>
#include <cstdlib>     // for rand(), srand()
#include <ctime>       // for time()
#include "HW03_1.h"
#include <cmath>
int main()
{
	srand(time(0));
	Point ori =	Point((double)rand() / 1000, (double)rand() / 1000, (double)rand() / 1000);
	Point px =	Point((double)rand() / 1000, (double)rand() / 1000, (double)rand() / 1000);
	Point py =	Point((double)rand() / 1000, (double)rand() / 1000, (double)rand() / 1000);
	Point pz =	Point((double)rand() / 1000, (double)rand() / 1000, (double)rand() / 1000);

	IGeometry**arr = new IGeometry*[3];
	arr[0] = new Pyramid(ori,px,py,pz);
	cout << *(Pyramid*)arr[0] << endl;

	arr[1] = new Cuboid(ori,px,py,pz);
	cout << *(Cuboid*)arr[1] << endl;
	
	arr[2] = new Cylinder(px,py, (double)rand()/1000);
	cout << *(Cylinder*)arr[2] << endl;

	Pyramid pr = Pyramid(Point(0.0,0.0,0.0), Point(10.0, 0.0, 0.0), Point(0.0, 10.0, 0.0), Point(0.0, 0.0, 10.0));
	cout << "Test Pyramid center:\n" << pr << endl;
	
	cout << "Bye\n";
	cin.get();
	cin.get();
	return 0;
}
