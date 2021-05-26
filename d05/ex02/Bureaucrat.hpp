#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include "Form.hpp"

class Form;

class Bureaucrat {
	public:
		Bureaucrat& operator=(Bureaucrat const &rhs);

		Bureaucrat(std::string const &name, int grade);
		Bureaucrat(Bureaucrat const &src);
		~Bureaucrat(void);

		std::string const	getName(void) const;
		int 				getGrade(void) const;

		void	 			incGrade(void);
		void 				decGrade(void);

		void				signForm(Form &form) const;
		void				executeForm(Form const &form) const;

		class GradeTooHighException: public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

		class GradeTooLowException: public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

	private:
		Bureaucrat(void);
		std::string const _name;
		int _grade;
};

std::ostream& operator<< (std::ostream &output, Bureaucrat const &bureaucrat);


#endif /* BUREAUCRAT_HPP */
