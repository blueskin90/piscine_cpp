#include "ParCloseToken.hpp"

ParCloseToken::ParCloseToken(char value): _value(value)
{
	this->_type = PARCLOSE;
}

char	ParCloseToken::getValue() const
{
	return (this->_value);
}

std::string	ParCloseToken::getPrint() const
{
	std::stringstream ss;

	ss << "ParClose";
	return (ss.str());
}
