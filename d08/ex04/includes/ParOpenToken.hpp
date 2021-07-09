#ifndef PAROPENTOKEN_HPP
#define PAROPENTOKEN_HPP

#include "Token.hpp"
#include <sstream>

class	ParOpenToken: public Token
{
	public:
		ParOpenToken(char value);
		char	getValue() const;
		std::string getPrint() const;
	private:
		char	_value;
};


#endif /* PAROPENTOKEN_HPP */
