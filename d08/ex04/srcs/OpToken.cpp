#include "OpToken.hpp"

OpToken::OpToken(char value): _value(value)
{
	if (value == '+' || value == '-')
		this->_precedence = 2;
	else
		this->_precedence = 3;
	this->_type = OP;
}

char	OpToken::getValue() const
{
	return (this->_value);
}

std::string	OpToken::getPrint() const
{
	std::stringstream ss;

	ss << "Op(" << this->getValue() << ")";
	return (ss.str());
}

int		OpToken::getPrecedence() const
{
	return (this->_precedence);
}

NumToken*	OpToken::exec(NumToken *a, NumToken *b) const
{
	if (this->_value == '+')
	{
		return (new NumToken(a->getValue() + b->getValue()));
	}
	else if (this->_value == '-')
	{
		return (new NumToken(a->getValue() - b->getValue()));
	}
	else if (this->_value == '*')
		return (new NumToken(a->getValue() * b->getValue()));
	else
	{
		if (a->getValue() == 0)
			return (NULL);
		return (new NumToken(b->getValue() / a->getValue()));
	}
}
