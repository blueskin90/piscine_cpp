#include "Victim.hpp"
#include <iostream>

Victim::Victim(void) : _name("Unnamed")
{
}

Victim::Victim(std::string const &name) : _name(name)
{
	std::cout << "Some random victim called " << this->_name << " just appeared!" << std::endl;
}

Victim::Victim(Victim const &src) : _name(src.getName())
{
	std::cout << "Some random victim called " << this->_name << " just appeared!" << std::endl;
}

virtual Victim::~Victim(void)
{
	std::cout << "The victim " << this->_name << " died for no apparent reasons!" << std::endl;
}

void	Victim::getPolymorphed(void) const
{
	std::cout << this->_name << " has been turned into a cute little sheep!" << std::endl;
}

std::string	const Victim::getName(void) const
{
	return (this->_name);
}

Victim& Victim::operator=(Victim const &rhs)
{
	(void)rhs;
	return (*this);
}

std::ostream& operator<< (std::ostream &output, Victim const &vic)
{
	output << "I'm " << vic.getName() << " and I like otters!" << std::endl;
	return (output);
}
