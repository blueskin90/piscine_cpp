#include "ParCloseToken.hpp"

ParCloseToken::ParCloseToken(char value): _value(value)
{
}

char	ParCloseToken::getValue() const
{
	return (this->_value);
}

std::string	ParCloseToken::getPrint() const
{
	std::stringstream ss;

	ss << "ParClose(" << this->getValue() << ")";
	return (ss.str());
}
