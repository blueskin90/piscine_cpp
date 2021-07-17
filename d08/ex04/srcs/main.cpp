#include <iostream>
#include <vector>
#include <stack>
#include <iomanip>
#include "Token.hpp"
#include "NumToken.hpp"
#include "OpToken.hpp"
#include "ParOpenToken.hpp"
#include "ParCloseToken.hpp"

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

bool	parseNumber(std::string::iterator *it, std::vector<Token*> *list)
{
	std::string str;
	int			value;
	while (**it && isNumber(**it))
	{
		str.append(1, **it);
		(*it)++;
	}
	try
	{
		value = std::stoi(str, NULL, 10);
		list->push_back(new NumToken(value));
	}
	catch (std::exception &e)
	{
		std::cout << "Couldn't parse " << str << " because : " << e.what() << std::endl;
		return (false);
	}
	return (true);
}

bool	parseSignedNumber(std::string::iterator *it, std::vector<Token*> *list)
{
	std::string str;
	int			value;

	str.append(1, **it);
	(*it)++;
	while (**it && isNumber(**it))
	{
		str.append(1, **it);
		(*it)++;
	}
	try
	{
		value = std::stoi(str, NULL, 10);
		list->push_back(new NumToken(value));
	}
	catch (std::exception &e)
	{
		std::cout << "Couldn't parse " << str << " because : " << e.what() << std::endl;
		return (false);
	}
	return (true);
}


bool	parseSign(std::string::iterator *it, std::vector<Token*> *list)
{
	if ((**it == '+' || **it == '-') && isNumber(*((*it) + 1)))
		return (parseSignedNumber(it, list));
	list->push_back(new OpToken(**it));
	(*it)++;
	return (true);
}

void	parsePar(std::string::iterator *it, std::vector<Token*> *list)
{
	if (**it == '(')
		list->push_back(new ParOpenToken(**it));
	else
		list->push_back(new ParCloseToken(**it));
	(*it)++;
}

bool	tokenizeString(const char *charstr, std::vector<Token*> *list)
{
	std::string str(charstr);

	for (std::string::iterator it = str.begin(); it != str.end(); )
	{
		if (isSign(*it))
		{
			if (!parseSign(&it, list))
				return (false);
		}
		else if (isNumber(*it))
		{
			if (!parseNumber(&it, list))
				return (false);
		}
		else if (isPar(*it))
			parsePar(&it, list);
		else if (*it == ' ')
			++it;
		else
		{
			std::cout << "Can't parse token: " << *it << std::endl;
			return (false);
		}
	}
	return (true);
}

void	opTokenHandling(std::vector<Token*> *tokens, std::vector<Token*> *output, std::vector<Token*> *opStack)
{
	OpToken	*tmp;
	OpToken	*tmpStack;

	tmp = dynamic_cast<OpToken*>(tokens->front());
	while (opStack->size() > 0)
	{
		if (opStack->back()->getType() == PAROPEN)
			break;
		else
		{
			tmpStack = dynamic_cast<OpToken*>(opStack->back());
			if (tmpStack->getPrecedence() >= tmp->getPrecedence())
			{
				output->push_back(opStack->back());
				opStack->pop_back();
			}
			else
				break;
		}
	}
	opStack->push_back(tokens->front());
	tokens->erase(tokens->begin());
}

bool	parCloseHandling(std::vector<Token*> *tokens, std::vector<Token*> *output, std::vector<Token*> *opStack)
{
	Token	*tmp;
	if (opStack->size() == 0)
		return (false);
	while (opStack->back()->getType() != PAROPEN)
	{
		output->push_back(opStack->back());
		opStack->pop_back();
		if (opStack->size() == 0)
			return (false);
	}
	tmp = opStack->back();
	opStack->pop_back();
	delete tmp;
	tmp = tokens->front();
	tokens->erase(tokens->begin());
	delete tmp;
	return (true);
}

bool	postfixConversion(std::vector<Token*> *tokens)
{
	std::vector<Token*> output;
	std::vector<Token*> opStack;

	while (tokens->size() > 0)
	{
		if (tokens->front()->getType() == NUMBER)
		{
			output.push_back(tokens->front());
			tokens->erase(tokens->begin());
		}
		else if (tokens->front()->getType() == OP)
			opTokenHandling(tokens, &output, &opStack);
		else if (tokens->front()->getType() == PAROPEN)
		{
			opStack.push_back(tokens->front());
			tokens->erase(tokens->begin());
		}
		else if (tokens->front()->getType() == PARCLOSE)
		{
			if (!parCloseHandling(tokens, &output, &opStack))
			{
				std::cout << "Couldn't find matching parenthesis" << std::endl;
				return (false);
			}
		}
	}
	while (opStack.size() != 0)
	{
		if (opStack.back()->getType() == PAROPEN)
		{
			std::cout << "Couldn't find matching parenthesis" << std::endl;
			return (false);
		}
		output.push_back(opStack.back());
		opStack.pop_back();
	}
	*tokens = output;
	return (true);		
}

void	dumpStack(std::stack<Token*>result)
{
	while (result.size() > 0)
	{
		std::cout << *(result.top()) << " ";
		result.pop();
	}
}

void	vectorToStack(std::vector<Token*>*tokens, std::stack<Token*>*result)
{
	while (tokens->size() > 0)
	{
		result->push(tokens->back());
		tokens->pop_back();
	}
}

bool	do_op(std::stack<Token*>*tokenStack, OpToken* operation)
{
	NumToken*	a;
	NumToken*	b;
	NumToken*	result;

	if (tokenStack->size() < 2)
	{
		std::cout << "Couldn't solve the equation because you don't know how to write an equation" << std::endl;
		return (false);
	}
	else
	{
		a = dynamic_cast<NumToken*>(tokenStack->top());
		tokenStack->pop();
		b = dynamic_cast<NumToken*>(tokenStack->top());
		tokenStack->pop();
		result = operation->exec(a, b);
		if (result == NULL)
		{
			std::cout << " ERROR ! division by 0" << std::endl;
			return (false);
		}
		tokenStack->push(result);
		delete a;
		delete b;
	}
	return (true);
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

bool	solve(std::vector<Token*>*tokens)
{
	std::stack<Token*>tokenStack;
	std::stack<Token*>result;
	OpToken	*tmp;

	vectorToStack(tokens, &tokenStack);
	while (tokenStack.size() != 0)
	{
		std::cout << "[ " << std::left << std::setw(16) << *tokenStack.top();
		if (tokenStack.top()->getType() == NUMBER)
		{
			std::cout << " | " << std::left << std::setw(12) << "OP Push";
			std::cout << " | ST";
			result.push(tokenStack.top());
			dumpNumStack(result);
			std::cout << "]" << std::endl;
			tokenStack.pop();
		}
		else
		{
			tmp = dynamic_cast<OpToken*>(tokenStack.top());
			if (!do_op(&result, dynamic_cast<OpToken*>(tokenStack.top())))
				return (false);
			dumpOpType(tmp);
			tokenStack.pop();
			std::cout << " | ST ";
			dumpNumStack(result);
			std::cout << "]" << std::endl;
			delete tmp;
		}
	}
	std::cout << "Result : " << dynamic_cast<NumToken*>(result.top())->getValue() << std::endl;
	return (true);
}

int		main(int ac, char **av)
{
	std::vector<Token*> tokens;

	if (ac != 2)
	{
		std::cout << "./ex04 \"expression to evaluate\"" << std::endl;
		return (1);
	}
	if (!tokenizeString(av[1], &tokens))
		return (1);
	std::cout << "Tokens: ";
	dumpTokens(tokens);
	if (!postfixConversion(&tokens))
		return (1);
	std::cout << "Postfix: ";
	dumpTokens(tokens);
	if (!solve(&tokens))
		return (1);
	return (0);
}
