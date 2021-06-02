#include "Intern.hpp"

const std::string Intern::_compareStrings[3] = {
	"shrubbery creation", 
	"robotomy request", 
	"presidential pardon"
};

Form* (*formFunc[3])(std::string) = {
	&Intern::_makePardonForm,
	&Intern::_makeRobotomyForm,
	&Intern::_makeShrubberyForm
};

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
	*this = intern;
}

Intern::~Intern(void)
{
}

int		Intern::getFormType(std::string form)
{
	int	i;

	i = 0;
	while (i < 3 && form != Intern::_compareStrings[i])
		i++;
	return (i);
}

Form* Intern::makeForm(std::string type, std::string target)
{
	int		typeint;
	Form*	form;

	typeint = getFormType(type);
	if (typeint < 3)
	{
		form = Intern::formFunc[typeint](target);
		std::cout << "Intern creates " << *form << std::endl;
		return (form);
	}
	else
	{
		std::cout << "Intern couldn't create form: " << type << " because it doesn't exists" << std::endl;
		return (NULL);
	}
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
