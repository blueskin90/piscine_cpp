#include "Character.hpp"

Character::Character(void) : _name("Unnamed"), _APmax(40), _AP(40), _weapon(NULL)
{
}

Character::Character(std::string const &name) : _name(name), _APmax(40), _AP(40), _weapon(NULL)
{
}

Character::Character(Character const &src) : _name(src.getName()), _APmax(40), _AP(src.getAP()), _weapon(NULL)
{
}

Character::~Character(void)
{
}

Character& Character::operator=(Character const &rhs)
{
	this->_AP = rhs.getAP();
	return (*this);
}

void		Character::equip(AWeapon *weapon)
{
	this->_weapon = weapon;
}

void		Character::attack(Enemy *enemy)
{
	if (this->_weapon == NULL)
		return ;
	if (this->getAP() < this->_weapon->getAPCost())
	{
		std::cout << this->_name << " can't shoot because it doesn't have enough AP !" << std::endl;
	}
	else
	{
		this->_AP -= this->_weapon->getAPCost();
		std::cout << this->_name << " hasttaque " << enemy->getType() << " with a " << this->_weapon->getName() << std::endl;
		this->_weapon->attack();
		enemy->takeDamage(this->_weapon->getDamage());
		if (enemy->getHP() <= 0)
			delete enemy;
	}
}

void		Character::recoverAP(void)
{
	this->_AP += 10;
	if (this->_AP > this->_APmax)
		this->_AP = this->_APmax;
}

std::string Character::getName(void) const
{
	return (this->_name);
}

int			Character::getAP(void) const
{
	return (this->_AP);
}

AWeapon		*Character::getWeapon(void)const
{
	return (this->_weapon);
}

std::ostream& operator<< (std::ostream &output, Character const &character)
{
	output << character.getName() << " has " << character.getAP() << " AP";
	if (character.getWeapon() == NULL)
		output << " and is unarmed";
	else
		output << " and carries a " << character.getWeapon()->getName();
	output << std::endl;
	return (output);
}
