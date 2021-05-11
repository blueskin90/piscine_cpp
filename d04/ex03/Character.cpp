#include "Character.hpp"

Character::Character(void) : _name("unnamed"), _mnumber(0)
{
}

Character::Character(std::string const &name): _name(name), _mnumber(0)
{
}

Character::Character(Character const &src): _name(src.getName()), _mnumber(src.getMnumber()) 
{
	if (this->_mnumber >= 1)
	{
		for(int i = 0; i < this->_mnumber; i++)
			this->_materias[i] = src.getMaterias()[i].clone();
	}	
}

Character::~Character(void)
{
	for (int i = 0; i < this->_mnumber; i++)
		delete this->_materias[i];
}

std::string const	&Character::getName(void) const
{
	return (this->_name);
}

int					Character::getMnumber(void) const
{
	return (this->_mnumber);
}

AMateria			*Character::getMaterias(void) const
{
	return (*(this->_materias));
}

void				Character::equip(AMateria *m)
{
	if (_mnumber < 4)
	{
		this->_materias[this->_mnumber] = m;
		this->_mnumber += 1;
	}
}

void				Character::unequip(int idx)
{
	if (idx >= 0 && this->_mnumber > idx)
	{
		if (this->_mnumber == idx + 1)
		{
			this->_materias[idx] = NULL;
		}
		else
		{
			this->_materias[idx] = NULL;
			for (int i = idx; i < this->_mnumber && i < 3; i++)
				this->_materias[i] = this->_materias[i + 1];
		}
		this->_mnumber -= 1;
	}
}

void				Character::use(int idx, ICharacter &target)
{
	if (idx < 0 || idx >= this->_mnumber)
		return ;
	this->_materias[idx]->use(target);
}

Character&	Character::operator=(Character const &rhs)
{
	(void)rhs;
	return (*this);
}


