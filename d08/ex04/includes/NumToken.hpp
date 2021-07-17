#ifndef NUMTOKEN_HPP
#define NUMTOKEN_HPP

#include "Token.hpp"
#include <cstdlib>
#include <sstream>

class NumToken: public Token
{
	public:
		NumToken(long long int value);
		long long int	getValue() const;
		std::string getPrint() const;
	private:
		long long int		_value;
};


#endif /* NUMTOKEN_HPP */
