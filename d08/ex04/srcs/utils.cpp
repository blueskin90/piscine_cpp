#include "ex04.hpp"

bool	isNumber(char c)
{
	return ( (c >= '0' && c <= '9') ? 1 : 0);
}

bool	isSign(char c)
{
	return ((c == '+' || c == '-' || c == '/' || c == '*') ? 1 : 0);
}

bool	isPar(char c)
{
	return ((c == '(' || c == ')') ? 1 : 0);
}

void	vectorToStack(std::vector<Token*>*tokens, std::stack<Token*>*result)
{
	while (tokens->size() > 0)
	{
		result->push(tokens->back());
		tokens->pop_back();
	}
}
