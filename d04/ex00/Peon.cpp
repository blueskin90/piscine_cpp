#include "Peon.hpp"

Peon::Peon(void) : Victim("Unnamed")
{
}

Peon::Peon(std::string const &name) : Victim(name)
{
	std::cout << "Zog zog." << std::endl;
}

Peon::Peon(Peon const &src) : Victim(src.getName())
{
	std::cout << "Zog zog." << std::endl;
}

Peon::~Peon(void)
{
	std::cout << "Bleuark..." << std::endl;
}

void	Peon::getPolymorphed(void) const
{
	std::cout << this->_name << " was just polymorphed into a pink pony" << std::endl;
}

Peon& Peon::operator=(Peon const &rhs)
{
	(void)rhs;
	return (*this);
}
