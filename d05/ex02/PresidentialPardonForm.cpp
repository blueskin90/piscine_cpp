#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string const &target): Form::Form("Presidential Pardon Form", 25, 5, target)
{
}

void PresidentialPardonForm::onExecute(bool success)
{
	if (success)
		std::cout << this->getTarget() << " a été pardonné par Zafod Beeblebrox" << std::endl;
}
