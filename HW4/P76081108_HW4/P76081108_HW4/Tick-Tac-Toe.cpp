#include "Tick-Tac-Toe.h"
using namespace P76081108HW4;
[STAThreadAttribute]
int main(array<System::String ^> ^args)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	// �إߥD�����ð���
	Application::Run(gcnew TickTacToe());
	return 0;
}

