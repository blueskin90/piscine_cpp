#include "AMateria.hpp"

AMateria::AMateria(void): _type("Blank") , _xp(0)
{
}

AMateria::AMateria(std::string const &type):  _type(type), _xp(0)
{
}

AMateria::AMateria(AMateria const &src): _type(src.getType()), _xp(src.getXP())
{
}

AMateria::~AMateria(void)
{
}

AMateria&			AMateria::operator=(AMateria const &rhs)
{
	this->_xp = rhs.getXP();
	return (*this);
}

std::string const	&AMateria::getType(void) const
{
	return (this->_type);
}

unsigned int		AMateria::getXP(void) const
{
	return (this->_xp);
}

void				AMateria::use(ICharacter &target)
{
	(void)target;
	this->_xp += 10;
}
