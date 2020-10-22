#ifndef ZOMBIE_HORDE_H
# define ZOMBIE_HORDE_H

#include "Zombie.hpp"
#include <cstdlib>
#include <string>
#include <iostream>

class ZombieHorde {
	private:
		int		_size;
		Zombie*	_zombies;
	public:
		ZombieHorde(int N);
		~ZombieHorde(void);
		void	announce(void) const;
};

#endif


