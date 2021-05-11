#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"
#include "AMateria.hpp"

class MateriaSource: public IMateriaSource
{
	private:
		AMateria*	_materias[4];
	public:
		MateriaSource(void);
		MateriaSource(MateriaSource const &src);
		~MateriaSource(void);
		MateriaSource&	operator=(MateriaSource const &rhs);

		AMateria	*getMaterias(int idx) const;
		void		learnMateria(AMateria* m);
		AMateria*	createMateria(std::string const &type);
};

#endif /* MATERIASOURCE_HPP */
