#ifndef ASSAULTTERMINATOR_HPP
# define ASSAULTTERMINATOR_HPP

#include "ISpaceMarine.hpp"
#include <iostream>

class AssaultTerminator : public ISpaceMarine
{
	private:
		AssaultTerminator&	operator=(AssaultTerminator const &rhs);
		AssaultTerminator(AssaultTerminator const &src);
	public:
							AssaultTerminator(void);
							~AssaultTerminator(void);	
		AssaultTerminator	*clone(void) const;
		void				battleCry(void) const;
		void				rangedAttack(void) const;
		void				meleeAttack(void) const;
};

#endif
