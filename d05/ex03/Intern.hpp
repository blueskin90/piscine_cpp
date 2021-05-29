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
		
		Form *makeForm(std::string formType, std::string target);
	private:
		
};

#endif /* INTERN_HPP */
