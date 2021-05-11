#include "MateriaSource.hpp"

MateriaSource::MateriaSource(void)
{
	for (int i = 0; i < 4; i++)
		this->_materias[i] = NULL;
}

MateriaSource::MateriaSource(MateriaSource const &src)
{
	for (int i = 0; i < 4; i++)
	{
		this->_materias[i] = src.getMaterias(i);
	}
}

MateriaSource::~MateriaSource(void)
{
}

MateriaSource&	MateriaSource::operator=(MateriaSource const &rhs)
{
	for (int i = 0; i < 4; i++)
		this->_materias[i] = rhs.getMaterias(i);
	return (*this);
}

AMateria	*MateriaSource::getMaterias(int idx) const
{
	return (this->_materias[idx]);
}

void		MateriaSource::learnMateria(AMateria* materia)
{
	int		i;
	for (i = 0; i < 4 && this->getMaterias(i) != NULL; i++)
	{
	}
	if (i != 4)
		this->_materias[i] = materia;
}

AMateria	*MateriaSource::createMateria(std::string const &type)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_materias[i]->getType() == type)
			return (this->_materias[i]->clone());
	}
	return (NULL);
}
