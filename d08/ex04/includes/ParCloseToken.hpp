#ifndef PARCLOSETOKEN_HPP
#define PARCLOSETOKEN_HPP

#include "Token.hpp"
#include <sstream>

class	ParCloseToken: public Token
{
	public:
		ParCloseToken(char value);
		char	getValue() const;
		std::string getPrint() const;
	private:
		char	_value;
};

#endif /* PARCLOSETOKEN_HPP */
