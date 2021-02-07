#include "PowerFist.hpp"

PowerFist::PowerFist(void) : AWeapon::AWeapon("Power Fist", 8, 50)
{
}

PowerFist::~PowerFist(void)
{
}

void	PowerFist::attack(void) const
{
	std::cout << "* pschhh... SBAM ! *" << std::endl;
}
