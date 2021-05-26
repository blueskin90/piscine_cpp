#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "Form.hpp"

class ShrubberyCreationForm : public Form
{
	public :
		ShrubberyCreationForm(std::string const &target);
		void onExecute(bool success);
};

#endif /* SHRUBBERYCREATIONFORM_HPP */
