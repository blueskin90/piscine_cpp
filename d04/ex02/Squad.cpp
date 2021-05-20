#include "Squad.hpp"

#include <iostream>

Squad::Squad(void): _units(NULL), _nbr(0)
{
}

Squad::~Squad(void)
{
	for (int i = 0; i < this->_nbr; i++)
		delete this->_units[i];
	delete this->_units;
}

Squad::Squad(Squad const &src): _units(NULL), _nbr(src.getCount())
{
	this->_units = new ISpaceMarine*[this->_nbr];
	for (int i = 0; i <= this->_nbr; i++)
		this->_units[i] = src.getUnit(i)->clone();
}

Squad&	Squad::operator=(Squad const &rhs)
{

	if (this->_nbr != 0)
	{
		for (int i = 0; i < this->_nbr; i++)
			delete this->_units[i];
		delete this->_units;
	}
	this->_units = new ISpaceMarine*[rhs.getCount()];
	for (int i = 0; i < rhs.getCount(); i++)
		this->_units[i] = rhs.getUnit(i)->clone();
	this->_nbr = rhs.getCount();
	return (*this);
}

int		Squad::getCount(void) const
{
	return (this->_nbr);
}

ISpaceMarine	*Squad::getUnit(int num) const
{
	if (num < 0 || num > this->_nbr)
		return (NULL);
	return (this->_units[num]);
}

int				Squad::push(ISpaceMarine *unit)
{
	ISpaceMarine	**tmp;

	if (unit == NULL)
		return (0);

	for (int i = 0; i < this->_nbr; i++)
	{
		if (this->_units[i] == unit)
		{
			return (0);
		}
	}
	if (this->_nbr == 0)
	{
		this->_units = new ISpaceMarine*[1];
		this->_units[0] = unit;
	}
	else
	{
		tmp = this->_units;
		this->_units = new ISpaceMarine*[this->_nbr + 1];
		for (int i = 0; i < this->_nbr; i++)
			this->_units[i] = tmp[i];
		this->_units[this->_nbr] = unit;
		delete tmp;
	}
	this->_nbr++;
	return (this->_nbr);
}
