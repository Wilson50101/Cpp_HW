//學號:P76081108
//useHW01_02.cpp : 
#include "pch.h"
#include "HW01_02.h"
#include <math.h>
#include <iostream>
#include <cstring>
int main()
{
	using namespace std;
	using namespace MyGeometry;
	//#1設定x=3,y=4做測試
	Point p = { 3.0,4.0 };

	//#2
	cout << "\n#2:\n原點(0,0)到(" << p.x << "," << p.y << ")距離為:" << p.Length() << endl;

	//#3
	cout << "\n#3:\nCoutPoint()內容如下:" << p.CoutPoint() << endl;

	//#4
	unsigned int nPoint = 0;							//紀錄讀檔讀到的點數
	Point*rdata = LoadPoint("C:\\Users\\HSNL\\source\\repos\\P76081108\\HW01_02\\Point_HW1.txt", nPoint);
	cout << "\n#4:\n讀入" << nPoint << "個點" << endl;
	cout << "讀入data如下:" << endl;
	for (int i = 0; i < nPoint; i++)
		cout << "Point" << i + 1 << ":" << "(" << rdata[i].x << "," << rdata[i].y << ")" << endl;
	//#5
	float mindis = 0.0;
	Point MDPL = MinDistance(rdata, nPoint, mindis, 1/*x的係數*/, 1/*y的係數*/, -1/*常數項*/);	//求#4讀入的各點中距離x+y=1最近的點為何
	cout << "\n#5:\n與x+y-1=0最近的點為:(" << MDPL.x << "," << MDPL.y << ")" << endl;
	cout << "其之間距離為:" << mindis << endl;
	
	//#6
	cout << "\n#6:\n將點陣列依各點與原點距離由大到小排序後結果如下:" << endl;
	SortbyLength(rdata,nPoint);
	for (int i = 0; i < nPoint; i++)
		cout << "Point" << i + 1 << ":" << "(" << rdata[i].x << "," << rdata[i].y << ")\t距離原點:" <<rdata[i].Length()<< endl;

	//#7
	cout << "\n#7:\n將Report寫至C:\\Users\\HSNL\\source\\repos\\P76081108\\HW01_02\\Report_HW1.txt" << endl;
	Report("C:\\Users\\HSNL\\source\\repos\\P76081108\\HW01_02\\Report_HW1.txt", nPoint, MDPL, rdata);
	return 0;
}