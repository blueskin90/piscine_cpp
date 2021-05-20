#include "Villager.hpp"
#include <iostream>

Villager::Villager(void) : Victim("Unnamed")
{
}

Villager::Villager(std::string const &name) : Victim(name)
{
	std::cout << "Welcome Traveller." << std::endl;
}

Villager::Villager(Villager const &src) : Victim(src.getName())
{
	std::cout << "Welcome Traveller." << std::endl;
}

Villager::~Villager(void)
{
	std::cout << this->_name << " died, too bad, so sad :(" << std::endl;
}

void	Villager::getPolymorphed(void) const
{
	std::cout << this->_name << " has been turned into a turtle!" << std::endl;
}

Villager& Villager::operator=(Villager const &rhs)
{
	(void)rhs;
	return (*this);
}
