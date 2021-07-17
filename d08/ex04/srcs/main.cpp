#include "ex04.hpp"

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
	delete result.top();
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
