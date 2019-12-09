//學號:P76081108
//HW01_01.cpp : 
#include "pch.h"
#include <iostream>
#include <cstring>
#include <stdlib.h>																//srand()的函式原型在<stdlib.h>內
#include <time.h>																//time()的函式原型在<time.h>內
using namespace std;

//樣板函式宣告
template <typename T>
T max(T a[], int size);

//樣板函式特定化宣告
template < >const char* max(const char*a[], int size);

//主程式
int main()
{	//讀取內部時鐘產生seed做亂數
	srand((unsigned)time(NULL));	

	/*-----------------------------------------------------------------------------------------------------------------------------------------------------------*/
	
	//6個short值的陣列
	short* short_array;
	short_array = new short[6];
	//利用亂數產生6個short值並顯示
	cout << "亂數生成short array內容如下:\n";
	for (int i = 0; i < 6; i++)
	{
		//生成-32768~32767之間的亂數短整數,rand()是整數需強制轉型成(double),否則rand()[0~32767] / RAND_MAX[32767]幾乎全為0,導致short array值幾乎都是-32768
		short_array[i] = -32768 + (short)((double)rand() / RAND_MAX * 65535);	
		cout << "short_array[" << i << "]=" << short_array[i] << "\n";
	}
	cout << "\nshort array內最大值= " << max(short_array, 6) << "\n\n";

	/*-----------------------------------------------------------------------------------------------------------------------------------------------------------*/

	//8個double值的陣列
	double* double_array;
	double_array = new double[8];
	//利用亂數產生8個double值並顯示
	cout << "亂數生成double array內容如下:\n";
	for (int i = 0; i < 8; i++)
	{
		//生成-32768~32767之間的亂數小數,rand()是整數需強制轉型成(double)
		double_array[i] = -32768 + (double)rand() / RAND_MAX * 65535;			
		cout << "double_array[" << i << "]=" << double_array[i] << "\n";
	}
	cout << "\ndouble array內最大值= " << max(double_array, 8) << "\n\n";

	/*-----------------------------------------------------------------------------------------------------------------------------------------------------------*/

	//6個const char*的陣列
	const char* str_array[6] = { "AAA","BBBB","CCCC","DDDD","E","FFFFFF" };
	//顯示string內容
	cout << "str array contents:\n";
	for (int i = 0; i < 6; i++)
	{
		cout << "str_array[" << i << "]=";
		for (int j = 0; str_array[i][j] != '\0'; j++)
			cout << str_array[i][j];
		cout << "\n";
	}
	cout << "\n具有最大字串長度的字串(位置)= " << max(str_array, 6) << "\n";
	return 0;
}
//樣板函式內容
template <typename T>
T max(T a[], int size)
{
	T max = a[0];
	for (int i = 0; i < size; i++)												//不斷檢查a[i]是否>max
		if (a[i] > max)															//若有利
			max = a[i];															//則更新
	return max;
}
//樣板函式特定化
template <> const char* max(const char *a[], int size)
{
	int maxlen = 0;
	int maxindex = 0;
	for (int i = 0; i < size; i++)												
	{
		if (strlen(a[i]) > maxlen)												//不斷檢查a[i]的字串長度是否>maxlen
		{
			maxlen = strlen(a[i]);												//若有利則更新maxlen
			maxindex=i;															//以maxindex紀錄目前具有maxlen的字串索引
		}
	}
	return a[maxindex];															//回傳a[maxindex]為const char*
}