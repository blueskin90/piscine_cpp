#include "Form.hpp"

Form::Form(std::string const &name, int signGrade, int execGrade): _name(name),_signGrade(checkGrade(signGrade)), _execGrade(checkGrade(execGrade)), _signed(false)
{
}

Form::Form(Form const &src): _name(src.getName()), _signGrade(checkGrade(src.getSignGrade())), _execGrade(checkGrade(src.getExecGrade())), _signed(src.getSignature())
{
}

Form::~Form()
{
}

std::string const	Form::getName(void) const
{
	return (this->_name);
}

int					Form::getSignGrade(void) const
{
	return (this->_signGrade);
}

int					Form::getExecGrade(void) const
{
	return (this->_execGrade);
}

bool				Form::getSignature(void) const
{
	return (this->_signed);
}

void				Form::beSigned(Bureaucrat const &bureaucrat)
{
	int				grade = bureaucrat.getGrade();

	if (grade <= this->_signGrade)	
		this->_signed = true;
	else
		throw Form::GradeTooLowException();
}

int		Form::checkGrade(int grade)
{
	if (grade < 1 || grade < 1)
		throw Form::GradeTooHighException();
	else if (grade > 150 || grade > 150)
		throw Form::GradeTooLowException();
	return (grade);
}

Form::Form(void): _name("Unnamed"), _signGrade(150), _execGrade(150), _signed(false)
{
}

Form &Form::operator=(Form const &rhs)
{
	this->_signed = rhs.getSignature();
	return (*this);
}

std::ostream &operator<<(std::ostream &output, Form const &form)
{
	output << (form.getSignature() ? "Signed" : "unsigned") << " form: " << form.getName() << " with Sign grade set to : " << form.getSignGrade() << ", Exec grade set to : " << form.getExecGrade();
	return (output);
}

const char* Form::GradeTooHighException::what() const throw()
{
	return ("Grade too high.");
}

const char* Form::GradeTooLowException::what() const throw()
{
	return ("Grade too low.");
}


