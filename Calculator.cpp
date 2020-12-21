#include "Calculator.h"

Calculator::Calculator()
	:_isValid(true)
{
}
Calculator::~Calculator()
{

}

void Calculator::init()
{
	_isValid = true;
	while (!num.empty())
		num.pop();

	while (!operand.empty())
		operand.pop();
}

void Calculator::Run()
{
	std::string input; //input에 숫자 외의 문자가 포함될 시 Error
	std::cout << "Input Example. \"3333333333333333333333333 - 55555 * ( 10 - 7311111111111111111111 )\"\n(if input number is zero, Program exit)\n\n";
	while (true)
	{
		init();
		std::cout << "Input >";
		getline(std::cin, input);
		if (input == "0") break;

		inf_int result = Calculation(input);

		if (isValid())
			std::cout << result << '\n';
		else
		{
			std::cout << "Not valid input (Check the input format)\n";
		}
	}
}

inf_int Calculator::Calculation(std::string& expr)
{
	std::stringstream st(expr);
	inf_int result;
	std::string token;

	while (st >> token)
	{
		if (token == "(")
			operand.push({ '(',0 });
		else if (token == ")")
		{
			while (!operand.empty() && operand.top().op != '(')
			{
				Calculate();
				if (operand.empty())
				{
					_isValid = false;
					return result;
				}
			}
			if (!operand.empty())
				operand.pop();
		}
		else if (token == "*" || token == "+" || token == "-")
		{
			int priority;
			if (token == "*")
				priority = 2;
			else
				priority = 1;

			while (!operand.empty() && priority <= operand.top().priority)
				Calculate();
			operand.push({ token[0],priority });
		}
		else
		{
			inf_int temp(token.c_str());
			if (temp == "#") //input Error
			{
				_isValid = false;
				break;
			}
			num.push(temp);
		}
	}

	while (!operand.empty())
		Calculate();

	if (!num.empty() && operand.empty())
		if (num.size() == 1)
			result = num.top();
		else
			_isValid = false;


	return result;
}

void Calculator::Calculate()
{
	if (num.size() < 2)
	{
		_isValid = false;
		operand.pop();
		return;
	}

	inf_int first,second,result;
	second = num.top(); num.pop();
	first = num.top(); num.pop();

	char oper = operand.top().op; operand.pop();

	switch (oper)
	{
	case '*':
	{
		result= first * second;
		break;
	}
	case '+':
		result = first + second;
		break;
	case '-':
		result = first - second;
		break;
	}
	num.push(result);
}