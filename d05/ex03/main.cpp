#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Intern.hpp"

int			main(void)
{
	Intern slave;
	Bureaucrat	noob("Noobito", 146);
	Bureaucrat	god("God", 138);

	Form* pardonform = slave.makeForm("presidential pardon", "Thomas");
	Form* robotomyform =  slave.makeForm("robotomy request", "Pauvre victime");
	Form* shrubberyform = slave.makeForm("shrubbery creation", "Maison");


	std::cout << "SHRUBBERY FORM TEST" << std::endl;
	noob.signForm(*shrubberyform);
	noob.incGrade();
	god.executeForm(*shrubberyform);
	noob.signForm(*shrubberyform);
	god.executeForm(*shrubberyform);
	god.incGrade();
	god.executeForm(*shrubberyform);

	std::cout << std::endl << "ROBOTOMY FORM TEST" << std::endl;
	while (noob.getGrade() > 73)
		noob.incGrade();
	while (god.getGrade() > 46)
		god.incGrade();

	std::cout << "SHRUBBERY FORM TEST" << std::endl;
	noob.signForm(*robotomyform);
	noob.incGrade();
	god.executeForm(*robotomyform);
	noob.signForm(*robotomyform);
	god.executeForm(*robotomyform);
	god.incGrade();
	god.executeForm(*robotomyform);

	std::cout << std::endl << "PARDON FORM TEST" << std::endl;
	while (noob.getGrade() > 26)
		noob.incGrade();
	while (god.getGrade() > 6)
		god.incGrade();

	noob.signForm(*pardonform);
	noob.incGrade();
	god.executeForm(*pardonform);
	noob.signForm(*pardonform);
	god.executeForm(*pardonform);
	god.incGrade();
	god.executeForm(*pardonform);

	return (1);
}
