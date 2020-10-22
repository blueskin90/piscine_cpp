#ifndef ZOMBIE_EVENT_HPP
# define ZOMBIE_EVENT_HPP

#include <string>
#include "Zombie.hpp"
#include <cstdlib>

class ZombieEvent {
	private:
		std::string _type;
	public:
		ZombieEvent(void);
		~ZombieEvent(void);
		void	setZombieType(std::string const &type);
		Zombie* newZombie(std::string const &name) const;
		Zombie*	randomChump(void) const;
};

#endif
