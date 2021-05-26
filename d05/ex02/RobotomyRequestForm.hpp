#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "Form.hpp"

class RobotomyRequestForm : public Form
{
	public:
		RobotomyRequestForm(std::string const &target);
		void onExecute(bool success);
};

#endif /* ROBOTOMYREQUESTFORM_HPP */
