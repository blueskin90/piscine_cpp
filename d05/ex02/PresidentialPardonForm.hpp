#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "Form.hpp"

class PresidentialPardonForm : public Form
{
	public :
		PresidentialPardonForm(std::string const &target);
		void onExecute(bool success);
};

#endif /* PRESIDENTIALPARDONFORM_HPP */
