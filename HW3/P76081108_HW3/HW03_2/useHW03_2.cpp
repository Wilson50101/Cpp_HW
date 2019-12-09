// P76081108:useHW03_2.cpp
#include <iostream>
#include"HW03_2.h"
#include <iostream>
#include <cstdlib>     // for rand(), srand()
#include <ctime>       // for time()
#include <string>
using namespace std;
int main()
{
	cout << "Test template Queue using integer: "<<endl;
	// create an empty int queue(circular) with 10 slots
	Queue<int> Qi(10);
	cout << "Enqueue:10"<<endl;
	Qi.Add(10);
	cout << "Enqueue:20" << endl;
	Qi.Add(20);
	cout << "Enqueue:30" << endl;
	Qi.Add(30);
	cout << "Enqueue:40" << endl;
	Qi.Add(40);
	cout << "Enqueue:50" << endl;
	Qi.Add(50);
	cout << "Enqueue:60" << endl;
	Qi.Add(60);
	cout << "Enqueue:70" << endl;
	Qi.Add(70);
	cout << "Enqueue:80" << endl;
	Qi.Add(80);
	cout << "Enqueue:90" << endl;
	Qi.Add(90);
	cout << "Enqueue:100" << endl;
	Qi.Add(100);
	cout << Qi << endl;
	
	cout<<"Dequeue:"<<*Qi.Delete()<<endl;
	cout << Qi << endl;

	cout << "Enqueue:1000" << endl;
	Qi.Add(1000);
	cout << Qi << endl;
	

	cout << "Test template Queue using string: " << endl;
	// create an empty int queue(circular) with 10 slots
	Queue<const char*> Qs(10);//sames as Queue<string> Qs(10);
	cout << "Enqueue:C++" << endl;
	Qs.Add("C++");
	cout << "Enqueue:Java" << endl;
	Qs.Add("Java");
	cout << "Enqueue:C" << endl;
	Qs.Add("C");
	cout << "Enqueue:PHP" << endl;
	Qs.Add("PHP");
	cout << "Enqueue:Python" << endl;
	Qs.Add("Python");

	cout << Qs << endl;

	cout << "Dequeue:" << *Qs.Delete() << endl;
	cout << Qs << endl;

	cout << "Enqueue:C#" << endl;
	Qs.Add("C#");
	cout << Qs << endl;
	std::cout << "Bye\n";
	std::cin.get();
	std::cin.get();
	return 0;
}
