#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <iostream>
#include "ICharacter.hpp"

class ICharacter;

class AMateria
{
	private:
		AMateria(void);
	protected:
		std::string const	_type; 
		unsigned int 		_xp;
	public:
		AMateria(std::string const & type);
		AMateria(AMateria const &src);
		virtual ~AMateria(void);
		AMateria &operator=(AMateria const &rhs);

		std::string const 	&getType(void) const; //Returns the materia type
		unsigned int 		getXP(void) const; //Returns the Materia's XP
		virtual AMateria* 	clone(void) const = 0;
		virtual void 		use(ICharacter& target);
};
#endif /* AMATERIA_HPP */
