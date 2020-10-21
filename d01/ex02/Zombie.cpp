#include "Zombie.hpp"

#include <iostream>

Zombie::Zombie(void)
{
	this->name = "";
	this->type = "";
}

Zombie::~Zombie(void)
{

}

void	Zombie::advert(void) const
{
	std::cout << "<" << this->name << " (" << this->type << ")> Braiiiiiiinnnssss ..." << std::endl;
}
