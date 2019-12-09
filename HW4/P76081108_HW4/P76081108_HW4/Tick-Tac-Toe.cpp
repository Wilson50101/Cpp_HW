#include "Tick-Tac-Toe.h"
using namespace P76081108HW4;
[STAThreadAttribute]
int main(array<System::String ^> ^args)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	// 建立主視窗並執行
	Application::Run(gcnew TickTacToe());
	return 0;
}

