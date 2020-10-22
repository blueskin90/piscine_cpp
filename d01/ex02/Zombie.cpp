#include "Zombie.hpp"

#include <iostream>

Zombie::Zombie(void) : _name(""), _type("")
{
	std::cout << "A Generic Zombie Rises from the deads !" << std::endl;
}

Zombie::Zombie(std::string const &name, std::string const &type) : _name(name), _type(type)
{
	std::cout << "<" << this->_name << " (" << this->_type << ")> Rises from the deads !" << std::endl;
}

Zombie::~Zombie(void)
{
	std::cout << "<" << this->_name << " (" << this->_type << ")> Returns to rest" << std::endl;
}

void	Zombie::announce(void) const
{
	std::cout << "<" << this->_name << " (" << this->_type << ")> Braiiiiiiinnnssss ..." << std::endl;
}
