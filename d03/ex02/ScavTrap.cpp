#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void) : ClapTrap("unnamed", 100, 100, 1, 20, 15, 3)
{
	std::srand(time(NULL));
	std::cout << "Vanilla SC4V-TP was born, behold it's mightiest scavenging abilities !" << std::endl ;
}

ScavTrap::ScavTrap(ScavTrap const &src) : ClapTrap(src)
{
	std::srand(time(NULL));
	std::cout << "SC4V-TP " << src.getName() << " was cloned ! Twice the scavenging !" << std::endl ;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name, 100, 100, 1, 20, 15, 3)
{
	std::srand(time(NULL));
	std::cout << "SC4V-TP " << name << " is in the place, please hold your your hornyness." << std::endl;
}

ScavTrap::~ScavTrap(void)
{
	std::cout << "SC4V-TP " << this->_name << " runned out of garbage to scavenge" << std::endl;
}

ScavTrap &ScavTrap::operator=(ScavTrap const &rhs) {
	this->_name					= rhs.getName();
	this->_hp					= rhs.getHp();
	this->_ep					= rhs.getEp();
	this->_level				= rhs.getLevel();
	this->_meleeDamage			= rhs.getMeleeDamage();
	this->_rangedDamage			= rhs.getRangedDamage();
	this->_armorReduc			= rhs.getArmorReduc();
	return (*this);
}

void			ScavTrap::challengeNewcomer(std::string const & target)
{
	std::string attacks[6] = {" to a dancing contest !", " to say the alphabet in reverse", " to lick his / her elbow", " to finish a pint of Maximator", " to program a printf without any mallocs !", " to work at Safran without wanting to kill himself."
	};
   
	std::cout << this->_name << " challenges " << target << attacks[std::rand() % 6] << std::endl;
}
