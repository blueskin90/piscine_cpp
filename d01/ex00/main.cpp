#include "Pony.hpp"

#include <iostream>

void		ponyOnTheStack(void)
{
	Pony	pon;

	pon.legs = 3;
	std::cout << "Pony legs number is (should be 3) : " << pon.legs << std::endl;
}

void		ponyOnTheHeap(void)
{
	Pony	*pon;

	pon = new Pony();
	pon->legs = 2;
	std::cout << "Pony legs number is (should be 2) : " << pon->legs << std::endl;
	delete pon;
}

int			main(void)
{
	ponyOnTheStack();
	ponyOnTheHeap();
	Pony::show_alloc();
	return (1);
}
