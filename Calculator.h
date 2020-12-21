#ifndef _CALCULATOR_
#define _CALCULATOR_

#include "inf_int.h"
#include <iostream>
#include <stack>
#include <sstream>
#include <stdlib.h>

class Calculator
{
	struct oper
	{
		char op;
		int priority;
	};

private:
	std::stack <inf_int> num;
	std::stack <oper> operand;

	bool _isValid;

public:
	Calculator();
	~Calculator();

	bool isValid() {return _isValid;};
	void init();
	void Run();
	inf_int Calculation(std::string&);
	void Calculate();
};

#endif