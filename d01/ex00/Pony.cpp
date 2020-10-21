#include "Pony.hpp"
#include <iostream>

int Pony::destructor_called = 0;
int Pony::constructor_called = 0;

Pony::Pony(void)
{
	constructor_called++;
	this->legs = 4;
}

Pony::~Pony(void)
{
	destructor_called++;
}

void	Pony::show_alloc(void)
{
	std::cout << "Constructor called " << constructor_called << " times and destructor called " << destructor_called << " times" << std::endl;
}
