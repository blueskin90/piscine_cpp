#include "NumToken.hpp"

NumToken::NumToken(long long int value): _value(value)
{
	this->_type = NUMBER;
}

long long int	NumToken::getValue() const
{
	return (this->_value);
}

std::string NumToken::getPrint() const
{
	std::stringstream ss;

	ss << "Num(" << this->getValue() << ")";
	return (ss.str());
}
