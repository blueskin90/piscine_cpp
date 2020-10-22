#include "Weapon.hpp"

Weapon::Weapon(std::string type) : _type(type)
{
}

Weapon::~Weapon(void)
{
}

void	Weapon::setType(std::string type)
{
	this->_type = type;
}

std::string const & Weapon::getType(void) const
{
	std::string const &ref = this->_type;
	return (ref);
}
