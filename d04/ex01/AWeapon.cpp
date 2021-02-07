#include "AWeapon.hpp"
#include <iostream>
AWeapon::AWeapon(std::string const &name, int apcost, int damage) : _name(name), _APcost(apcost), _damage(damage)
{
}

AWeapon::AWeapon(AWeapon const &src) : _name(src.getName()), _APCost(src.getAPCost()), _damage(src.getDamage())
{
}

AWeapon::~AWeapon(void)
{
}

std::string	const AWeapon::getName(void) const
{
	return (this->_name);
}

int	const AWeapon::getAPCost(void) const
{
	return (this->_APCost);
}

int	const AWeapon::getDamage(void) const
{
	return (this->_damage);
}


AWeapon& AWeapon::operator=(AWeapon const &rhs)
{
	this._APcost = rhs.getAPCost();
	this._damage = rhs.getDamage();
	this._name = rhs.getName();
	return (*this);
}

AWeapon::AWeapon(void)
{
}
