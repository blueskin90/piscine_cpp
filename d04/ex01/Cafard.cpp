#include "Cafard.hpp"

Cafard::Cafard(void): Enemy(1, "Cafard")
{
	std::cout << "* screeeee *" << std::endl;
}

Cafard::~Cafard(void)
{
	std::cout << "* sprotch *" << std::endl;
}
