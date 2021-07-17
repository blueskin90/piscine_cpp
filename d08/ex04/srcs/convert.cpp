#include "ex04.hpp"

static void	opTokenHandling(std::vector<Token*> *tokens, std::vector<Token*> *output, std::vector<Token*> *opStack)
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

static bool	parCloseHandling(std::vector<Token*> *tokens, std::vector<Token*> *output, std::vector<Token*> *opStack)
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
