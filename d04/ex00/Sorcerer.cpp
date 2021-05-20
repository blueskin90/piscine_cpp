#include "Sorcerer.hpp"

Sorcerer::Sorcerer(void) : _name("Unnamed"), _title("the untitled")
{
}

Sorcerer::Sorcerer(std::string const &name, std::string const &title) : _name(name), _title(title)
{
	std::cout << this->_name << ", " << this->_title << ", is born!" << std::endl;
}

Sorcerer::Sorcerer(Sorcerer const &src) : _name(src.getName()), _title(src.getTitle())
{
	std::cout << this->_name << ", " << this->_title << ", is born!" << std::endl;
}

Sorcerer::~Sorcerer(void)
{
	std::cout << this->_name << ", " << this->_title << ", is dead. Consequences will never be the same!" << std::endl;
}

void	Sorcerer::polymorph(Victim const & victim) const
{
	victim.getPolymorphed();
}

std::string	const Sorcerer::getName(void) const
{
	return (this->_name);
}

std::string	const Sorcerer::getTitle(void) const
{
	return (this->_title);
}

Sorcerer& Sorcerer::operator=(Sorcerer const &rhs)
{
	(void)rhs;
	return (*this);
}

std::ostream& operator<< (std::ostream &output, Sorcerer const &sorc)
{
	output << "I am " <<  sorc.getName() << ", " << sorc.getTitle() << ", and I like ponies!"<< std::endl;
	return (output);
}
