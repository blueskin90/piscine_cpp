#include "OpToken.hpp"

OpToken::OpToken(char value): _value(value)
{
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
