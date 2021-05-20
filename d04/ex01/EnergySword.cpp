#include "EnergySword.hpp"

EnergySword::EnergySword(void) : AWeapon::AWeapon("Energy sword", 2, 10)
{
}

EnergySword::~EnergySword(void)
{
}

void	EnergySword::attack(void) const
{
	std::cout << "* swoosh *" << std::endl;
}
