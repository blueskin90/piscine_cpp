#include "Bureaucrat.hpp"

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &rhs)
{
	int srcGrade = rhs.getGrade();
	if (srcGrade < 1)
		throw GradeTooHighException();
	else if (srcGrade > 150)
		throw GradeTooLowException();
	this->_grade = srcGrade;
	return (*this);
}

Bureaucrat::Bureaucrat(void): _name("Unnamed"), _grade(150)
{
}

Bureaucrat::Bureaucrat(std::string const &name, int grade): _name(name)
{
	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
	this->_grade = grade;
}

Bureaucrat::Bureaucrat(Bureaucrat const &src): _name(src.getName())
{
	int srcGrade = src.getGrade();
	if (srcGrade < 1)
		throw GradeTooHighException();
	else if (srcGrade > 150)
		throw GradeTooLowException();
	this->_grade = srcGrade;
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade too high, can't get higher.");
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade too low, can't get any lower.");
}

Bureaucrat::~Bureaucrat(void)
{
}

std::string const	Bureaucrat::getName(void) const
{
	return (this->_name);
}

int			 		Bureaucrat::getGrade(void) const
{
	return (this->_grade);
}

void				Bureaucrat::incGrade(void)
{
	if (this->getGrade() == 1)
		throw GradeTooHighException();
	this->_grade--; 
}

void				Bureaucrat::decGrade(void)
{
	if (this->getGrade() == 150)
		throw GradeTooLowException();
	this->_grade++;
}

void				Bureaucrat::signForm(Form &form) const
{
	try
	{
		form.beSigned(*this);
		std::cout << *this << " signs " << form << "." << std::endl;
	}
	catch (Form::GradeTooLowException &e)
	{
		std::cout << *this << " can't sign " << form << " because its grade is too low to sign this form." << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << *this << " can't sign " << form << " because : " << e.what() << std::endl;
	}
}

void				Bureaucrat::executeForm(Form const &form) const
{
	try
	{
		form.execute(*this);
		std::cout << *this << " executs " << form << "." << std::endl;
	}
	catch (Form::GradeTooLowException &e)
	{
		std::cout << *this << " cant execute " << form << " because its grade is too low to execute this form." << std::endl;
	}
	catch (Form::NotSignedException &e)
	{
		std::cout << *this << " cant execute " << form << " because " << e.what() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << *this << " cant execute " << form << " because : " << e.what() << std::endl;
	}
}



std::ostream& operator<< (std::ostream &output, Bureaucrat const &bur)
{
	output << bur.getName() << ", bureaucrat grade " << bur.getGrade();
	return (output);
}
