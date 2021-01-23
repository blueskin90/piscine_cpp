#include "FragTrap.hpp"

FragTrap::FragTrap(void) : ClapTrap("unnamed", 100, 50, 1, 30, 20, 5)
{
	std::srand(time(NULL));
	std::cout << "unflavored FR4G-TP was born, now with 0% naming !" << std::endl ;
}

FragTrap::FragTrap(FragTrap const &src) : ClapTrap(src)
{
	std::srand(time(NULL));
	std::cout << "FR4G-TP " << src.getName() << " was cloned ! Prepare for trouble, and make it double !" << std::endl ;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name, 100, 50, 1, 30, 20, 5)
{
	std::srand(time(NULL));
	std::cout << "FR4G-TP " << name << " was born, fear him mere mortals, for he does not fear death !" << std::endl;
}

FragTrap::~FragTrap(void)
{
	std::cout << "FR4G-TP " << this->_name << " met a staircase" << std::endl;
}

FragTrap &FragTrap::operator=(FragTrap const &rhs) {
	this->_name					= rhs.getName();
	this->_hp					= rhs.getHp();
	this->_ep					= rhs.getEp();
	this->_level				= rhs.getLevel();
	this->_meleeDamage			= rhs.getMeleeDamage();
	this->_rangedDamage			= rhs.getRangedDamage();
	this->_armorReduc			= rhs.getArmorReduc();
	return (*this);
}

void			FragTrap::vaulthunter_dot_exe(std::string const & target)
{
	std::string attacks[5] = { " Throws a Nokia 3310 at " + target, " Fart on "+ target, " Stab " + target + " with a pencil, John Wick style,", " empty its oil in " + target + " eyes", " dance like crazy in front of " + target};
	unsigned int damages[5] = { 100000, 1, 35, 15, 0};
	unsigned int rand;
   
	rand = std::rand() % 5;
	if (this->_ep < 25)
	{
		std::cout << "You don't have enough energy to operate an attack." << std::endl;
		return ;
	}
	this->_ep -= 25;
	std::cout << this->_name << ": \"Behold my MIGHTIEST ATTACK !\" ";
	std::cout << this->_name << attacks[rand] << " causing " << damages[rand] << " damages";
	if (rand == 4)
		std::cout << ", but looking so darn hot";
	std::cout << "." << std::endl;
}
