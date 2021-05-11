#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "ICharacter.hpp"
#include "AMateria.hpp"

class Character : public ICharacter
{
	private:
		Character(void);

		AMateria*	_materias[4];
		std::string	_name;
		int			_mnumber;
	public:
		Character& 			operator=(Character const &rhs);
							Character(std::string const &name);
							Character(Character const &src);
							~Character(void);

		std::string const	&getName(void) const;
		int					getMnumber(void) const;
		AMateria*			getMaterias(void) const;

		void				equip(AMateria *m);
		void				unequip(int idx);
		void				use(int idx, ICharacter& target);
};

#endif /* CHARACTER_HPP */
