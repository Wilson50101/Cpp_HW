//學號:P76081108
//HW01_02.cpp : 
#include "pch.h"
#include "HW01_02.h"
#include <math.h>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <fstream>
namespace MyGeometry
{
	using namespace std;

	//#2
	double Point::Length()
	{
		return sqrt(x*x + y * y);
	}

	//#3
	string Point::CoutPoint()
	{
		string str = "(" + to_string(x) + "," + to_string(y) + ")";//利用to_string將數字轉成字串
		return str;
	}

	//#4
	Point*LoadPoint(const char *filename, unsigned int &nPoint)
	{
		//const char*filename="C:\\Users\\HSNL\\source\\repos\\P76081108\\HW01_02\\Point_HW1.txt"
		const int n = 2;			//檔案每行2筆data,n直接給值設成常數以後改直接改這行就好
		string Loc = filename;	//檔案路徑
		string Line;			//Line buffer
		string Get = "";		//用來累積儲存字元用
		int Row = 0;			//列數
		int Col = 0;			//行數
		int End = 0;

		//初始化
		float Box[50][n];
		for (int i = 0; i < 50; i++)
		{
			for (int j = 0; j < n; j++)
			{
				Box[i][j] = 0.0;
			}
		}

		//輸入串流(讀檔)
		ifstream infile(Loc.c_str(), ios::in);	//c_str()功能：將String物件轉換成C語言形式的字串常數.
		//如果讀檔成功
		if (infile)
		{
			while (!infile.eof())
			{
				getline(infile, Line);							//一次讀取一列到Line Buffer
				Line = Line + " ";								//"x y\n" 變成->"x y \n"在y後面補空格來統一程式碼58~61行的動作

				for (int i = 0; i < Line.length(); i++)			//對Line Buffer內逐個字元traverse
				{
					if (Line[i] != ' ')							//若不是空白即代表是字元
					{
						Get = Get + Line[i];						//故get收集到下一個空白為止的字元,形成字串
					}
					else										//否則,是空白的話代表某個數字的讀取結束
					{
						Box[Row][Col] = atof(Get.c_str());			//將get累積的字串用atof轉成float存到Box陣列中
						Get = "";									//get清除重製
						Col++;										//Box[row][col]裝完Box[row][++col]裝下一個
					}
				}
				Row++;											//這列裝完換下一列裝
				End++;											//紀錄最後有幾列(幾組(x,y)pair)
				Col = 0;										//換列col重製
			}
			Line = "";											//Line buffer清除重製
		}
		//讀檔失敗
		else
		{
			cout << "Failed..." << endl;
		}
		Point *read_points = new Point[End];					//將Box所存的data用Point array方式回傳
		for (int i = 0; i < End; i++)
		{
			read_points[i].x = Box[i][0];
			read_points[i].y = Box[i][1];
		}
		infile.close();
		nPoint = End;
		return read_points;
	}
	//#5
	Point MinDistance(Point*points, unsigned int pointnum, float&returnmindis, float A, float B, float C)	//找到點使得該點到Ax+By+C=0距離最短,且利用call by ref回傳最短距離returnmindis
	{
		float *distance_to_line = new float[pointnum];														//將點到線的距離依序儲存
		distance_to_line[0] = abs(A*points[0].x + B * points[0].y + C) / sqrt(A*A + B * B);					//紀錄最短距離
		float mindistance = distance_to_line[0];
		int mindistance_index = 0;																			//紀錄哪個index的點具有最短距離
		for (int i = 1; i < pointnum; i++)
		{

			distance_to_line[i] = abs(A*points[i].x + B * points[i].y + C) / sqrt(A*A + B * B);
			if (distance_to_line[i] < mindistance)
			{
				mindistance = distance_to_line[i];
				mindistance_index = i;
			}
		}
		returnmindis = mindistance;
		return points[mindistance_index];
	}
	//#6																									//將點陣列依照到原點距離由大->小排列
	int cmp(const void*a, const void*b)																		//C/C++内建qsort()的cmp()需自訂
	{
		return (*(Point*)a).Length() > (*(Point*)b).Length() ? -1 : 1;										//小->大是?1:-1.然而大到小恰好相反是?-1:1
	}
	void SortbyLength(Point*points, unsigned int pointnum)													//呼叫C/C++内建qsort()來對Point結構的array排序
	{
		qsort(points, pointnum, sizeof(Point), cmp);
	}
	//#7
	void Report(const char*filename, unsigned int pointnum, Point MDPL, Point*rdata)
	{
		//const char*filename="C:\\Users\\HSNL\\source\\repos\\P76081108\\HW01_02\\Report_HW1.txt"
		string Loc = filename;	//檔案路徑

		//輸出串流(寫檔)
		ofstream outfile(Loc.c_str(),ios::out);
		//寫檔成功
		if (outfile)
		{
			outfile << "物件導向程式設計第一次作業" << endl;
			outfile << "學號:P76081108\t姓名:蘇奕瑋" << endl;
			outfile << "點數目：" << pointnum << endl;
			outfile << "最接近 x + y = 1 的點：(" << MDPL.x << "," << MDPL.y << ")" << endl;
			outfile << "與原點距離最近的點：("<<rdata[pointnum-1].x<<","<< rdata[pointnum - 1].y<<")、距離為：" << rdata[pointnum - 1].Length()<< endl;
			cout << "OUTPUT SUCCESS!!" << endl;
		}
		//寫檔失敗
		else
		{
			cout << "Failed..." << endl;
		}
		outfile.close();
	}
}