#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string const &target): Form("Robotomy Request form", 72, 45, target)
{
}

void	RobotomyRequestForm::onExecute(bool success)
{
	if (success)
		std::cout << "*BZZZZZZT pew pew RRRRRRRRRR* " << this->getTarget() << " a bien été robotomizé" << std::endl;
	else
		std::cout << "La robotomization de " << this->getTarget() << " est un échec cuisant" << std::endl;
}
