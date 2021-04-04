#ifndef TACTICALMARINE_HPP
# define TACTICALMARINE_HPP

#include <iostream>
#include "ISpaceMarine.hpp"

class TacticalMarine : public ISpaceMarine
{
	private:
	public:
		TacticalMarine&	operator=(TacticalMarine const &rhs);
							TacticalMarine(TacticalMarine const &src);
							TacticalMarine(void);
							~TacticalMarine(void);	
		TacticalMarine	*clone(void) const;
		void				battleCry(void) const;
		void				rangedAttack(void) const;
		void				meleeAttack(void) const;
};



#endif
