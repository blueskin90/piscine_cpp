#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string const &target): Form::Form("Shruberry Creation Form", 145, 137, target)
{
}

void ShrubberyCreationForm::onExecute(bool success)
{
	if (success)
		std::cout << "success" << std::endl;
	else
		std::cout << "fail" << std::endl;
	// ici creer le fichier avec les arbres
}
