#include "Form.hpp"

Form::Form(std::string const &name, int signGrade, int execGrade, std::string const &target): _name(name),_signGrade(checkGrade(signGrade)), _execGrade(checkGrade(execGrade)), _signed(false), _target(target)
{
}

Form::Form(Form const &src): _name(src.getName()), _signGrade(checkGrade(src.getSignGrade())), _execGrade(checkGrade(src.getExecGrade())), _signed(src.getSignature()), _target(src.getTarget())
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

std::string const	Form::getTarget(void) const
{
	return (this->_target);
}


void				Form::beSigned(Bureaucrat const &bureaucrat)
{
	int				grade = bureaucrat.getGrade();

	if (grade <= this->_signGrade)	
		this->_signed = true;
	else
		throw Form::GradeTooLowException();
}

void				Form::execute(Bureaucrat const &executor) const
{
	int				grade = executor.getGrade();
	
	if (this->_signed == false)
	{
		this->onExecute(false);
		throw Form::NotSignedException();
	}
	if (grade <= this->_execGrade)
		this->onExecute(true);
	else
	{
		this->onExecute(false);
		throw Form::GradeTooLowException();
	}
}

int		Form::checkGrade(int grade)
{
	if (grade < 1)
		throw Form::GradeTooHighException();
	else if (grade > 150)
		throw Form::GradeTooLowException();
	return (grade);
}

Form::Form(void): _name("Unnamed"), _signGrade(150), _execGrade(150), _signed(false), _target("unnamedTarget")
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

const char* Form::NotSignedException::what() const throw()
{
	return ("The form wasn't signed.");
}
