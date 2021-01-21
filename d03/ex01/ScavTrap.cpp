#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void) : _hp(ScavTrap::maxhp), _ep(ScavTrap::maxep), _level(1), _name("Unnamed"), _meleeDamage(20), _rangedDamage(15), _armorReduc(3)
{
	std::srand(time(NULL));
	std::cout << "Vanilla SC4V-TP was born, behold it's mightiest scavenging abilities !" << std::endl ;
}

ScavTrap::ScavTrap(ScavTrap const &src) : _hp(src.getHp()), _ep(src.getEp()), _level(src.getLevel()), _name(src.getName()), _meleeDamage(src.getMeleeDamage()), _rangedDamage(getRangedDamage()), _armorReduc(src.getArmorReduc())
{
	std::srand(time(NULL));
	std::cout << "SC4V-TP " << src.getName() << " was cloned ! Twice the scavenging !" << std::endl ;
}

ScavTrap::ScavTrap(std::string name) : _hp(ScavTrap::maxhp), _ep(ScavTrap::maxep), _level(1), _name(name), _meleeDamage(20), _rangedDamage(15), _armorReduc(3)
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

void			ScavTrap::rangedAttack(std::string const &target) const
{
	std::cout << "SC4V-TP " << this->_name << " throws garbage at " << target << " , dealing " << this->_rangedDamage << " damages, yuck. " << std::endl;
}

void			ScavTrap::meleeAttack(std::string const &target) const
{
	std::cout << "SC4V-TP " << this->_name << " attacks " << target << " up with a frying pan, dealing " << this->_meleeDamage << " bonk damages." << std::endl;
}

void			ScavTrap::takeDamage(unsigned int amount)
{
	if (amount < this->_armorReduc)
	{
		std::cout << this->_name << " : really, that's all you got ?" << std::endl ;  
		return ;
	}
	std::cout << "SC4V-TP " << this->_name << " was at " << this->_hp << " and took " << amount << " damages (minus armor : " << this->_armorReduc << ") which causes him to be at : ";  
	if (this->_hp < (amount - this->_armorReduc))
		this->_hp = 0;
	else
		this->_hp -= (amount - this->_armorReduc);
	std::cout << this->_hp << " HPs, 'tis nothing but a scratch !" << std::endl;
}

void			ScavTrap::beRepaired(unsigned int amount)
{
	std::cout << "SC4V-TP " << this->_name << " was at " << this->_hp << " and repaired " << amount << " damages ! which causes him to be at : ";  
	if (amount > ScavTrap::maxhp || (this->_hp + amount) > ScavTrap::maxhp)
		this->_hp = 100;
	else
		this->_hp += amount;
	std::cout << this->_hp << " he is more powerful than ever, fly you fools !" << std::endl;
}

void			ScavTrap::challengeNewcomer(std::string const & target)
{
	std::string attacks[6] = {" to a dancing contest !", " to say the alphabet in reverse", " to lick his / her elbow", " to finish a pint of Maximator", " to program a printf without any mallocs !", " to work at Safran without wanting to kill himself."
	};
   
	std::cout << this->_name << " challenges " << target << attacks[std::rand() % 6] << std::endl;
}

unsigned int	ScavTrap::getHp(void) const
{
	return (this->_hp);
}

unsigned int	ScavTrap::getEp(void) const
{
	return (this->_ep);
}

unsigned int	ScavTrap::getLevel(void) const
{
	return (this->_level);
}

std::string	const	&ScavTrap::getName(void) const
{
	return (this->_name);
}

unsigned int	ScavTrap::getMeleeDamage(void) const
{
	return (this->_meleeDamage);
}

unsigned int	ScavTrap::getRangedDamage(void) const
{
	return (this->_rangedDamage);
}

unsigned int	ScavTrap::getArmorReduc(void) const
{
	return (this->_armorReduc);
}
