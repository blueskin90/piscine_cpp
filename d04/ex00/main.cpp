#include "Sorcerer.hpp"
#include "Victim.hpp"
#include "Peon.hpp"
#include "Villager.hpp"

int		main(void)
{
	Sorcerer robert("Robert", "the Magnificent");
	Victim jim("Jimmy");
	Peon joe("Joe");
	Villager noob("noob");
	Villager test(noob);

	std::cout << robert << jim << joe;
	robert.polymorph(jim);
	robert.polymorph(joe);

	std::cout << noob << test;
	robert.polymorph(noob);
	robert.polymorph(test);
	return 0;
}
