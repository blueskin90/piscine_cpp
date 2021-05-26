#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

void		signForm(Form *form, Bureaucrat &bureaucrat)
{
	try
	{
		form->beSigned(bureaucrat);
		std::cout << "form signed !" << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "form not signed because : " << e.what() << std::endl;
	}	
}

void		execForm(Form *form, Bureaucrat &bureaucrat)
{
	try
	{
		form->execute(bureaucrat);
		std::cout << "form executed !" << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "form not executed because: " << e.what() << std::endl;
	}	
}

int			main(void)
{
	Bureaucrat	noob("Noobito", 146);
	Bureaucrat	god("God", 138);

	Form* pardonform= new PresidentialPardonForm("Thomas");
	Form* robotomyform = new RobotomyRequestForm("Pauvre victime");
	Form* shrubberyform = new ShrubberyCreationForm("maison");

	std::cout << "SHRUBBERY FORM TEST" << std::endl;
	signForm(shrubberyform, noob);
	noob.incGrade();
	execForm(shrubberyform, god);
	signForm(shrubberyform, noob);
	execForm(shrubberyform, god);
	god.incGrade();
	execForm(shrubberyform, god);

	std::cout << std::endl << "ROBOTOMY FORM TEST" << std::endl;
	while (noob.getGrade() > 73)
		noob.incGrade();
	while (god.getGrade() > 46)
		god.incGrade();
	
	signForm(robotomyform, noob);
	noob.incGrade();
	execForm(robotomyform, god);
	signForm(robotomyform, noob);
	execForm(robotomyform, god);
	god.incGrade();
	execForm(robotomyform, god);


	std::cout << std::endl << "PARDON FORM TEST" << std::endl;
	while (noob.getGrade() > 26)
		noob.incGrade();
	while (god.getGrade() > 6)
		god.incGrade();
	
	signForm(pardonform, noob);
	noob.incGrade();
	execForm(pardonform, god);
	signForm(pardonform, noob);
	execForm(pardonform, god);
	god.incGrade();
	execForm(pardonform, god);




	return (1);
}
