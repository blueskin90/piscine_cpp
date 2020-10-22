#include "Zombie.hpp"
#include "ZombieEvent.hpp"

int		main(void)
{
	Zombie	zonzon("ZombieDeLaStack", "StackZombie");
	Zombie	*zomb;
	ZombieEvent	zevent;

	zonzon.announce();
	zevent.setZombieType("HeapZombie");
	zomb = zevent.randomChump();
	zomb->announce();
	delete zomb;
	zomb = zevent.newZombie("Jean-Eude");
	zomb->announce();
	delete zomb;
	return (1);
}
