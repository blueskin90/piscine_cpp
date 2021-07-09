#include "NumToken.hpp"

NumToken::NumToken(int value): _value(value)
{
}

int	NumToken::getValue() const
{
	return (this->_value);
}

std::string NumToken::getPrint() const
{
	std::stringstream ss;

	ss << "Num(" << this->getValue() << ")";
	return (ss.str());
}
