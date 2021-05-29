#include "Intern.hpp"

Intern &Intern::operator=(Intern const &rhs)
{
	(void)rhs;
	return (*this);
}

Intern::Intern(void)
{
	_functions[0] = &Intern::_makePardonForm;
}

Intern::Intern(Intern const &intern)
{
	*this = intern;
}

Intern::~Intern(void)
{
}

Form* Intern::makeForm(std::string type, std::string target)
{
	(void)type;
	(void)target;
	Form *form = NULL;
	std::cout << "Intern creates " << *form << std::endl;

	return (form);
}

Form* Intern::_makePardonForm(std::string target)
{
	return (new PresidentialPardonForm(target));
}

Form* Intern::_makeRobotomyForm(std::string target)
{
	return (new RobotomyRequestForm(target));
}

Form* Intern::_makeShrubberyForm(std::string target)
{
	return (new ShrubberyCreationForm(target));
}
