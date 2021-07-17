#ifndef OPTOKEN_HPP
#define OPTOKEN_HPP

#include "Token.hpp"
#include "NumToken.hpp"

#include <sstream>

class	OpToken: public Token
{
	public:
		OpToken(char value);
		char	getValue() const;
		std::string getPrint() const;
		int		getPrecedence() const;
		NumToken*	exec(NumToken *a, NumToken *b) const;

	private:
		char	_value;
		int		_precedence;
};

#endif /* OPTOKEN_HPP */
