#include "ParOpenToken.hpp"

ParOpenToken::ParOpenToken(char value): _value(value)
{
	this->_type = PAROPEN;
}

char	ParOpenToken::getValue() const
{
	return (this->_value);
}

std::string	ParOpenToken::getPrint() const
{
	std::stringstream ss;

	ss << "ParOpen";
	return (ss.str());
}
