#include <iostream> 
#include <sstream>
#include <fstream>
#include <vector>
#include "AInstruction.hpp"
#include "instructions.hpp"

int		parsing(char *filePath, std::vector<AInstruction*> *list)
{
	std::fstream file;
	std::string	str;
	std::stringstream strStream;

	file.open(filePath, std::ios::in);
	if (!file)
	{
		std::cout << "Couldn't open the file" << std::endl;
		return (0);
	}
	strStream << file.rdbuf();
	str = strStream.str();
	for (std::string::size_type i = 0; i < str.size(); i++)
	{
		if (str[i] == 'f')
			list->push_back(new IncPtr());
		else if (str[i] == 'u')
			list->push_back(new DecPtr());
		else if (str[i] == 'c')
			list->push_back(new IncPtrValue());
		else if (str[i] == 'k')
			list->push_back(new DecPtrValue());
		else if (str[i] == 't')
			list->push_back(new Print());
		else if (str[i] == 'h')
			list->push_back(new Read());
		else if (str[i] == 'i')
			list->push_back(new StartLoop());
		else if (str[i] == 's')
			list->push_back(new EndLoop());
	}
	file.close();
	return (1);
}

void	execute(std::vector<AInstruction*> *list)
{
	std::vector<AInstruction*>::iterator it;
	char	mem[255];
	size_t	memptr;


	memptr = 0;
	it = list->begin();
	bzero(mem, 255 * sizeof(char));
	while (it != list->end())
	{
		(*it)->execute(mem, &memptr, &it);
	}
}

int		main(int ac, char **av)
{
	std::vector<AInstruction*> instructionList;

	if (ac != 2)
	{
		std::cout << "Usage: ./mindopen FILE" << std::endl;
		return (1);
	}
	if (!parsing(av[1], &instructionList))
		return (0);
	execute(&instructionList);
	return (1);
}
