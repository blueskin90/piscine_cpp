#ifndef SQUAD_HPP
# define SQUAD_HPP

#include "ISquad.hpp"
#include "ISpaceMarine.hpp"
#include <cstddef>

class Squad : public ISquad
{
	private:
		ISpaceMarine 	**_units;
		int				_nbr;
	public:
		Squad(void);
		Squad(Squad const &src);
		~Squad(void);
		Squad& operator=(Squad const &rhs);

		int				getCount(void) const;
		ISpaceMarine	*getUnit(int num) const;
		int				push(ISpaceMarine *unit);
};

#endif
