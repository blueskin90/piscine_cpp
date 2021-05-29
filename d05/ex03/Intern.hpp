#ifndef INTERN_HPP
#define INTERN_HPP

#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Form.hpp"

class Intern
{
	public:
		Intern & operator=(Intern const &rhs);
		
		Intern(void);
		Intern(Intern const &intern);
		~Intern(void);
		
		Form* makeForm(std::string formType, std::string target);
	private:
		Form* _makePardonForm(std::string target);
		Form* _makeRobotomyForm(std::string target);
		Form* _makeShrubberyForm(std::string target);

		Form* (Intern::*f)(std::string) _functions[3];
			
};

#endif /* INTERN_HPP */
