#include "Enemy.hpp"

Enemy::Enemy(void)
{
}

Enemy::Enemy(unsigned int hp, std::string const &type): _hp(hp), _type(type)
{
}

Enemy::Enemy(Enemy const &src): _hp(src.getHP()), _type(src.getType())
{
}

Enemy::~Enemy(void)
{
}

std::string	Enemy::getType(void) const
{
	return (this->_type);
}

int	Enemy::getHP(void) const
{
	return (this->_hp);
}

void	Enemy::takeDamage(int damage)
{
	if (damage < 0)
		return;
	if (this->_hp <= damage)
		this->_hp = 0;
	else
		this->_hp -= damage;
}

Enemy& Enemy::operator=(Enemy const &rhs)
{
	this->_type = rhs.getType();
	this->_hp = rhs.getHP();
	return (*this);
}
