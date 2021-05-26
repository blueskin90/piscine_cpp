#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string const &target): Form::Form("Shruberry Creation Form", 145, 137, target)
{
}

void ShrubberyCreationForm::onExecute(bool success) const
{
	if (success)
	{
		try
		{
			std::ofstream myFile(this->getTarget() + "_shrubbery");
			if (myFile)
			{
				myFile <<"      /\\      " << std::endl;
				myFile <<"     /\\*\\     " << std::endl;
				myFile <<"    /\\O\\*\\    " << std::endl;
				myFile <<"   /*/\\/\\/\\   " << std::endl;
				myFile <<"  /\\O\\/\\*\\/\\  " << std::endl;
				myFile <<" /\\*\\/\\*\\/\\/\\ " << std::endl;
				myFile <<"/\\O\\/\\/*/\\/O/\\" << std::endl;
				myFile <<"     ||      " << std::endl;
				myFile <<"     ||      " << std::endl;
				myFile <<"     ||  " << std::endl;
				myFile << std::endl;
				myFile <<"      /\\      " << std::endl;
				myFile <<"     /\\*\\     " << std::endl;
				myFile <<"    /\\O\\*\\    " << std::endl;
				myFile <<"   /*/\\/\\/\\   " << std::endl;
				myFile <<"  /\\O\\/\\*\\/\\  " << std::endl;
				myFile <<" /\\*\\/\\*\\/\\/\\ " << std::endl;
				myFile <<"/\\O\\/\\/*/\\/O/\\" << std::endl;
				myFile <<"     ||      " << std::endl;
				myFile <<"     ||      " << std::endl;
				myFile <<"     ||  " << std::endl;
				myFile.close();
			}
			else
			{
				std::cout << "Couldn't Create shrubbery because  there was a problem when creating or writing to the file." << std::endl;
			}
		}
		catch (std::exception &e)
		{
			std::cout << "Couldn't Create shrubbery because : " << e.what() << std::endl;
		}	
	}
}
