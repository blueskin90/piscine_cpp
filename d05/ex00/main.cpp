#include "Bureaucrat.hpp"

int			main(void)
{
	Bureaucrat	*noob = new Bureaucrat("Noobito", 149);

	std::cout << "should be 149: " << noob->getGrade() << std::endl;
	noob->decGrade();
	std::cout << "should be 150: " << noob->getGrade() << std::endl;
		std::cout << "should cout grade too low exception" << std::endl;
	try
	{
		noob->decGrade();
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << *noob << std::endl;
	delete noob;

	noob = new Bureaucrat("Pro", 2);
	std::cout << "should be 2: " << noob->getGrade() << std::endl;
	noob->incGrade();
	std::cout << "should be 1: " << noob->getGrade() << std::endl;
		std::cout << "should cout grade too high exception" << std::endl;
	try
	{
		noob->incGrade();
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << *noob << std::endl;

	return (1);
}
