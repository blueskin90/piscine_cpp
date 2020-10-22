#include "HumanA.hpp"

HumanA::HumanA(std::string const &name, Weapon const &weapon) : _weapon(weapon) ,_name(name)
{
}

HumanA::~HumanA(void)
{
}

void	HumanA::attack(void) const
{
	std::cout << this->_name << "attacks with his " << this->_weapon.getType() << std::endl;	
}
