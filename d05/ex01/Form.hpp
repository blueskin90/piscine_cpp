#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
	public:
		Form(std::string const &name, int signGrade, int execGrade);
		Form(Form const &src);
		~Form(void);

		std::string const getName(void) const;
		int		getSignGrade(void) const;
		int		getExecGrade(void) const;
		bool	getSignature(void) const;

		void	beSigned(Bureaucrat const &bureaucrat);


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
		int		checkGrade(int grade);
		Form(void);
		Form& operator=(Form const &rhs);

		std::string const 	_name;
		int const			_signGrade;
		int const			_execGrade;
		bool				_signed;
};

std::ostream& operator<< (std::ostream &output, Form const &form);


#endif /* FORM_HPP */
