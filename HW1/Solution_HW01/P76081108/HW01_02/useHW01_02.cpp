//�Ǹ�:P76081108
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
	//#1�]�wx=3,y=4������
	Point p = { 3.0,4.0 };

	//#2
	cout << "\n#2:\n���I(0,0)��(" << p.x << "," << p.y << ")�Z����:" << p.Length() << endl;

	//#3
	cout << "\n#3:\nCoutPoint()���e�p�U:" << p.CoutPoint() << endl;

	//#4
	unsigned int nPoint = 0;							//����Ū��Ū�쪺�I��
	Point*rdata = LoadPoint("C:\\Users\\HSNL\\source\\repos\\P76081108\\HW01_02\\Point_HW1.txt", nPoint);
	cout << "\n#4:\nŪ�J" << nPoint << "���I" << endl;
	cout << "Ū�Jdata�p�U:" << endl;
	for (int i = 0; i < nPoint; i++)
		cout << "Point" << i + 1 << ":" << "(" << rdata[i].x << "," << rdata[i].y << ")" << endl;
	//#5
	float mindis = 0.0;
	Point MDPL = MinDistance(rdata, nPoint, mindis, 1/*x���Y��*/, 1/*y���Y��*/, -1/*�`�ƶ�*/);	//�D#4Ū�J���U�I���Z��x+y=1�̪��I����
	cout << "\n#5:\n�Px+y-1=0�̪��I��:(" << MDPL.x << "," << MDPL.y << ")" << endl;
	cout << "�䤧���Z����:" << mindis << endl;
	
	//#6
	cout << "\n#6:\n�N�I�}�C�̦U�I�P���I�Z���Ѥj��p�Ƨǫᵲ�G�p�U:" << endl;
	SortbyLength(rdata,nPoint);
	for (int i = 0; i < nPoint; i++)
		cout << "Point" << i + 1 << ":" << "(" << rdata[i].x << "," << rdata[i].y << ")\t�Z�����I:" <<rdata[i].Length()<< endl;

	//#7
	cout << "\n#7:\n�NReport�g��C:\\Users\\HSNL\\source\\repos\\P76081108\\HW01_02\\Report_HW1.txt" << endl;
	Report("C:\\Users\\HSNL\\source\\repos\\P76081108\\HW01_02\\Report_HW1.txt", nPoint, MDPL, rdata);
	return 0;
}