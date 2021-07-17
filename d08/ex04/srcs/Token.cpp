#include "Token.hpp"

std::ostream& operator << (std::ostream &output, Token const &arg)
{
	output << arg.getPrint();
	return (output);
}

int	Token::getType() const
{
	return (this->_type);
}
