//¾Ç¸¹:P76081108
//HW01_02.h : 
#include <math.h>
#include <string.h>
#include <cstring>
#include <string>
namespace MyGeometry
{
	using namespace std;
	struct Point
	{
		float x;
		float y;
		//#2
		double Length(void);

		//#3
		string CoutPoint(void);
	};
	//#4
	Point* LoadPoint(const char*, unsigned int&);
	//#5
	Point MinDistance(Point*, unsigned int, float&, float, float, float);
	//#6
	void SortbyLength(Point*,unsigned int);
	//#7 
	void Report(const char*,unsigned int/*pointnum*/,Point/*MinDistance*/,Point*/*LoadPoint*/); 
}
