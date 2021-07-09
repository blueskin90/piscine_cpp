#ifndef OPTOKEN_HPP
#define OPTOKEN_HPP

#include "Token.hpp"
#include <sstream>

class	OpToken: public Token
{
	public:
		OpToken(char value);
		char	getValue() const;
		std::string getPrint() const;
	private:
		char	_value;
};

#endif /* OPTOKEN_HPP */
