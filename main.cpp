#include "Calculator.h"
#include "MyForm.h"

int main()
{
	std::cout << "    -Infinite Integer Calculator Menu-    \n";
	std::cout << "\t1.Command User Interface\n\t2.Graphic User Interface\n\n>";
	int select; std::cin >> select;
	getchar();
	if (select == 1) //CUI
	{
		system("cls");
		Calculator Calc;
		Calc.Run();
	}
	else if (select == 2)
	{
		System::Windows::Forms::Application::EnableVisualStyles();
		System::Windows::Forms::Application::SetCompatibleTextRenderingDefault(false);
		CALCULATORGUI::MyForm form;
		System::Windows::Forms::Application::Run(% form);
	}
	else
	{
		std::cout << "Wrong number\n";
		getchar();
	}

	return 0;
}