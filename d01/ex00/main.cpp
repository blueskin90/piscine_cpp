#include "Pony.hpp"

#include <iomanip>
#include <iostream>
#include <locale>
#include <string>

void		ponyOnTheStack(void)
{
	Pony	pon;

	pon.legs = 3;
	std::cout << pon.legs << std::endl;
}

void		ponyOnTheHeap(void)
{
	Pony	*pon;

	pon = new Pony();
	pon->legs = 2;
	std::cout << pon->legs << std::endl;
}

int			main(void)
{
	ponyOnTheStack();
	ponyOnTheHeap();
	return (1);
}
