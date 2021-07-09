#ifndef NUMTOKEN_HPP
#define NUMTOKEN_HPP

#include "Token.hpp"
#include <cstdlib>
#include <sstream>

class NumToken: public Token
{
	public:
		NumToken(int value);
		int	getValue() const;
		std::string getPrint() const;
	private:
		int		_value;
};


#endif /* NUMTOKEN_HPP */
