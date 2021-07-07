#include "instructions.hpp"

void	IncPtr::execute(char *buffer, size_t *ptr, std::vector<AInstruction*>::iterator *it)
{
	(void)buffer;
	(*ptr)++;
	(*it)++;
}


void	DecPtr::execute(char *buffer, size_t *ptr, std::vector<AInstruction*>::iterator *it)
{
	(void)buffer;
	(*ptr)--;
	(*it)++;
}


void	IncPtrValue::execute(char *buffer, size_t *ptr, std::vector<AInstruction*>::iterator *it)
{
	buffer[*ptr]++;
	(*it)++;
}


void	DecPtrValue::execute(char *buffer, size_t *ptr, std::vector<AInstruction*>::iterator *it)
{
	buffer[*ptr]--;
	(*it)++;
}

void	Print::execute(char *buffer, size_t *ptr, std::vector<AInstruction*>::iterator *it)
{
	std::cout << buffer[*ptr];
	(*it)++;
}

void	Read::execute(char *buffer, size_t *ptr, std::vector<AInstruction*>::iterator *it)
{
	std::cin.get(buffer + *ptr, 1);
	(*it)++;
}

void		findClosing(std::vector<AInstruction*>::iterator *it)
{
	int	counter;
	StartLoop	*test0;
	EndLoop		*test1;

	counter = 0;
	do
	{
		test0 = dynamic_cast<StartLoop*>(**it);
		test1 = dynamic_cast<EndLoop*>(**it);
		if (test0 != NULL)
			counter++;
		else if (test1 != NULL)
			counter--;
		(*it)++;
		if (counter == 0)
			(*it)++;
	} while (counter != 0);

}

void	findOpening(std::vector<AInstruction*>::iterator *it)
{
	int	counter;
	StartLoop	*test0;
	EndLoop		*test1;

	counter = 0;
	do
	{
		test0 = dynamic_cast<StartLoop*>(**it);
		test1 = dynamic_cast<EndLoop*>(**it);
		if (test0 != NULL)
			counter++;
		else if (test1 != NULL)
			counter--;
		if (counter == 0)
		{
			(*it)++;
			break;
		}
		(*it)--;
	} while (counter != 0);

}

void	StartLoop::execute(char *buffer, size_t *ptr, std::vector<AInstruction*>::iterator *it)
{
	if (buffer[*ptr] == 0)
		findClosing(it);
	else
		(*it)++;
}

void	EndLoop::execute(char *buffer, size_t *ptr, std::vector<AInstruction*>::iterator *it)
{
	if (buffer[*ptr] != 0)
		findOpening(it);
	else
		(*it)++;
}
