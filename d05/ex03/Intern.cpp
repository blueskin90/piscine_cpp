#include "Intern.hpp"

Intern &Intern::operator=(Intern const &rhs)
{
	(void)rhs;
	return (*this);
}

Intern::Intern(void)
{
}

Intern::Intern(Intern const &intern)
{
	(void)intern;
}

Intern::~Intern(void)
{
}

Form *Intern::makeForm(std::string type, std::string target)
{
	std::cout << "Intern creates " << *form << std::endl;
}
