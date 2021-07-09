#include <iostream>
#include <vector>
#include "Token.hpp"
#include "NumToken.hpp"
#include "OpToken.hpp"
#include "ParOpenToken.hpp"
#include "ParCloseToken.hpp"

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

int		main(int ac, char **av)
{
	std::vector<Token*> tokens;

	if (ac != 2)
	{
		std::cout << "./ex04 \"expression to evaluate\"" << std::endl;
		return (1);
	}
	tokens.push_back(new ParOpenToken('('));
	tokens.push_back(new NumToken(11));
	tokens.push_back(new OpToken('-'));
	tokens.push_back(new NumToken(11));
	tokens.push_back(new ParCloseToken(')'));
	
	dumpTokens(tokens);
	(void)av;
	return (0);
}
