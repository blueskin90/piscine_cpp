#include "ParOpenToken.hpp"

ParOpenToken::ParOpenToken(char value): _value(value)
{
}

char	ParOpenToken::getValue() const
{
	return (this->_value);
}

std::string	ParOpenToken::getPrint() const
{
	std::stringstream ss;

	ss << "ParOpen(" << this->getValue() << ")";
	return (ss.str());
}
