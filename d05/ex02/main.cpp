#include "Bureaucrat.hpp"
#include "Form.hpp"

int			main(void)
{
	Bureaucrat	noob("Noobito", 150);
	Bureaucrat	god("God", 2);

	Form		noobForm("Easy form", 150, 1);
	Form		hardForm("hard form", 1, 1);

	std::cout << "test noob form" << std::endl;
	std::cout << noobForm << std::endl;
	noob.signForm(noobForm);
	std::cout << noobForm << std::endl;


	std::cout << "test hard form" << std::endl;
	std::cout << hardForm << std::endl;
	god.signForm(hardForm);
	std::cout << hardForm << std::endl;
	god.incGrade();
	god.signForm(hardForm);
	std::cout << hardForm << std::endl;


	return (1);
}
