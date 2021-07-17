#include "ex04.hpp"

void	dumpTokens(std::vector<Token*> tokens)
{
	std::vector<Token*>::iterator it = tokens.begin();
	while (it != tokens.end())
	{
		std::cout << **it << " ";
		it++;
	}
	std::cout << std::endl;
}

void	dumpStack(std::stack<Token*>result)
{
	while (result.size() > 0)
	{
		std::cout << *(result.top()) << " ";
		result.pop();
	}
}

void	dumpNumStack(std::stack<Token*>result)
{
	while (result.size() > 0)
	{
		std::cout << " " << dynamic_cast<NumToken*>(result.top())->getValue();
		result.pop();
	}
}

void	dumpOpType(OpToken* tok)
{
	std::string str;

	if (tok->getValue() == '+')
		str = "OP Add";
	else if (tok->getValue() == '-')
		str = "OP Substract";
	else if (tok->getValue() == '*')
		str = "OP Multiply";
	else if (tok->getValue() == '/')
		str = "OP Divide";

	std::cout << " | " << std::left << std::setw(12) << str;
	(void)tok;
}
