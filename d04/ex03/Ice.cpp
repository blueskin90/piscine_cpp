#include "Ice.hpp"

Ice::Ice(void): AMateria("ice")
{
}

Ice::Ice(Ice const &src): AMateria(src)
{
}

Ice::~Ice(void)
{
}

AMateria*	Ice::clone(void) const
{
	return (new Ice(*this));
}

void		Ice::use(ICharacter &target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
	this->_xp += 10;
}
