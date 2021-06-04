#ifndef INTERN_HPP
#define INTERN_HPP

#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Form.hpp"


class Intern
{

	typedef Form* (Intern::*InternMemFn)(std::string);
	public:
		Intern & operator=(Intern const &rhs);
		
		Intern(void);
		Intern(Intern const &intern);
		~Intern(void);
		
		Form* makeForm(std::string formType, std::string target);

		Form* _makePardonForm(std::string target);
		Form* _makeRobotomyForm(std::string target);
		Form* _makeShrubberyForm(std::string target);
		InternMemFn formFunc[3];


	private:
		int		getFormType(std::string form);
		static const std::string _compareStrings[3];
};

#endif /* INTERN_HPP */
