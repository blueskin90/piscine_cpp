#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>

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

		class GradeTooHighException: public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return ("Grade too high, can't get higher.");
				}
		};

		class GradeTooLowException: public std::exception
		{
			public:
				virtual const char* what() const throw()
			{
				return ("Grade too low, can't get any lower.");
			}
		};

	private:
		Bureaucrat(void);
		std::string const _name;
		int _grade;
};

std::ostream& operator<< (std::ostream &output, Bureaucrat const &bureaucrat);


#endif /* BUREAUCRAT_HPP */
